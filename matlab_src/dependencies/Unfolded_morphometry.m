% parameters to be set
% APres = 256; PDres = 128; IOres = 8;
%ratio should be aproximately 2:1:(1/32 or 1/16)



rm = find(isnan(Laplace_AP) | isnan(Laplace_PD) | isnan(Laplace_IO));
Laplace_AP(rm)=[]; Laplace_PD(rm)=[]; Laplace_IO(rm)=[]; idxgm(rm)=[];

%% interpolate between unfolded and native space

[i_L,j_L,k_L]=ind2sub(sz,idxgm);
APsamp = [1:APres]/(APres+1); 
PDsamp = [1:PDres]/(PDres+1); 
IOsamp = [1:IOres]/(IOres+1); 
[v,u,w] = meshgrid(PDsamp,APsamp,IOsamp); % have to switch AP and PD because matlab sucks
Vuvw = [u(:),v(:),w(:)];

interp='linear';
extrap='nearest';
scattInterp=scatteredInterpolant(Laplace_AP,Laplace_PD,Laplace_IO,i_L,interp,extrap);
x = scattInterp(Vuvw(:,1),Vuvw(:,2),Vuvw(:,3));
scattInterp=scatteredInterpolant(Laplace_AP,Laplace_PD,Laplace_IO,j_L,interp,extrap);
y = scattInterp(Vuvw(:,1),Vuvw(:,2),Vuvw(:,3));
scattInterp=scatteredInterpolant(Laplace_AP,Laplace_PD,Laplace_IO,k_L,interp,extrap);
z = scattInterp(Vuvw(:,1),Vuvw(:,2),Vuvw(:,3));
clear scattInterp
Vxyz = [x(:) y(:) z(:)];

%% get midpoint surface

% get face connectivity
t = [1:(APres*PDres)]';
F = [t,t+1,t+(APres) ; t,t-1,t-(APres)];

F = reshape(F',[3,APres,PDres,2]);
F(:,APres,:,1) = nan;
F(:,1,:,2) = nan;
F(:,:,PDres,1) = nan;
F(:,:,1,2) = nan;
F(isnan(F)) = [];
F=reshape(F,[3,(APres-1)*(PDres-1)*2])';
FV.faces = F;

% get midpoint vertices
IO=ceil(IOres/2);
x = reshape(x,(APres),(PDres),(IOres));
y = reshape(y,(APres),(PDres),(IOres));
z = reshape(z,(APres),(PDres),(IOres));
x = x(:,:,IO); y = y(:,:,IO); z = z(:,:,IO);
FV.vertices = [x(:) y(:) z(:)];

% mask any area outside roi
[~,keep1] = intersect(floor(Vxyz),[i_L,j_L,k_L],'rows');
[~,keep2] = intersect(ceil(Vxyz),[i_L,j_L,k_L],'rows');
keep = unique([keep1; keep2]);
FV.vertices(~keep,:) = nan;

%% compute curvatures

warning('off');
Cmean = patchcurvature(FV);%, true);
Cmean = real(Cmean);
if LR=='R'
    Cmean = -Cmean; %opens on opposite side
end
warning('on');
Cmean = reshape(Cmean,[APres,PDres]);

if exist('suppress_visuals')==0
    suppress_visuals = 0;
end
if suppress_visuals==0
    tmp = Cmean;
    smoothKernel = fspecial('gaussian',[25 25],3);
    tmp(isoutlier(tmp(:),'mean')) = nan;
    tmp = inpaintn(tmp); 
    tmp = imfilter(tmp,smoothKernel,'symmetric');
    t = sort(tmp(:));
    window = [t(round(length(t)*.05)) t(round(length(t)*.95))];

    figure; 
    subplot(1,2,1);
    p = patch('Faces',FV.faces,'Vertices',FV.vertices,'FaceVertexCData',tmp(:));
    p.FaceColor = 'flat';
    p.LineStyle = 'none';
    axis equal tight;
    colormap('jet');
    light;
    caxis(window);
    title('curvature');
    subplot(1,2,2); 
    imagesc(tmp');
    axis equal tight;
    colormap('jet');
    caxis(window);
    drawnow;
end

%% compute thickness

voxelsize = origheader.hdr.dime.pixdim(2); %mm
threshold = [0.1 4.0]; %min and max thicknesses in mm
stepsize = 0.1;
maxvert = threshold(2)/voxelsize/stepsize;

start = [x(:) y(:) z(:)];
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

streamlengths = reshape(streamlengths,[APres,PDres]);

if suppress_visuals==0
    tmp = streamlengths;
    smoothKernel = fspecial('gaussian',[25 25],3);
    tmp(isoutlier(tmp(:),'mean')) = nan;
    tmp = inpaintn(tmp);
    tmp = imfilter(tmp,smoothKernel,'symmetric');
    t = sort(tmp(:));
    window = [t(round(length(t)*.05)) t(round(length(t)*.95))];
    
    figure; 
    subplot(1,2,1);
    p = patch('Faces',FV.faces,'Vertices',FV.vertices,'FaceVertexCData',tmp(:));
    p.FaceColor = 'flat';
    p.LineStyle = 'none';
    axis equal tight;
    colormap('jet');
    light;
    caxis(window);
    title('thickness');
    subplot(1,2,2); 
    imagesc(tmp');
    axis equal tight;
    colormap('jet');
    caxis(window);
    drawnow;
end

save([output 'morphometry.mat'],'Vuvw','Vxyz','FV','Cmean','streamlengths',...
    'LR','APres','PDres','IOres','output');
