% tries to choose modalities to flatmap in this order: T1map > T1w/T2w > T1w

smoothKernel = fspecial('gaussian',[25 25],3);



%% prioritize from available modalities

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
    map = load_nii([quantitative_dir '/' sub '/anat/' qfilenames{p1(1)}]);
    map = map.img; 
    mapModality = 'T1map';
elseif ~isempty(p2) && ~isempty(p3) %T1w/T2w
    map1 = load_nii([quantitative_dir '/' sub '/anat/' qfilenames{p2(1)}]);
    map2 = load_nii([quantitative_dir '/' sub '/anat/' qfilenames{p3(1)}]);
    map = map1.img./map2.img; clear map1 map2
    mapModality = 'T1w/T2w';
elseif ~isempty(p3) %just take T1w
    map = load_nii([quantitative_dir '/' sub '/anat/' qfilenames{p2(1)}]);
    map = map.img;
    mapModality = 'T1w';
end

%% sample in same spaces

MRdata = zeros(sz);
MRdata(:) = map(cropping==1); clear map
if LR=='L'
    MRdata = flipdim(MRdata,1);
end
Vxyz = round(Vxyz);
inds = sub2ind(sz, Vxyz(:,1),Vxyz(:,2),Vxyz(:,3));
bad = isnan(inds);
inds(bad) = 1;
flatmap = MRdata(inds);
flatmap(bad) = nan;

flatmap = reshape(flatmap,[(APres+1),(PDres+1),(IOres+1)]);
flatmap = inpaintn(flatmap); % this should be done in 3D
% average across laminae
flatmap = mean(flatmap,3);
flatmap = imfilter(flatmap,smoothKernel,'symmetric');

% figure;
% p = patch('Faces',FV.faces,'Vertices',FV.vertices,'FaceVertexCData',flatmap(:));
% p.FaceColor = 'interp';
% p.LineStyle = 'none';
% axis equal;
% colormap('jet');

clearvars -except Vuvw Vxyz FV flatmap mapModality LR APres PDres IOres output
save([output '_qmap.mat']);