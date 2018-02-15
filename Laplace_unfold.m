function out = Laplace_unfold(fn)

% performs laplacian unfolding on the image of manually labelled structures
% (.nii.gz). Output directory is a subdirectory in the same place
% as the input file.

% Expected manually labelled structures are:
% hippocampal grey matter (==1),
% dark band (==2),
% HATA (==22),
% indusium griseum (==23),
% medial temporal lobe cortex border (==20),
% dark band along medial side of the vertical component of the uncus (==21).
% cyst label (==4) is optional, and all else should be ==0.

% output files include a binned visualizations (.nii.gz) of the unfolding in each
% dimension. Check for major distortions caused by errors in manual
% segmentation! Also outputs a .mat file containing all the variables of
% interest and the actual Laplace gradients.

tic;

% load manual segmentation
orig_labelmap = load_untouch_nii(fn);
fn_noFT = fn(1:strfind(fn,'.nii')-1);
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
sz = size(labelmap);
%% AP gradient:

maxiters = 5000;
%Define ROIs
source = find(labelmap==22); %HATA
fg = find(labelmap==1); %Greymatter
sink = find(labelmap==23); %indusium griseum

[Laplace_AP,change_per_iter_AP] = laplace_solver(fg,source,sink,maxiters,[],sz);

%% Laminar gradient
% compute thicknesses
voxel_size = orig_labelmap.hdr.dime.pixdim(2);
[Laplace_IO,Thickness_streamlengths,labelmap_SRLMextended] = compute_thickness(labelmap,voxel_size);

%% automatically define PD gradient sink (i.e. approximates DGgcl)

% This portion of the code was used in the original publication, but future
% work will define the DGgcl separately

% The current section does fast marching from EC within each bin of AP gradient.
% this is used to define the sink (approximately the DG granule cell layer, or
% most distal ~12% of the fast march)
Laplace_AP_bin=zeros(sz);
Laplace_AP_bin(fg) = Laplace_AP;
Laplace_AP_bin = ceil(Laplace_AP_bin*25); % 25 discreet bins seems to work well

Geodist_PD = nan(size(labelmap));
Geodist_temp = nan(size(labelmap));
source = (labelmap==20); %EC

%run separately on each AP bin
for AP = 1:25
    fg = (Laplace_AP_bin == AP); %use grey matter of this bin
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

% dilate dark band (or cyst) over distal parts of geodist_PD to get only
% approximate granule cell layer
se = ones(3,3,3);
sink_main = (imdilate((labelmap==2 | labelmap == 4),se) & Geodist_PD>=0.88); %last ~12% of geodist is DG


% now find where DG passes through the vertical component of the uncus.
% This will be the part of hippocampus where our heuristic 'SRLM on
% vertical component' label ends (i.e. where it borders clear label)
sf = zeros(3,3,3); sf(2,:,:) = 1; sf(:,2,:) = 1; sf (:,:,2) = 1;

sink_unc = false(size(labelmap));
hold = false(size(labelmap));
hold(imdilate(labelmap==1,sf) & imdilate(labelmap==21,sf) & labelmap_SRLMextended==0) = 1;
sink_unc(imdilate(hold==1,se) & labelmap==1) = 1; %where that overlaps greymatter
sink_unc(hold==1) = false;

%% PD gradient
% Define ROIs for Laplacian
source=find(labelmap==20); %EC
sink=find(sink_main | sink_unc); %DG
fg = find(labelmap==1); %Greymatter

[Laplace_PD,change_per_iter_PD] = laplace_solver(fg,source,sink,maxiters,Geodist_PD(fg),sz);
tmp = zeros(sz); tmp(fg) = Laplace_PD; 
tmp(sink) = 1; % in this case we want to include the sink as part of the domain
Laplace_PD = tmp(fg);

%% orthogonalize Laplace_AP

Laplace_AP = laplace_orthogonalize(Laplace_AP, Laplace_PD, [], sz, fg);

%% clean up and save all variables

bad = find(isnan(Laplace_AP) | isnan(Laplace_PD) | isnan(Laplace_IO) | isnan(fg));
sprintf('removing %d bad voxels',length(bad)) % this sometimes happens due 'islands' in the manual segmentation
Laplace_AP(bad) = []; Laplace_PD(bad) = []; Laplace_IO(bad) = []; fg(bad) = [];
idxgm = fg;

clearvars -except cropping fn fn_noFT Laplace_AP Laplace_PD Laplace_IO Thickness_streamlengths labelmap_SRLMextended isleft orig_labelmap labelmap idxgm sz;

save(sprintf('%s_Unfolded/data',fn_noFT));

out = zeros(sz); out(idxgm) = ceil(Laplace_AP*20);
if isleft
    out = flipdim(out,3); %flip on z (i.e. sagittally)
end
orig_labelmap.img(cropping==1) = out;
save_untouch_nii(orig_labelmap,sprintf('%s_Unfolded/laplace_AP.nii.gz',fn_noFT));

out = zeros(sz); out(idxgm) = ceil(Laplace_PD*20);
if isleft
    out = flipdim(out,3); %flip on z (i.e. sagittally)
end
orig_labelmap.img(cropping==1) = out;
save_untouch_nii(orig_labelmap,sprintf('%s_Unfolded/laplace_PD.nii.gz',fn_noFT));

out = zeros(sz); out(idxgm) = ceil(Laplace_IO*10);
if isleft
    out = flipdim(out,3); %flip on z (i.e. sagittally)
end
orig_labelmap.img(cropping==1) = out;
save_untouch_nii(orig_labelmap,sprintf('%s_Unfolded/laplace_IO.nii.gz',fn_noFT));

toc;
end
