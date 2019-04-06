% extend SRLM over the subiculum

% This portion of the code was used in the original publication, but future
% work will define the (dummy label) SRLM over subiculum separately.

%UPenn data
labelmap = permute(labelmap,[2 1 3]);
labelmap = flipdim(labelmap,1); 

%% if left, flip
LR = output(strfind(output,'hemi-')+5);
if LR=='L'% && origheader.hdr.dime.pixdim(1)==1
    labelmap = flipdim(labelmap,1); %flip on x (i.e. sagittally)
% elseif LR=='R' && origheader.hdr.dime.pixdim(1)==-1
%     labelmap = flipdim(labelmap,1); %flip on x (i.e. sagittally)
end

%% 'march' infero-medially from SRLM

% increasing x moves laterally
% y is coronal
% increasing z moves superior
se = ones(3,3,3);
labelmap2 = imresize3(labelmap,3,'nearest');
contour1 = imdilate(labelmap2==0,se) & labelmap2==1;
CC = bwconncomp(contour1,6);
for c = 1:length(CC.PixelIdxList)
    le(c) = length(CC.PixelIdxList{c});
end
[le,li] = sort(le,'descend');

Xrlm = zeros(size(labelmap2));
Xrlm(CC.PixelIdxList{li(2)}) = 1; % second largest connected contour area
Xrlm = imdilate(Xrlm,ones(5,5,5));
Xrlm = imresize3(Xrlm,size(labelmap),'nearest');
labelmap(Xrlm==1 & labelmap==0) = 44;
% 
% 
% %find where SRLM borders surface (i.e. medial edge)
% SRLMlabel = labeldescription.Var2(contains(cellstr(labeldescription.Var3),'SRLM'));
% medial_SRLM = (imdilate(labelmap==0,se) & ismember(labelmap,SRLMlabel));
% [xedge,yedge,zedge] = ind2sub(size(labelmap),find(medial_SRLM));
% 
% %now for each of those points, walk medially along the border
% %of grey matter (unless surpassed max steps or at medial edge or at inferior
% %edge)
% 
% walkover_labels = [0; SRLMlabel; 44];
% stopat_labels = [SRLMlabel; 44];
% for a = 1:length(yedge)
%     y = yedge(a);
%     z = zedge(a);
%     x = xedge(a);
%     steps=0;
%     while (z<size(labelmap,3) && x<size(labelmap,1) && x>1 && z>1)
%         %choose step direction and make new label
%         steps = steps+1;
%         if ismember(labelmap(x,y,z-1),walkover_labels) %step down -- top priority step direction
%             z=z-1;
%         elseif ismember(labelmap(x-1,y,z),walkover_labels) %step medial
%             x=x-1;
%         elseif ismember(labelmap(x,y,z+1),walkover_labels) %step up -- low priority
%             z=z+1;
%         elseif ismember(labelmap(x-1,y,z+1),walkover_labels) %step up-medial in case stuck in a hole
%             x=x-1; z=z+1;
%         else
%             break
%         end
%         
%         labelmap(x,y,z) = 44; %arbitrarily chosen. just has to not ==0
%     end
% end
% %dilate the result over clear label just to ensure no spots were missed
% se = ones(3,3,3);
% dil_DB = (imdilate(labelmap==44,se) & labelmap==0);
% labelmap(dil_DB) = 44;

%% flip back
LR = output(strfind(output,'hemi-')+5);
if LR=='L'% && origheader.hdr.dime.pixdim(1)==1
    labelmap = flipdim(labelmap,1); %flip on x (i.e. sagittally)
% elseif LR=='R' && origheader.hdr.dime.pixdim(1)==-1
%     labelmap = flipdim(labelmap,1); %flip on x (i.e. sagittally)
end

%UPenn data
labelmap = flipdim(labelmap,1);
labelmap = permute(labelmap,[2 1 3]);
