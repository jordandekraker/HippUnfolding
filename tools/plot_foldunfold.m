function figurehandle = plot_foldunfold(img,FV,smooth,plt_title)

if exist('smooth')~=1
    smooth = false;
end
if exist('plt_title')~=1
    plt_title = '';
end

if smooth % TODO: set adjustable input parameters
    img(isoutlier(img(:))) = nan;
    img = inpaintn(img);
    smoothKernel = fspecial('gaussian',[25 25],3);
    img = imfilter(img,smoothKernel,'symmetric');
end

% set 95% colourmap window
t = sort(img(:));
window = [t(round(length(t)*.05)) t(round(length(t)*.95))];

figurehandle=figure;
subplot(1,2,1);
p = patch('Faces',FV.faces,'Vertices',FV.vertices,'FaceVertexCData',img(:));
p.FaceColor = 'flat';
p.LineStyle = 'none';
axis equal tight;
% colormap('jet');
light;
caxis(window);
subplot(1,2,2);
imagesc(img');
title(plt_title);
axis equal tight;
% colormap('jet');
set(gca,'YDir','normal')
caxis(window);
% drawnow;
end