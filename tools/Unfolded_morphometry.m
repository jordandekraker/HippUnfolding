% NOTE: should load in laplace.mat first!


if exist('suppress_visuals')==0
    suppress_visuals = 0;
end

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

% get midpoint vertices
IO=ceil(IOres/2);
Vmid = reshape(Vxyz,[APres,PDres,IOres,3]);
Vmid = Vmid(:,:,IO,:);

% smooth using Cosine Representation
Vrec = CosineRep_2Dsurf(Vmid,64,0.01);
Vmid = reshape(Vmid,[APres*PDres,3]);


FV.vertices = reshape(Vrec,[APres*PDres,3]);
FV.faces = F;

%% get gyrification index

Vrec = reshape(Vrec,[APres,PDres,3]);
for PD=1:PDres-1
    for AP=1:APres-1
        arcPD(AP,PD) = norm(squeeze(squeeze(Vrec(AP,PD,:)-Vrec(AP,PD+1,:))));
        arcAP(AP,PD) = norm(squeeze(squeeze(Vrec(AP,PD,:)-Vrec(AP+1,PD,:))));
    end
end
GI = imresize(arcAP.^2+arcPD.^2,[APres,PDres]);
Vrec = reshape(Vrec,[APres*PDres,3]);

if suppress_visuals==0
    plot_foldunfold(GI,FV,true,'Gyrification Index');
end

%% compute curvatures

warning('off');
Cmean = patchcurvature(FV);%, true);
Cmean = real(Cmean);
if LR=='R'
    Cmean = -Cmean; %opens on opposite side
end
warning('on');
Cmean = reshape(Cmean,[APres,PDres]);

if suppress_visuals==0
    plot_foldunfold(Cmean,FV,true,'Curvature');
end

%% compute thickness

voxelsize = origheader.hdr.dime.pixdim(2); %mm
threshold = [0.1 4.0]; %min and max thicknesses in mm
stepsize = 0.1;
maxvert = threshold(2)/voxelsize/stepsize;

start = Vmid;
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
    plot_foldunfold(streamlengths,FV,true,'Thickness');
end

save([output 'morphometry.mat'],'Vuvw','Vxyz','Vmid','Vrec','F','FV','Cmean','streamlengths','GI',...
    'LR','APres','PDres','IOres','output');
