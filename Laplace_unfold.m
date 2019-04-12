function out = Laplace_unfold(manual_mask,output_dir,orig_img,labeldescription_fn,suppress_visuals)
% performs laplacian unfolding on the image of manually labelled structures
%
% INPUTS:
% manual_masks: single nifti file
% output_dir: relative or absolute path
% orig_img: same space as manual_mask. For quantitative mapping only.
% labeldescription_fn(optional): 1 for basic structures, 2 for extended
% dummy labels, or specify custom .tsv file (see misc/labeldescription.tsv)
% suppress_visuals(optional): 0(default) or 1 generate binned .nii and
% gradients and morphometry/quantitative map figures

%% default arguments

% parameters to be set
APres = 256; PDres = 128; IOres = 4;
%ratio should be aproximately 2:1:(1/32 or 1/16)

%orthogonalization of AP and PD gradients (by adjusting boundary
%conditions) (causes additional problems on low-res data)
orthogonalize = false;

if exist('labeldescription_fn')~=1 || isempty('labeldescription_fn')
    labeldescription_fn = 1;
end
if exist('suppress_visuals')~=1 || isempty('suppress_visuals')
    suppress_visuals = 0;
end
isBIDS = false;

%% get & format label description file
if labeldescription_fn==1
    labeldescription_fn = 'misc/labeldescription_basic.tsv';
elseif labeldescription_fn==2
    labeldescription_fn = 'misc/labeldescription_extendedSRLMdummylabels.tsv';
end
labeldescription = tdfread(labeldescription_fn);
labeldescription.label = cellstr(labeldescription.label);
labeldescription.boundary = cellstr(labeldescription.boundary);
labeldescription = table(labeldescription.boundary,labeldescription.value,labeldescription.label);

%% get output filename
output = [output_dir '/'];
mkdir(output);
LR = strmatch(output_dir,'hemi-');
if LR>0
    LR = output_dir(LR+5);
else
    disp('please specify either hemi-L or hemi-R in output_dir');
    break
end

%% load & crop manual segmentation
origheader = load_untouch_nii(manual_mask);

% crop around hippocampus by finding min and max in each direction that
% contain non-zero label, and add one more voxel on each side just in case
origsz = size(origheader.img);
[x,y,z] = ind2sub(origsz,find(origheader.img>0));
cropping = false(origsz); %initialize
cropping(min(x):max(x),min(y):max(y),min(z):max(z)) = true;
labelmap = zeros(max(x)-min(x)+1,max(y)-min(y)+1,max(z)-min(z)+1); %+3 because 2 come from expanding min and max domain by 1;
labelmap(:) = origheader.img(cropping==1);
origheader.img = [];
sz = size(labelmap);
preprocess_labelmaps;% removes 'islands'
idxgm = find(ismember(labelmap,labeldescription.Var2(contains(cellstr(labeldescription.Var1),'domain'))));
%note this is the domain for each gradient

%% AP gradient:

%Define ROIs
sourceAP = find(ismember(labelmap,labeldescription.Var2(contains(cellstr(labeldescription.Var1),'APsource'))));
sinkAP = find(ismember(labelmap,labeldescription.Var2(contains(cellstr(labeldescription.Var1),'APsink'))));

Laplace_AP = laplace_solver(idxgm,sourceAP,sinkAP,50,[],sz);


%% PD gradient

% Define ROIs for Laplacian
sourcePD = find(ismember(labelmap,labeldescription.Var2(contains(cellstr(labeldescription.Var1),'PDsource'))));
sinkPD = find(ismember(labelmap,labeldescription.Var2(contains(cellstr(labeldescription.Var1),'PDsink'))));
if isempty(sinkPD)
    %have to make these dummy labels ourselves
    automatic_DGgcl_approximation; %note: has to be run after Laplace_AP
    sinkPD=find(sink_main | sink_unc); %DGgcl
end
Laplace_PD = laplace_solver(idxgm,sourcePD,sinkPD,50,[],sz);

%% Laminar gradient
% compute thicknesses
        % check if SRLM covers subiculum
if ~exist(labeldescription.Var2(contains(cellstr(labeldescription.Var3),'(dummy label) SRLM over subiculum')))
    extend_SRLM; %note: extended SRLM label number is 44
end
sourceIO = find(ismember(labelmap,[44;labeldescription.Var2(contains(cellstr(labeldescription.Var1),'IOsource'))]));
sinkIO = find(ismember(labelmap,labeldescription.Var2(contains(cellstr(labeldescription.Var1),'IOsink'))));

Laplace_IO = laplace_solver(idxgm,sourceIO,sinkIO,50,[],sz);

%% orthogonalize Laplace_AP
% gets the current edges of unfolded space, and then adjusts the boundary
% conditions for the AP and PD gradients such that they always meet, making
% them closer to orthogonal at the edges

if orthogonalize
    laplace_orthogonalize; %this seems to work poorly on low-res data...
end

%% solve again, using more iters and with orthogonalized boundary conditions
Laplace_AP = laplace_solver(idxgm,sourceAP,sinkAP,1000,Laplace_AP,sz);
Laplace_PD = laplace_solver(idxgm,sourcePD,sinkPD,1000,Laplace_PD,sz);

%% clean up and save all variables

bad = find(isnan(Laplace_AP) | isnan(Laplace_PD) | isnan(Laplace_IO) | isnan(idxgm));
if bad > 0
    sprintf('removing %d bad voxels; sometimes happens due to islands in manual seg',length([bad;bad]))
end
Laplace_AP(bad) = []; Laplace_PD(bad) = []; Laplace_IO(bad) = []; idxgm(bad) = [];

save([output 'laplace.mat'],'origsz','output','LR','cropping',...
'origheader','idxgm','sz','Laplace_AP','Laplace_PD','Laplace_IO',...
'sourceAP','sinkAP','sourcePD','sinkPD','sourceIO','sinkIO',...
'manual_mask','labeldescription','orig_img','isBIDS',...
'APres', 'PDres', 'IOres');

%% binned niftis for visualization
if suppress_visuals==0
    origheader.img = zeros(origsz);

    out = zeros(sz);
    out(idxgm) = Laplace_AP*100;
    out(sinkAP) = 101;
    out(sourceAP) = 102;
    origheader.img(cropping==1) = out;
    save_untouch_nii(origheader,[output 'srcsnk-AP_PhiMap.nii.gz']);

    out = zeros(sz);
    out(idxgm) = Laplace_PD*100;
    out(sinkPD) = 101;
    out(sourcePD) = 102;
    origheader.img(cropping==1) = out;
    save_untouch_nii(origheader,[output 'srcsnk-PD_PhiMap.nii.gz']);

    out = zeros(sz);
    out(idxgm) = Laplace_IO*100;
    out(sourceIO) = 101;
    origheader.img(cropping==1) = out;
    save_untouch_nii(origheader,[output 'srcsnk-IO_PhiMap.nii.gz']);
end

%% try some quantitative analyses
try
    Unfolded_morphometry
catch
    disp('Error in morphometry mapping, but unfolding coordinates are still correct.');
end
try
    Unfolded_qmapping
catch
    disp('Error in quantitative mapping, but unfolding coordinates are still correct.');
end

disp('Done. Please inspect results to ensure correct unfolding!');


out = 1;
end
