function [LP,iter_change] = laplace_solver(fg,source,sink,maxiters)
% solves Laplace's equation
%
% fg: logical specifying foreground volume
% source: logical specifying source volume
% sink: logical specifying sink volume
% maxiters: varies depending on distance between source and sink. see
% below (iterative averaging filter)

% LP: solved Laplacian equation values at foreground
% iter_change: sum of changes per iteration (from iterative averaging filter)

% implementation first initializes using volumetric fast marching from
% source and sink, then weights and combines the two. Next, 
% iterative finite-differences approach to obtain better solution 
% settings, by using a 26-neighbour average to compute the updated potential 
% field, and terminating when the potential field change is below a specified 
% threshold (sum of changes < 0.001%) or a maximum iteration is reached

%% Initialize with FastMarching (geodist) to save iterations of subsequent Laplace
% fast march from source
geodist1 = nan(size(fg)); %initialize
geodist2 = nan(size(fg)); %initialize

vel = zeros(size(fg)); %no passing outside
vel(fg) = 0.5; %medium resistance - optimal path
vel(source) = 1; %pass easily within source
[r,c,v] = ind2sub(size(fg),find(source)); %index of start points

%Fast-march
geodist1 = perform_fast_marching(vel,[r c v]');
geodist1(~fg) = nan;
geodist1(geodist1>10000) = nan; %10000 step max
geodist1 = geodist1/(max(geodist1(:))); %rescale 0 to 1

%fast march from sink
vel = zeros(size(fg)); %no passing outside
vel(fg) = 0.5; %medium resistance - optimal path
vel(sink) = 1; %pass easily within source
[r,c,v] = ind2sub(size(fg),find(sink)); %index of start points

%Fast-march
geodist2 = perform_fast_marching(vel,[r c v]');
geodist2(~fg) = nan;
geodist2(geodist2>10000) = nan; %10000 step max
geodist2 = -geodist2/(max(geodist2(:))) +1; %rescale 0 to 1 and invert

% combine the two fast marches
init = nan(size(fg));
init(fg) = 0.5;
init = (geodist1.^2 + geodist2.^2).^0.5;
init = init/max(init(:));
%% Now solve Laplace using (insulated) interative averaging filter
[LP,iter_change] = laplace_iters(source, sink, init, maxiters);

% %% plot or save results
% figure; plot(iter_change);
% figure; imagesc(squeeze(LP(25,:,:)))
% 
% save_var = orig_labelmap;
% if ~isleft
%     save_var.img(cropping) = ceil(LP*20);
% elseif isleft
%     save_var.img(cropping) = flipdim(ceil(LP*20),3);
% end
% save_fn = 'test.nii.gz';
% save_untouch_nii(save_var,save_fn);
