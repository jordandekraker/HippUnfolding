function [Laplace_thickness,absolute_thickness,SRLMcoveredSub_labelmap] = compute_thickness(labelmap,voxel_size)

%expects to compute thickness as length of Laplacian streamlines. assumes the following labels:
%greymatter (labelmap==1)
%clear label (labelmap==0)
%SRLM/cyst/medialEdgeOfUncus (labelmap==2/4/21)

%NOTE
% increasing x moves down
% increasing z moves medial
% y is coronal slices


%% first need to extend SRLM over the subiculum
%find where SRLM borders surface (i.e. medial edge)
se = ones(3,3,3);
medial_SRLM = (imdilate(labelmap==0,se) & labelmap==2);
[xedge,yedge,zedge] = ind2sub(size(labelmap),find(medial_SRLM));

%now for each of those points, walk medially along the border
%of grey matter (unless surpassed max steps or at medial edge or at inferior
%edge)
for a = 1:length(yedge)
    y = yedge(a);
    z = zedge(a);
    x = xedge(a);
    
    steps=0;
    while ((steps < 40) && z<(size(labelmap,3)) && x<(size(labelmap,1)))
        %choose step direction and make new label
        steps = steps+1;
        if (labelmap(x+1,y,z)==0 || labelmap(x+1,y,z)==2) %step down -- top priority step direction
            x=x+1;
        elseif (labelmap(x,y,z+1)==0 || labelmap(x,y,z+1)==2) %step medial
            z=z+1;
        elseif (labelmap(x-1,y,z)==0 || labelmap(x-1,y,z)==2) %step up -- low priority
            x=x-1;
        elseif (labelmap(x-1,y,z+1)==0 || labelmap(x-1,y,z+1)==2) %step up-medial in case stuck in a hole
            x=x-1; z=z+1;
        else
            break
        end
        labelmap(x,y,z) = 4;
    end
    labelmap(labelmap==4) = 2;
end
%dilate the result over clear label just to ensure no spots were missed
se = ones(3,3,3);
dil_DB = (imdilate(labelmap==2,se) & labelmap==0);
labelmap(dil_DB) = 2;
SRLMcoveredSub_labelmap = labelmap;

%% thicknesses Laplacian
Laplace_thickness = labelmap; %initialize

% Define ROIs
source=(labelmap==2 | labelmap==4 | labelmap==21); %SRLM/cyst/medialEdgeOfUncus
sink=(labelmap==0); %clear label
fg=(labelmap==1); %Greymatter

init = zeros(size(fg))+0.5;

if exist('laplace_iters_mex') > 0 % if mex file exists, use that (its faster!)
    [Laplace_thickness,~] = laplace_iters_mex(fg,source,sink,init);
else
    disp('no MEX file available. Running MATLAB code instead (slower)');
    [Laplace_thickness,~] = laplace_iters(fg,source,sink,init);
end
%% compute streamlines across gradient

%start points:  voxels bordering SRLM
se = zeros(3,3,3); se(2,2,:)=1; se(:,2,2)=1; se(2,:,2)=1; % 6 NN
startpts = (imdilate(source,se) & labelmap==1);
[sx,sy,sz] = ind2sub(size(Laplace_thickness),find(startpts));

%         figure;
%         scatter3(sy,sx,sz,'.');
%         axis equal;

% turn laplace gradient into a vector field
Laplace_thick_vectorized = zeros(size(labelmap));
Laplace_thick_vectorized(fg) = Laplace_thickness(fg);
Laplace_thick_vectorized(sink) = 1;
[dx,dy,dz]=gradient(Laplace_thick_vectorized);

%now stream
stepsize=0.1;
maxvert=100; %10 voxels at this stepsize
options=[stepsize,maxvert];
streams = stream3(dx,dy,dz,sy,sx,sz,options);

%% convert back to 3d space, compute length of streams

absolute_thickness = nan(size(labelmap));
thickness=nan(1,length(streams));
%sum up number of vertices in each stream, multiple by step size and voxel
%size
for i = 1:length(streams)
    if sum(~isnan(streams{i}(:,1))) < maxvert
        thickness(i)=sum(~isnan(streams{i}(:,1))).*stepsize*voxel_size;
        absolute_thickness(sx(i),sy(i),sz(i)) = thickness(i); %put thicknesses values in the starting points
    else
        thickness(i) = nan;
        absolute_thickness(sx(i),sy(i),sz(i)) = nan;
    end
end

end
