function out = plot_UnfoldedSpace(unfolded_fn,MRimage)
% finds and plots the MRimage intensities at each A-P and P-D coordinate.
% includes average borders from current study, and rescales the
% image according to average real world size from the current study.

load('avg_borders.mat')
SEM_borders = stdev_borders./sqrt(size(borders,3));

load([unfolded_fn '/data.mat']);
data = load_untouch_nii(MRimage);

% crop (already done in the example image loaded here)
cropped_data = data.img;
% cropped_data = zeros(size(labelmap));
% cropped_data(:) = data.img(cropping==1);

%if left, flip on sagittal (z plane, or the third dimension in this matrix)
if isleft
    cropped_data = flipdim(cropped_data,3);
end


%% run through all indexes and retreive intensities

for AP = 1:100
    for PD = 1:100
        vox = (Laplace_AP==AP & Laplace_PD==PD);
        if max(vox(:))>0 %if this coord exists
            flatmap(PD,AP) = nanmean(cropped_data(vox)); %might be more than 1 voxel
            flatmap_nvoxels(PD,AP) = length(vox);
        else
            flatmap(PD,AP) = NaN;
            flatmap_nvoxels(PD,AP) = 0;
        end
    end
end

%% interpolate and smooth the map

[Xq, Yq] = find(~isnan(flatmap));
F = scatteredInterpolant(Xq,Yq,flatmap(~isnan(flatmap)),'nearest','nearest');
[Xq, Yq] = find(isnan(flatmap));
flatmap_interp = flatmap;
flatmap_interp(isnan(flatmap)) = F(Xq,Yq);

%% plot!

figure; hold on;
axis([1 100 1 100]);
imagesc(flatmap_interp)
colormap('jet')

% overlay data from manual segmentations (in referenced paper) to help get oriented in UnfoldedSpace
for b = 1:4
    y = avg_borders(:,b);
    x = [1:100]';
    plot(y,'k');
    dy = SEM_borders(:,b);
    fill([x;flipud(x)],[y-dy;flipud(y+dy)],[0 0 0],'FaceAlpha', 0.3,'linestyle','none');
end
x = [5 18]; y = [1,100]; plot(x,y,'--k'); %vertical component
x = [20 28]; y = [1,100]; plot(x,y,'--k'); %uncus
x = [36 40]; y = [1,100]; plot(x,y,'--k'); %head
x = [84 80]; y = [1,100]; plot(x,y,'--k'); %tail
xlabel('Anterior - Posterior (%)');
ylabel('Proximal - Distal (%)');
title(sprintf('Average subfield borders overlaid on\nintracortical myelin'));
annotation('textbox',[0.45 0.20 0.08 0.06],'String',{'Sub'},'LineStyle','none','FontWeight','bold');
annotation('textbox',[0.45 0.50 0.08 0.06],'String',{'CA1'},'LineStyle','none','FontWeight','bold');
annotation('textbox',[0.45 0.66 0.08 0.06],'String',{'CA2'},'LineStyle','none','FontWeight','bold');
annotation('textbox',[0.45 0.76 0.08 0.06],'String',{'CA3'},'LineStyle','none','FontWeight','bold');
annotation('textbox',[0.45 0.845 0.20 0.06],'String',{'DG'},'LineStyle','none','FontWeight','bold');

annotation('textbox',[0.80 0.1 0.20 0.06],'String',{'tail'},'LineStyle','none');
annotation('textbox',[0.55 0.1 0.20 0.06],'String',{'body'},'LineStyle','none');
annotation('textbox',[0.30 0.1 0.20 0.06],'String',{'head'},'LineStyle','none');
annotation('textbox',[0.18 0.1 0.20 0.06],'String',{'uncus'},'LineStyle','none');
annotation('textbox',[0.115 0.15 0.20 0.06],'String',{sprintf('vert.\nunc.')},'LineStyle','none');

end