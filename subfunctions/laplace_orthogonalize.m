% This function modifies the AP laplace solution in order to make it more
% closely orthogonal to the PD laplace gradient. Thus, the two gradients
% will cover all of unfolded space. The modified AP gradient is still
% laplacian, but has modified boundary conditions that span all the way to
% the PD boundary conditions (thus you might think of this function as
% correcting for error in the manual segmentation of boundary conditions
% labels). 

% In short this is done by extending the AP source
% and sink by finding the edge points in the AP direction of current
% unfolded space, and then applying more iterations of the averaging filter
% using those edge points as an (extended) source and sink.
% In order to make that process faster, I also stretch the AP gradient to
% cover the whole unfolded space, but limit this stretching only to the
% areas near the endpoints using weighted averaging, with weights
% determined from a gaussian kernel. The product of this is not smooth
% though, so I apply additional averaging filters suing the new source &
% sink as well.

% inputs: 
% 
% AP_laplace and PD_laplace: non-discretized gradients (3D or
% indexed; if indexed include sz,idx) 
% res (optional): the resolution (or scaling) at which to define the edges
% of original unfolded space. Defaut is 100, but higher values may improve
% results for very high resolution data.
% sz (only if AP_laplace and PD_laplace are given in indices): size
% of original 3D matrix 
% idx (only if AP_laplace and PD_laplace are given in indices): index of
% laplacian domain within original 3D matrix

function AP_laplace_modified = laplace_orthogonalize(AP_laplace,PD_laplace,res,sz,idx)

if (~exist('res','var') | isempty(res))
    res = 100;
end
if ~exist('sz','var') & ~exist('idx','var')
    sz = size(AP_laplace);
    idx = (AP_laplace>0 & PD_laplace>0);
    
    AP_laplace = AP_laplace(idx);
    PD_laplace = PD_laplace(idx);
end

AP_laplace = AP_laplace*res; PD_laplace = PD_laplace*res;

%%
% stretch unfolded space linearly in each row; get edge points (will be
% used for source/sink later)


AP_laplace_modified = AP_laplace;
edges = zeros(size(AP_laplace));
for PD = 1:res-1
    row = AP_laplace(PD_laplace>=PD & PD_laplace<PD+1);
    if ~isempty(row)
        
        [minAP,i] = min(row); [maxAP,j] = max(row);
        t = zeros(size(row)); t(i) = 1; t(j) = 2;
        row = (row-minAP) * (res/(maxAP-minAP));
        
        AP_laplace_modified(PD_laplace>=PD & PD_laplace<PD+1) = row;
        edges(PD_laplace>=PD & PD_laplace<PD+1) = t;
    end
end
source = zeros(sz);
source(idx(edges==1)) = 1;
sink = zeros(sz);
sink(idx(edges==2)) = 1;

hl=strel('sphere',5);
gm = zeros(sz); gm(idx) = 1;
source = imdilate(source==1,hl) & ~(gm);
sink = imdilate(sink==1,hl) & ~(gm);

AP_laplace_modified(AP_laplace_modified>=100) = 99.9999;
AP_laplace_modified(AP_laplace_modified==0) = 0.0001;

%     figure; scatter(AP_laplace_modified,PD_laplace,[],'.');


%%
% compine AP_laplace_modified and AP_laplace using weighted mean to
% limit the stretching to areas near edgepoints. Note: this step is
% optional; reduces required iterations for next step
sigma = res/10; offset = 1;

x = 1:res;
y1 = gaussmf(x,[sigma,1+offset]); y2 = gaussmf(x,[sigma,res-offset]);
weights = y1+y2; weights(1:1+offset) = 1; weights(res-offset:res) = 1;
% figure; plot(x,weights);

for n = 1:length(AP_laplace)
    w1 = weights(ceil(AP_laplace_modified(n)));
    w2 = 1-w1;
    AP_laplace_modified(n) = w2*AP_laplace(n) + w1*AP_laplace_modified(n);
end

%     figure; scatter(AP_laplace_modified,PD_laplace,[],'.');
% note I originally thought this would be good enough, since it fully
% spans unfolded space. However, the modified gradient is not very
% smooth in native space.

%%
% apply n more laplace_iters, using boundary conditions from
% the places that used to be edgepoints of unfolded space

n = 100;

%return to 0-1 range
AP_laplace_modified = AP_laplace_modified/res;
PD_laplace = PD_laplace/res;
AP_laplace = AP_laplace/res;

AP_laplace_modified = laplace_solver(idx,source,sink,n,AP_laplace_modified,sz);

%     figure; scatter(AP_laplace_modified,PD_laplace,[],'.');

end