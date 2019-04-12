function csvToVTK (in_points_csv, in_triangles_csv, out_vtk)

%in_points_csv='INDD100551-R.surf/surf_points_w1.csv'
%in_triangles_csv='INDD100551-R.surf/surf_triangles_w1.csv'
%out_vtk='INDD100551-R.surf/test_surf_tri_w1.vtk'

vertices=dlmread(in_points_csv,',',1,0);
vertices=vertices(:,1:3); %throw away garbage cols 3-6

%convert from LPS to RAS
vertices(:,1:2)=-vertices(:,1:2);

triangles=dlmread(in_triangles_csv,',',1,0);

vtkwrite(out_vtk,'polydata','triangle',vertices(:,1),vertices(:,2),vertices(:,3),triangles);

end