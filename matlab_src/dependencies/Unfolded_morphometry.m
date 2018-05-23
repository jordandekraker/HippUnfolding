% parameters to be set
APres = 256; PDres = 128; IOres = 8;
%ratio should be aproximately 2:1:(1/32 or 1/16)
smoothKernel = fspecial('gaussian',[25 25],3);



rm = find(isnan(Laplace_AP) | isnan(Laplace_PD) | isnan(Laplace_IO));
Laplace_AP(rm)=[]; Laplace_PD(rm)=[]; Laplace_IO(rm)=[]; idxgm(rm)=[];

%% interpolate between unfolded and native space

[i_L,j_L,k_L]=ind2sub(sz,idxgm);
APsamp = 0:1/APres:1; PDsamp = 0:1/PDres:1; IOsamp = 0:1/IOres:1;
[v,u,w] = meshgrid(PDsamp,APsamp,IOsamp); % have to switch AP and PD because matlab sucks
Vuvw = [u(:),v(:),w(:)];

interp='linear';
extrap='none';
scattInterp=scatteredInterpolant(Laplace_AP,Laplace_PD,Laplace_IO,i_L,interp,extrap);
x = scattInterp(Vuvw(:,1),Vuvw(:,2),Vuvw(:,3));
scattInterp=scatteredInterpolant(Laplace_AP,Laplace_PD,Laplace_IO,j_L,interp,extrap);
y = scattInterp(Vuvw(:,1),Vuvw(:,2),Vuvw(:,3));
scattInterp=scatteredInterpolant(Laplace_AP,Laplace_PD,Laplace_IO,k_L,interp,extrap);
z = scattInterp(Vuvw(:,1),Vuvw(:,2),Vuvw(:,3));
clear scattInterp

Vxyz = [x(:),y(:),z(:)];

% mask area outside roi
[~,keep1] = intersect(floor(Vxyz),[i_L,j_L,k_L],'rows');
[~,keep2] = intersect(ceil(Vxyz),[i_L,j_L,k_L],'rows');
keep = unique([keep1; keep2]);
toss = 1:length(Vxyz); toss(keep) = [];
%         Vxyz(toss,:) = nan;

%% compute curvatures

% get face connectivity
t = [1:(APres+1)*(PDres+1)]';
F = [t,t+1,t+(APres+1) ; t,t-1,t-(APres+1)];
badfaces = any(F>(APres+1)*(PDres+1) | F<=0 , 2);
F(badfaces,:) = [];

% midpoint curvatures
IO=ceil(IOres/2);
x = reshape(x,(APres+1),(PDres+1),(IOres+1));
y = reshape(y,(APres+1),(PDres+1),(IOres+1));
z = reshape(z,(APres+1),(PDres+1),(IOres+1));
x2 = x(:,:,IO); y2 = y(:,:,IO); z2 = z(:,:,IO);
FV.vertices = [x2(:) y2(:) z2(:)];
FV.faces = F;
warning('off');
Cmean = patchcurvature(FV);%, true);
warning('on');

Cmean = reshape(Cmean,[APres+1,PDres+1]);
Cmean(isoutlier(Cmean(:),'mean')) = nan;
Cmean = inpaintn(Cmean);
Cmean = imfilter(Cmean,smoothKernel,'symmetric');
   
if suppress_visuals==0
    figure;
    p = patch('Faces',FV.faces,'Vertices',FV.vertices,'FaceVertexCData',Cmean(:));
    p.FaceColor = 'interp';
    p.LineStyle = 'none';
    axis equal;
    colormap('jet');
    title([sub 'hemi-' LR ' mean curvature']);
end

%% compute thickness

voxelsize = origheader.hdr.dime.pixdim(2); %mm
threshold = [0.1 4.0]; %min and max thicknesses in mm
stepsize = 0.1;
maxvert = threshold(2)/voxelsize/stepsize;

start = [x2(:) y2(:) z2(:)];
start(isnan(start)) = 0;

% midpoint to outside
Space3d = ones(sz);
Space3d(idxgm) = Laplace_IO;
[dx,dy,dz]=gradient(Space3d);
clear Space3d
streams = stream3(dx,dy,dz,start(:,2),start(:,1),start(:,3),[stepsize,maxvert]); %switch dims 1 and 2 because matlab is dumb
clear dx dy dz
for n = 1:length(streams)
    streamlengths1(n) = stepsize*voxelsize*size(streams{n},1);
end
clear streams

% midpoint to inside
Space3d = ones(sz);
Space3d(idxgm) = -Laplace_IO+1;
[dx,dy,dz]=gradient(Space3d);
clear Space3d
streams = stream3(dx,dy,dz,start(:,2),start(:,1),start(:,3),[stepsize,maxvert]); %switch dims 1 and 2 because matlab is dumb
clear dx dy dz
for n = 1:length(streams)
    streamlengths2(n) = stepsize*voxelsize*size(streams{n},1);
end
clear streams

% combine and delete bad streams
streamlengths = streamlengths1 + streamlengths2;
bad = find(streamlengths>=threshold(2) | streamlengths<=threshold(1));
streamlengths(bad) = nan;

streamlengths = reshape(streamlengths,[APres+1,PDres+1]);
streamlengths(isoutlier(streamlengths(:),'mean')) = nan;
streamlengths = inpaintn(streamlengths);
streamlengths = imfilter(streamlengths,smoothKernel,'symmetric');

if suppress_visuals==0
figure;
p = patch('Faces',FV.faces,'Vertices',FV.vertices,'FaceVertexCData',streamlengths(:));
p.FaceColor = 'interp';
p.LineStyle = 'none';
axis equal;
colormap('jet');
title([sub 'hemi-' LR ' thickness']);
end

save([output '_morphometry.mat'],'Vuvw','Vxyz','FV','Cmean','streamlengths',...
    'LR','APres','PDres','IOres','output');
