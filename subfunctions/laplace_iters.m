function [LP, iter_change] = laplace_iters(source,sink,init,maxiters)

change_threshold = 10^(-3);

% iterative averaging filter to solve Laplace equation with greater
% accuracy than initial fast-marching
fg = (init(:)>=0);

% %filter set-up (26 nearest neighbours)
% hl=ones(3,3,3);
% nelem=numel(hl);
% hl=hl./nelem;
% hl=hl+hl(2,2,2)./(nelem-1); hl(2,2,2)=0;

% filter set-up (6 NN) (safer, especially in cases of coronal non-oblique
% where dark band is more likely to 'peak' through across diagonals
hl = strel('sphere',1);
hl = double(hl.Neighborhood);


bg=(~source & ~sink & isnan(init));

%set up vel
vel=init; %geodist to initialize greymatter
vel(source)=0;
vel(sink)=1;
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