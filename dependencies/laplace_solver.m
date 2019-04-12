function [LP,iter_change] = laplace_solver(fg,source,sink,maxiters,init,sz)
% solves Laplace's equation
%
% fg: 3D logical OR indices specifying foreground volume
% source: 3D logical OR indices specifying source volume
% sink: 3D logical OR indices specifying sink volume
% maxiters(optional): max finite difference iterations
% init(optional): initialization of fg values (same size as number of fg indices)
% sz(optional): only necessary if using only indices for all above variables.
% Otherwise will be determined from size(<any input that is 3D>)

% LP: solved Laplacian equation values over fg
% iter_change: sum of changes per iteration (from iterative averaging filter)

% implementation first initializes using volumetric fast marching from
% source and sink, then weights and combines the two. Next,
% iterative finite-differences approach to obtain better solution
% settings, by using a 26-neighbour average to compute the updated potential
% field, and terminating when the potential field change is below a specified
% threshold (sum of changes < 0.001%) or a maximum iteration is reached

%% convert logicals to indices, and try to get matrix size
if length(size(fg)) == 3 %is 3D logical
    sz2 = size(fg);
    fg = find(fg==1);
end
if length(size(source)) == 3 %is 3D logical
    sz2 = size(source);
    source = find(source==1);
end
if length(size(sink)) == 3 %is 3D logical
    sz2 = size(sink);
    sink = find(sink==1);
end
if exist('init') == 1 %exists
    if length(size(init)) == 3 %is 3D
        sz2 = size(init);
        init = init(fg);
    end
end

if exist('sz') ~= 1 %doesn't exist
    try
        sz = sz2;
    end
end
if exist('sz') ~= 1 %still doesn't exist
    disp('error must specify matrix size');
    return
end

%% Initialize laplaceian solution with FastMarching (geodist) to save iterations of subsequent Laplace
if exist('init') ~= 1 %doesn't exist
    init = [];
end
if isempty(init)
    
    elems = [1: sz(1)*sz(2)*sz(3)];
    geodist1 = nan(sz); geodist2 = nan(sz); %initialize
    
    % fast march from source
    vel = zeros(sz); %no passing outside
    vel(fg) = 0.5; %medium resistance - optimal path
    vel(source) = 1; %pass easily within source
    [r,c,v] = ind2sub(sz,source); %index of start points
    
    %Fast-march
    geodist1 = perform_fast_marching(vel,[r c v]');
    geodist1(setdiff(elems,fg)) = nan;
    geodist1(geodist1>10000) = nan; %10000 step max
    geodist1 = geodist1/(max(geodist1(:))); %rescale 0 to 1
    
    %fast march from sink
    vel = zeros(sz); %no passing outside
    vel(fg) = 0.5; %medium resistance - optimal path
    vel(sink) = 1; %pass easily within source
    [r,c,v] = ind2sub(sz,sink); %index of start points
    
    %Fast-march
    geodist2 = perform_fast_marching(vel,[r c v]');
    geodist2(setdiff(elems,fg)) = nan;
    geodist2(geodist2>10000) = nan; %10000 step max
    geodist2 = -geodist2/(max(geodist2(:))) +1; %rescale 0 to 1 and invert
    
    % combine the two fast marches
    init = (geodist1.^2 + geodist2.^2).^0.5;
    init = init/max(init(:));
    init = init(fg);
end

%% Now improve the solution finite differences approach:
% interative averaging filter with Neumann boundary condition and fixed
% source/sink values
init(isnan(init)) = 0.5; %guess if there are still any nans! (e.g. from init)
try
    [LP,iter_change] = laplace_iters_mex(fg, source, sink, init, maxiters, sz);
catch
    disp('mex of laplace_iters failed, using non-mex file instead (slower, but will produce the same results). Retry laplace_iters_mex.prj (using MATLAB Coder) for faster results.');
    [LP,iter_change] = laplace_iters(fg, source, sink, init, maxiters, sz);
end
LP = LP(fg);
end
