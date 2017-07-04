function out = intensity_surf(fn)

out = 0;

load([fn '_Unfolded/data.mat']);
load('all_plots_data.mat');
avg_image = round(100*(avg_image-min(avg_image(:)))/(max(avg_image(:))-min(avg_image(:))));

[P,V,E]=readBYUSurface('output_file_cpp.byu');
% 
%V = round(V);
[x,y,z] = ind2sub(size(cropping),find(cropping==1));
V(:,1) = V(:,1) - min(x)+1;
V(:,2) = V(:,2) - min(y)+1;
V(:,3) = V(:,3) - min(z)+1;

Laplace_AP(Laplace_AP==0) = 1; %these range 0-100, but can only have 100 indices
Laplace_PD(Laplace_PD==0) = 1;

[greymatter(:,1) greymatter(:,2) greymatter(:,3)] = ind2sub(size(labelmap),find(Laplace_AP>0));

IDX = knnsearch(greymatter,V); % main function! finds closest corresponging GM voxel to each vertex

    AP = Laplace_AP(Laplace_AP>0);
    PD = Laplace_PD(Laplace_AP>0);
    y = AP(IDX);
    x = PD(IDX);
    
    fileID = fopen('vertexcolours.txt','w');
for vertex = 1:length(V)  
    if isnan(x(vertex)) || isnan(y(vertex))
        colour(vertex) = 50;
    else
    colour(vertex) = avg_image(x(vertex),y(vertex));
    end
    nbyte = fprintf(fileID,sprintf('%d\n',colour(vertex)));
end

out = 1;
end