function [LP, iter_change] = laplace_iters(fg,source,sink,init)
% solves Laplace's equation
%
% fg: logical specifying foreground volume
% source: logical specifying source volume
% sink: logical specifying sink volume
% init(optional): foreground values to initialize (reduces iterations)

% LP: solved Laplacian equation values at foreground
% iter_change: sum of changes per iteration. length specifies the number of
% iterations run (stopping condition is set to sum of changes < 0.001%)

% method uses iterative finite-differences approach to obtain solution 
% settings, by using a 26-neighbour average to compute the updated potential 
% field, and terminating when the potential field change is below a specified 
% threshold (sum of changes < 0.001%)

    if nargin < 4
        init = zeros(size(fg))+0.5; %with no other initialization, set entire domain = 0.5
    end
   
    maxiters = 5000;
    total_vol = sum(fg(:)>0);
    change_threshold = total_vol/100000; %change threshold should depend on total volume - greater volumes require more

    %filter set-up (26 nearest neighbours)
    hl=ones(3,3,3);
    nelem=numel(hl);
    hl=hl./nelem;
    hl=hl+hl(2,2,2)./(nelem-1); hl(2,2,2)=0;
    
    bg=(~source & ~sink & ~fg);

    %set up vel
    vel = zeros(size(fg));
    vel(source)=0;
    vel(sink)=1;
    vel(fg)=init(fg); %geodist to initialize greymatter
    vel(bg)=0; %must be insulated after filtering
    iter_change = zeros(1,maxiters);
    
    % apply filter
    iters = 0;
    while iters < maxiters %max iterations
        iters = iters+1;
        
        velup = imfilter(vel,hl,'replicate','conv'); %apply averaging filter
        
        %insulate the grey matter so gradient doesn't pass between folds - 
        %inspired by ndnanfilter
        insulate_correction = imfilter(double(~bg),hl,'replicate','conv');
        velup = velup./insulate_correction;
        velup(bg|source)=0; 
        velup(sink)=1;
        
        %stopping condition
        iter_change(iters) = nansum(abs(vel(fg)-velup(fg))); %compute change from last iteration
        vel = velup;
        if iter_change(iters)<change_threshold 
            break 
        end
    end   
    vel = vel./max(vel(:));
    vel(~fg) = nan;
    LP = vel;
    end