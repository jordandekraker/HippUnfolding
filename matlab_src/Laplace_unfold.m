function out = Laplace_unfold(labelmap_fn,outdir,labeldescription_fn)
% performs laplacian unfolding on the image of manually labelled structures

% labeldescription filename can be ==1 if dentate gyrus and SRLM extended
% dummy labels are not present (default), or ==2 if they are, or a string can be
% provided to a custom labelmap file (.tsv; see current example)

% all outputs are in BIDS format. Output files include a binned
% visualizations (.nii.gz) of the unfolding in each dimension. Check for
% major distortions caused by errors in manual segmentation! Also outputs a
% data.mat file containing all the variables of interest and the actual Laplace
% gradients.

%% get output filename
subs = strfind(labelmap_fn,'sub');
subs = subs(1);
subf = strfind(labelmap_fn(subs:end),'/');
subf = subf(1)+subs-2;
sub = labelmap_fn(subs:subf);
fnf = strfind(labelmap_fn,'/')+1;
fn = labelmap_fn(fnf(end):strfind(labelmap_fn,'.nii')-1);
try
fn = labelmap_fn(fnf(end):strfind(labelmap_fn,'_roi.nii')-1);
end
output = [outdir '/' sub '/anat/' fn];
outd = strfind(output,'/');
mkdir(output(1:outd(end)));


%% get & format label description file
if exist('labeldescription_fn') ~= 1
    labeldescription_fn = 1;
end
if labeldescription_fn==1
    labeldescription_fn = 'misc/labeldescription_basic.tsv';
elseif labeldescription_fn==2
    labeldescription_fn = 'misc/labeldescription_extendedSRLMdummylabels.tsv';
end
labeldescription = tdfread(labeldescription_fn);
labeldescription.label = cellstr(labeldescription.label);
labeldescription.boundary = cellstr(labeldescription.boundary);
labeldescription = table(labeldescription.boundary,labeldescription.value,labeldescription.label);

%% load & crop manual segmentation
origheader = load_nii(labelmap_fn);

% crop around hippocampus by finding min and max in each direction that
% contain non-zero label, and add one more voxel on each side just in case
[x,y,z] = ind2sub(size(origheader.img),find(origheader.img>0));
cropping = false(size(origheader.img)); %initialize
cropping(min(x)-1:max(x)+1,min(y)-1:max(y)+1,min(z)-1:max(z)+1) = true;
labelmap = zeros(max(x)-min(x)+3,max(y)-min(y)+3,max(z)-min(z)+3); %+3 because 2 come from expanding min and max domain by 1;
labelmap(:) = origheader.img(cropping==1);
origheader.img = [];

% if left hippocampus, flip
LR = output(strfind(output,'hemi-')+5);
if LR=='L'
    labelmap = flipdim(labelmap,1); %flip on x (i.e. sagittally)
end

sz = size(labelmap);
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
if strmatch(labeldescription_fn, 'misc/labeldescription_extendedSRLMdummylabels.tsv') ==1
    sinkPD = find(ismember(labelmap,labeldescription.Var2(contains(cellstr(labeldescription.Var1),'PDsink'))));
else
    %have to make these dummy labels ourselves
    extend_SRLM; 
    automatic_DGgcl_approximation; %note: has to be run after Laplace_AP
    
    sinkPD=find(sink_main | sink_unc); %DGgcl
end

Laplace_PD = laplace_solver(idxgm,sourcePD,sinkPD,50,[],sz);

%% Laminar gradient
% compute thicknesses
sourceIO = find(ismember(labelmap,labeldescription.Var2(contains(cellstr(labeldescription.Var1),'IOsource'))));
sinkIO = find(ismember(labelmap,labeldescription.Var2(contains(cellstr(labeldescription.Var1),'IOsink'))));

Laplace_IO = laplace_solver(idxgm,sourceIO,sinkIO,50,[],sz);

%% orthogonalize Laplace_AP
% gets the current edges of unfolded space, and then adjusts the boundary
% conditions for the AP and PD gradients such that they always meet, making
% them closer to orthogonal at the edges
laplace_orthogonalize; 

%% solve again, using more iters and with orthogonalized boundary conditions
Laplace_AP = laplace_solver(idxgm,sourceAP,sinkAP,1000,Laplace_AP,sz);
Laplace_PD = laplace_solver(idxgm,sourcePD,sinkPD,1000,Laplace_PD,sz);

%% clean up and save all variables

bad2 = find(isnan(Laplace_AP) | isnan(Laplace_PD) | isnan(Laplace_IO) | isnan(idxgm));
sprintf('removing %d bad voxels; sometimes happens due to islands in manual seg',length([bad;bad2]))
Laplace_AP(bad) = []; Laplace_PD(bad) = []; Laplace_IO(bad) = []; idxgm(bad) = [];

%% binned niftis for visualization
out = zeros(sz); 
out(idxgm) = ceil(Laplace_AP*20);
out(sinkAP) = 50;
out(sourceAP) = 51;
if LR=='L'
    out = flipdim(out,1); %flip on x (i.e. sagittally)
end
origheader.img(cropping==1) = out;
save_nii(origheader,[output '_srcsnk-AP_PhiMap.nii.gz']);

out = zeros(sz); 
out(idxgm) = ceil(Laplace_PD*20);
out(sinkPD) = 50;
out(sourcePD) = 51;
if LR=='L'
    out = flipdim(out,1); %flip on x (i.e. sagittally)
end
origheader.img(cropping==1) = out;
save_nii(origheader,[output '_srcsnk-PD_PhiMap.nii.gz']);

out = zeros(sz); 
out(idxgm) = ceil(Laplace_IO*10);
out(sourceIO) = 51;
if LR=='L'
    out = flipdim(out,1); %flip on x (i.e. sagittally)
end
origheader.img(cropping==1) = out;
save_nii(origheader,[output '_srcsnk-IO_PhiMap.nii.gz']);


%%
clearvars -except output LR cropping sub origheader idxgm sz Laplace_AP Laplace_PD Laplace_IO sourceAP sinkAP sourcePD sinkPD sourceIO sinkIO;
save([output '_data.mat']);

try
unfolding_visualize
end
out = 1;
end
