se = ones(3,3,3);
labels = unique(labelmap);
% don't remove islands from SRLMorCystlabels
SRLMorCystlabels = labeldescription.Var2(contains(cellstr(labeldescription.Var3),'SRLM')...
    | contains(cellstr(labeldescription.Var3),'cyst'));
for r = 1:length(SRLMorCystlabels)
    labels(labels==SRLMorCystlabels(r)) = [];
end

for l=1:length(labels)
    lbl = labels(l);
    CC = bwconncomp(labelmap==lbl);
    CC.PixelIdxList;
    [~,I] = sort(cellfun(@length,CC.PixelIdxList));
    CC.PixelIdxList = CC.PixelIdxList(I);
    for i =  1:length(CC.PixelIdxList)-1
        tmp = zeros(sz);
        tmp(CC.PixelIdxList{i}) = 1;
        tmp2 = imdilate(tmp,se);
        labelmap(CC.PixelIdxList{i}) = mode(labelmap(tmp2 & ~tmp));
    end
end 