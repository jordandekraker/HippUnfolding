% NOTE: should load in laplace.mat and morphometry.mat first!


%% prioritize from available modalities
% tries to choose modalities to flatmap in this order: T1map > T1w/T2w > T1w

if ~isBIDS
    modality = load_untouch_nii(orig_img);
    modality = modality.img; 
    mapModality = 'Input intensity';
    
elseif isBIDS
    [~,qfilenames] = system(['ls ' quantitative_dir '/' sub '/anat']);
    qfilenames = strsplit(qfilenames)';
    i = strfind(qfilenames, '.nii');
    i = find(cellfun('isempty', i));
    qfilenames(i) = [];

    p1 = strfind(qfilenames, 'T1map');
    p1 = find(~cellfun('isempty', p1));
    p2 = strfind(qfilenames, 'T1w');
    p2 = find(~cellfun('isempty', p2));
    p3 = strfind(qfilenames, 'T2w');
    p3 = find(~cellfun('isempty', p3));
    
    if ~isempty(p1) %load first T1map available
        modality = load_untouch_nii([quantitative_dir '/' sub '/anat/' qfilenames{p1(1)}]);
        modality = modality.img; 
        mapModality = 'T1map';
    elseif ~isempty(p2) && ~isempty(p3) %T1w/T2w
        map1 = load_untouch_nii([quantitative_dir '/' sub '/anat/' qfilenames{p2(1)}]);
        map2 = load_untouch_nii([quantitative_dir '/' sub '/anat/' qfilenames{p3(1)}]);
        modality = map1.img./map2.img; clear map1 map2
        mapModality = 'T1w/T2w';
    elseif ~isempty(p2) %just take T1w
        modality = load_untouch_nii([quantitative_dir '/' sub '/anat/' qfilenames{p2(1)}]);
        modality = modality.img;
        mapModality = 'T1w';
    elseif ~isempty(p3) %just take T2w
        modality = load_untouch_nii([quantitative_dir '/' sub '/anat/' qfilenames{p3(1)}]);
        modality = modality.img;
        mapModality = 'T2w';
    end
end

%% sample in same spaces

MRdata = zeros(sz);
MRdata(:) = modality(cropping==1); clear map
%if LR=='L'
%    MRdata = flipdim(MRdata,1);
%end
Vxyz = round(Vxyz);
inds = sub2ind(sz, Vxyz(:,1),Vxyz(:,2),Vxyz(:,3));
bad = isnan(inds);
inds(bad) = 1;
flatmap = MRdata(inds);
flatmap(bad) = nan;

flatmap = reshape(flatmap,[(APres),(PDres),(IOres)]);

if exist('suppress_visuals')==0
    suppress_visuals = 0;
end
if suppress_visuals==0
    tmp = flatmap;
    tmp(isoutlier(tmp(:),'mean')) = nan;
    tmp = inpaintn(tmp); % this should be done in 3D
    tmp = nanmean(flatmap,3);
    plot_foldunfold(tmp,FV,true,mapModality);
end

save([output 'qmap.mat'],'Vuvw','Vxyz','FV','flatmap','mapModality','LR',...
    'APres','PDres','IOres','output');
