function unfoldToVTK (in_unfold_dir,out_surf_dir)

%requires

load(sprintf('%s/morphometry.mat',in_unfold_dir));
load(sprintf('%s/laplace.mat',in_unfold_dir));

%get original image for physical xfm

sform=[origheader.hdr.hist.srow_x;
    origheader.hdr.hist.srow_y;
    origheader.hdr.hist.srow_z;
    0,0,0,1];


file_prefix='surf';

dsPD=1; %set 1 to not downsample
dsAP=1;


%create a surf mesh at w=1:4

for depth=1:IOres
    
    vol_u=reshape(Vuvw(:,1),[APres,PDres,IOres]);
    vol_v=reshape(Vuvw(:,2),[APres,PDres,IOres]);
    vol_w=reshape(Vuvw(:,3),[APres,PDres,IOres]);
    
    vol_x=reshape(Vxyz(:,1),[APres,PDres,IOres]);
    vol_y=reshape(Vxyz(:,2),[APres,PDres,IOres]);
    vol_z=reshape(Vxyz(:,3),[APres,PDres,IOres]);
    
    %pick out depth and downsample if needed
    vol_u=vol_u(1:dsAP:end,1:dsPD:end,depth);
    vol_v=vol_v(1:dsAP:end,1:dsPD:end,depth);
    vol_w=vol_w(1:dsAP:end,1:dsPD:end,depth);
    
    vol_x=vol_x(1:dsAP:end,1:dsPD:end,depth);
    vol_y=vol_y(1:dsAP:end,1:dsPD:end,depth);
    vol_z=vol_z(1:dsAP:end,1:dsPD:end,depth);
    
    
    %create triangulation from UV mesh
    Dtri=delaunayTriangulation(reshape(vol_u,[prod(size(vol_u)),1]),reshape(vol_v,[prod(size(vol_v)),1]));
    
    vertices=[reshape(vol_x,[prod(size(vol_x)),1]),reshape(vol_y,[prod(size(vol_y)),1]),reshape(vol_z,[prod(size(vol_z)),1])];
    
    % get crop params from cropping and origsz
    crop_x=find(squeeze(max(max(cropping,[],2),[],3))>0);
    crop_y=find(squeeze(max(max(cropping,[],1),[],3))>0);
    crop_z=find(squeeze(max(max(cropping,[],1),[],2))>0);
    
    crop_param=[crop_x(1), crop_y(2), crop_z(3)];
    
    crop_param=crop_param-1; %this may be off a little bit, look into it..
    
    %subtract from vertices
    vertices=vertices+repmat(crop_param,size(vertices,1),1);
    
    vertices=sform*[vertices';ones(1,length(vertices))];
    vertices=vertices(1:3,:)';
    
    %manual correction
    %vertices(:,1)=vertices(:,1)-0.2;
    %vertices(:,3)=vertices(:,3)-0.2;
    
    mkdir(out_surf_dir);
    vtk_out=sprintf('%s/%s_depth-%d_polydata.vtk',out_surf_dir,file_prefix,depth);

    vtkwrite(vtk_out,'polydata','triangle',vertices(:,1),vertices(:,2),vertices(:,3),Dtri.ConnectivityList);
    %writeTriByu(sprintf('surf_tri_w%d.g',depth),Dtri.ConnectivityList,vertices);
    
    %create csv file of vertices for ANTS (a
    csvdata=[vertices,zeros(size(vertices))];
    %header line: x,y,z,t,label,comment
    
    %make LPS (flip sign on xy)
    csvdata(:,1:2)=-csvdata(:,1:2);
    
  
    csv_out=sprintf('%s/%s_depth-%d_vertices.csv',out_surf_dir,file_prefix,depth);
    fprintf(fopen(csv_out,'w'),'x,y,z,t,label,comment\n');
    dlmwrite(csv_out,csvdata,'-append');
    
    %create csv file of triangles
    csvdata=Dtri.ConnectivityList;
    
    csv_out=sprintf('%s/%s_depth-%d_tri.csv',out_surf_dir,file_prefix,depth);
    fprintf(fopen(csv_out,'w'),'i1,i2,i3\n');
    dlmwrite(csv_out,csvdata,'-append')
    
    
end

% create tetrahedral mesh?

%Dtetra=delaunayTriangulation(Vuvw(:,1),Vuvw(:,2),Vuvw(:,3));

%vtkwrite('test_tetra.vtk','polydata','tetrahedron',Vxyz(:,1),Vxyz(:,2),Vxyz(:,3),Dtetra.ConnectivityList);

end