% extend SRLM over the subiculum

% This portion of the code was used in the original publication, but future
% work will define the (dummy label) SRLM over subiculum separately.

%% if left, flip
% if left hippocampus, flip
LR = output(strfind(output,'hemi-')+5);
if LR=='L' && origheader.hdr.dime.pixdim(1)==1
    labelmap = flipdim(labelmap,1); %flip on x (i.e. sagittally)
elseif LR=='R' && origheader.hdr.dime.pixdim(1)==-1
    labelmap = flipdim(labelmap,1); %flip on x (i.e. sagittally)
end
% increasing x moves laterally
% y is coronal
% increasing z moves superior

%%

%find where SRLM borders surface (i.e. medial edge)
se = ones(3,3,3);
SRLMorCystlabels = labeldescription.Var2(contains(cellstr(labeldescription.Var3),'SRLM')...
    | contains(cellstr(labeldescription.Var3),'cyst'));
medial_SRLM = (imdilate(labelmap==0,se) & ismember(labelmap,SRLMorCystlabels));
[xedge,yedge,zedge] = ind2sub(size(labelmap),find(medial_SRLM));

%now for each of those points, walk medially along the border
%of grey matter (unless surpassed max steps or at medial edge or at inferior
%edge)

for a = 1:length(yedge)
    y = yedge(a);
    z = zedge(a);
    x = xedge(a);
    
    steps=0;
    while ((steps < 40) && z<(size(labelmap,3)) && x<(size(labelmap,1)) && x>1 && z>1)
        %choose step direction and make new label
        steps = steps+1;
        if (labelmap(x,y,z-1)==0 || ismember(labelmap(x,y,z-1),SRLMorCystlabels)) %step down -- top priority step direction
            z=z-1;
        elseif (labelmap(x-1,y,z)==0 || ismember(labelmap(x-1,y,z),SRLMorCystlabels)) %step medial
            x=x-1;
        elseif (labelmap(x,y,z+1)==0 || ismember(labelmap(x,y,z+1),SRLMorCystlabels)) %step up -- low priority
            z=z+1;
        elseif (labelmap(x-1,y,z+1)==0 || ismember(labelmap(x-1,y,z+1),SRLMorCystlabels)) %step up-medial in case stuck in a hole
            x=x-1; z=z+1;
        else
            break
        end
        labelmap(x,y,z) = 44; %arbitrarily chosen. just has to not ==0
    end
end
%dilate the result over clear label just to ensure no spots were missed
se = ones(3,3,3);
dil_DB = (imdilate(labelmap==44,se) & labelmap==0);
labelmap(dil_DB) = 44;

%% flip back
% if left hippocampus, flip
LR = output(strfind(output,'hemi-')+5);
if LR=='L' && origheader.hdr.dime.pixdim(1)==1
    labelmap = flipdim(labelmap,1); %flip on x (i.e. sagittally)
elseif LR=='R' && origheader.hdr.dime.pixdim(1)==-1
    labelmap = flipdim(labelmap,1); %flip on x (i.e. sagittally)
end