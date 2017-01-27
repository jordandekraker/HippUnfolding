function out = Laplace_unfold(fn)

% performs laplacian unfolding on the image of manually labelled structures 
% (.nii.gz). Output directory is a subdirectory in the same folder as input
% file, in subdirectory <input_nii_prefix>_unfolded


% Expected manually labelled structures are: 
% hippocampal grey matter (==1), 
% dark band (==2), 
% HATA (==22), 
% indusium griseum (==23),
% medial temporal lobe cortex border (==20), 
% and dark band along medial side of the vertical component of the uncus (==21). 
% cyst label (==4) is optional, and all else should be ==0. 

% output files include a binned visualizations (.nii.gz) of the unfolding in each
% dimension. Check for major distortions caused by errors in manual
% segmentation! Also outputs a .mat file containing all the variables of
% interest and the actual Laplace gradients. 


% load manual segmentation
orig_labelmap = load_untouch_nii(fn);
fn_noFT = fn(1:end-7);
mkdir(sprintf('%s_Unfolded',fn_noFT));


% crop around hippocampus by finding min and max in each direction that
% contain non-zero label, and add one more voxel on each side just in case
[x,y,z] = ind2sub(size(orig_labelmap.img),find(orig_labelmap.img>0));
cropping = false(size(orig_labelmap.img)); %initialize
cropping(min(x)-1:max(x)+1,min(y)-1:max(y)+1,min(z)-1:max(z)+1) = true;
labelmap = zeros(max(x)-min(x)+3,max(y)-min(y)+3,max(z)-min(z)+3); %+3 because 2 come from expanding min and max domain by 1;
labelmap(:) = orig_labelmap.img(cropping==1);

% if left hippocampus, flip
isleft = mean(z) > size(orig_labelmap.img,3)/2;
if isleft
    labelmap = flipdim(labelmap,3); %flip on z (i.e. sagittally)
end

%% AP axis unfolding

% Initialize with FastMarching (geodist) to save iterations of subsequent Laplace
Geodist_AP = nan(size(labelmap)); %initialize

%Define ROIs for fast march
source = (labelmap==22); %HATA
fg = (labelmap==1); %Greymatter
vel = zeros(size(labelmap)); %no passing outside
vel(fg) = 0.5; %medium resistance - optimal path
vel(source) = 1; %pass easily within source
[r,c,v] = ind2sub(size(labelmap),find(source)); %index of start points

%Fast-march
Geodist_AP = perform_fast_marching(vel,[r c v]');
Geodist_AP(~fg) = nan;
Geodist_AP(Geodist_AP>10000) = nan; %10000 step max
Geodist_AP = Geodist_AP/(max(Geodist_AP(:))); %rescale 0 to 1


% Run Laplace unfolding
sink = (labelmap==23); %indusium griseum
fg = (Geodist_AP >= 0); %Greymatter. defining this way ignored isolated GM label missed in the fast-march

if exist('laplace_iters_mex') > 0 % if mex file exists, use that (its faster!)
    [Laplace_AP,change_per_iter_AP] = laplace_iters_mex(fg,source,sink,Geodist_AP);
else 
    disp('no MEX file available. Running MATLAB code instead (slower)');
    [Laplace_AP,change_per_iter_AP] = laplace_iters(fg,source,sink,Geodist_AP);
end
%figure; plot(change_per_iter_AP(5:end)); title('Change per iteration A-P');
Laplace_AP=round((Laplace_AP*99)+1); %rescale 1-100 and round


%Segment into bins of 5 and save - primarily for visualization purposes
Laplace_AP_bin4 = 4*ceil(Laplace_AP/4);

save_var = orig_labelmap;
if ~isleft
    save_var.img(cropping) = Laplace_AP_bin4/4;
elseif isleft
    save_var.img(cropping) = flipdim(Laplace_AP_bin4/4,3);
end
save_fn = sprintf('%s_Unfolded/APgrad_binned.nii.gz',fn_noFT);
save_untouch_nii(save_var,save_fn);


%% compute thicknesses
voxel_size = orig_labelmap.hdr.dime.pixdim(2);
[Laplace_thick,Thickness_streamlengths,SRLMcoveredSub_labelmap] = compute_thickness(labelmap,voxel_size);
%segment into bins of 4
Laplace_thick = ceil(Laplace_thick*4); %rescale 0-4 and round up

if ~isleft
    save_var.img(cropping) = Laplace_thick;
elseif isleft
    save_var.img(cropping) = flipdim(Laplace_thick,3);
end
save_fn = sprintf('%s_Unfolded/thickness_binned.nii.gz',fn_noFT);
save_untouch_nii(save_var,save_fn);


%% PD gradient this needs a bit of set up first. The current section does fast marching from EC within each bin of AP gradient.
% this does two things: initializes the laplacian to save iterations, and
% is used to define the sink 

Geodist_PD = nan(size(labelmap));
Geodist_temp = nan(size(labelmap));
source = (labelmap==20); %EC

%run separately on each AP bin
for AP = 4:4:100
    fg = (Laplace_AP_bin4 == AP); %use grey matter of this bin
    vel = zeros(size(labelmap)); %initialize / clear previous
    vel(fg) = 0.5;
    vel(source) = 1;
    [r,c,v] = ind2sub(size(labelmap),find(source == 1)); %ind of start
    
    Geodist_temp = perform_fast_marching(vel,[r c v]');
    Geodist_temp(~fg) = nan;
    Geodist_temp(Geodist_temp>10000) = nan; %10000 step max
    Geodist_temp = Geodist_temp/max(Geodist_temp(:)); %rescale 0 to 1
    Geodist_PD(fg) = Geodist_temp(fg); %save results for this bin
end

%% define DG sink for subsequent P-D Laplacian

%dilate dark band (or cyst) over distal parts of geodist_PD for main body of HPC
se = ones(3,3,3);
sink_main = (imdilate((labelmap==2 | labelmap == 4),se) & Geodist_PD>0.87);
%roughly corresponds to DG granular cell layer (i.e. the part of DG that borders SRLM)

sf = zeros(3,3,3); sf(2,:,:) = 1; sf(:,2,:) = 1; sf (:,:,2) = 1;

sink_unc = false(size(labelmap));
hold = false(size(labelmap));
hold(imdilate(labelmap==1,sf) & imdilate(labelmap==21,sf) & SRLMcoveredSub_labelmap==0) = 1; 
sink_unc(imdilate(hold==1,se) & labelmap==1) = 1; %where that overlaps greymatter
sink_unc(hold==1) = false;

%% PD Laplacian - now we can finally compute this
% Define ROIs for Laplacian
source=(labelmap==20); %EC
sink=(sink_main | sink_unc); %DG
fg=(Geodist_PD>=0); %Greymatter

if exist('laplace_iters_mex') > 0 % if mex file exists, use that (its faster!)
    [Laplace_PD,change_per_iter_PD] = laplace_iters_mex(fg,source,sink,Geodist_PD);
else
    disp('no MEX file available. Running MATLAB code instead (slower)');
    [Laplace_PD,change_per_iter_PD] = laplace_iters(fg,source,sink,Geodist_PD);
end
%figure; plot(change_per_iter_PD(5:end)); title('Change per iteration P-D');

Laplace_PD = round((Laplace_PD*98)+1); %rescale 1-99 and round
Laplace_PD(sink) = 100; %the very most distal part of DG. ~grandule cell layer

%Segment into bins of 10, then save
Laplace_PD_10 = 10*ceil(Laplace_PD/10);
Laplace_PD_10(sink) = 110;
if ~isleft
    save_var.img(cropping) = Laplace_PD_10/10;
elseif isleft
    save_var.img(cropping) = flipdim(Laplace_PD_10/10,3);
end
save_fn = sprintf('%s_Unfolded/PDgrad_binned.nii.gz',fn_noFT);
save_untouch_nii(save_var,save_fn);


%% clean up and save all variables
clearvars -except change_per_iter_AP change_per_iter_PD cropping fn fn_noFT Laplace_AP Laplace_PD Laplace_thick out Thickness_streamlengths isleft orig_labelmap labelmap
save(sprintf('%s_Unfolded/data',fn_noFT))
end
