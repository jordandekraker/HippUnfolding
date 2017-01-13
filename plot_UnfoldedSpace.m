function out = plot_UnfoldedSpace(unfolded_fn,MRimage)
% finds and plots the MRimage intensities at each A-P and P-D coordinate.
% includes average borders from current study, and rescales the
% image according to average real world size from the current study.


load([unfolded_fn '_Unfolded/data.mat']);
data = load_untouch_nii(MRimage);
load('SavedVariables.mat')

%crop
cropped_data = zeros(size(labelmap));
cropped_data(:) = data.img(cropping==1);

%if left, flip on sagittal (z plane, or the third dimension in this matrix)
if isleft
    cropped_data = flipdim(cropped_data,3);
end

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

%% warp according to average real world size from current study
warped_flatmap_interp = nan(size(flatmap));
for AP = 1:100
    query = 1/(avg_nvoxels(AP)/100);
    selection = 1:query:100;
    warped_flatmap_interp(1:avg_nvoxels(AP),AP) = interp1(flatmap_interp(:,AP),selection);
end

%% plot!
clims = [min(flatmap_interp(:)) max(flatmap_interp(:))];
figure; hold on;
axis([1 100 1 100]);
a = imagesc(warped_flatmap_interp,clims);
plot(warped_avg_borders,'k');
xlabel('Anterior - Posterior (%)');
ylabel('Proximal - Distal (%)(rescaled to true size)');
title(sprintf([MRimage,'\nintensities in unfolded hippocampal space']));
colormap(jet);
set(a,'alphadata',~isnan(warped_flatmap_interp));

end

