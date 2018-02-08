function out = plot_UnfoldedSpace(unfolded_fn,MRimage)
% finds and plots the MRimage intensities at each A-P and P-D coordinate.
% includes average borders from current study, and rescales the
% image according to average real world size from the current study.

load('avg_borders.mat')
SEM_borders = stdev_borders./sqrt(size(borders,3));

load([unfolded_fn '/data.mat']);
MRdata = load_untouch_nii(MRimage);
MRdata = double(MRdata.img);

% crop (already done in the example image loaded here)
% MRdata = zeros(size(labelmap));
% MRdata(:) = MRdata(cropping==1);

% if left, flip on sagittal (z plane, or the third dimension in this matrix)
if isleft
    MRdata = flipdim(MRdata,3);
end


%% match indices
sz = size(MRdata);

u=Laplace_AP;
v=Laplace_PD;
w=Laplace_IO;
[x,y,z]=ind2sub(sz,idxgm);
c = nan(size(x));
for i = 1:length(x)
    c(i) = MRdata(x(i),y(i),z(i));
end
clear MRdata %save memory
thresh(1) = mean(c) + 4*std(c); thresh(2) = mean(c) - 4*std(c);
c(c>thresh(1)) = thresh(1); c(c<thresh(2)) = thresh(2);

%% set parameters

interp='linear';
extrap='none';
APres = 100;
PDres = 100;
thickres = -4;
Nu=ceil(u*APres);
Nv=ceil(v*PDres);
Nw=ceil(w*thickres);


%% plot!
nSubPlots = 4;

v1 = linspace(45,0,nSubPlots);
v2 = linspace(45,90,nSubPlots);

figure('units','normalized','outerposition',[0 0 1 1]); 
lin = linspace(0,1,nSubPlots);
for n = 1:nSubPlots
    i = lin(n);
    j = 1-i;
    subplot(floor(sqrt(nSubPlots)),ceil(sqrt(nSubPlots)),n);
    scatter3(Nu*i + x*j, Nv*i + y*j, Nw*i + z*j,48,c,'.');
    axis equal; h = colorbar; ylabel(h, 'MR T1 over T2 (a.u.)');
    colormap('jet'); view(v1(n),v2(n))
    if n == 1
        title('Native space');
        xlabel('x');
        ylabel('y');
        zlabel('z');
    elseif n ==nSubPlots
        title('Unfolded space');
        xlabel('Anterior - Posterior (%)');
        ylabel('Proximal - Distal (%)');
        zlabel('laminar');
    else
        title(num2str(n));
    end
end
hold on;

% overlay data from manual segmentations & other annotations
% note positions set up for nSubPlots = 9
for b = 1:4
    by = avg_borders(:,b);
    bx = [1:APres]';
    plot(by,'k');
    dy = SEM_borders(:,b);
    fill([bx;flipud(bx)],[by-dy;flipud(by+dy)],[0 0 0],'FaceAlpha', 0.3,'linestyle','none');
end
bx = [5 18]; by = [1,100]; plot(bx,by,'--k'); %vertical component
bx = [20 28]; by = [1,100]; plot(bx,by,'--k'); %uncus
bx = [36 40]; by = [1,100]; plot(bx,by,'--k'); %head
bx = [84 80]; by = [1,100]; plot(bx,by,'--k'); %tail
a = gca;
a = a.Position;
annotation('textbox',[a(1:2)+([0.45 0.00].*a(3:4)) [0.08 0.06]],'String',{'Sub'},'LineStyle','none','FontWeight','bold');
annotation('textbox',[a(1:2)+([0.45 0.35].*a(3:4)) [0.08 0.06]],'String',{'CA1'},'LineStyle','none','FontWeight','bold');
annotation('textbox',[a(1:2)+([0.45 0.60].*a(3:4)) [0.08 0.06]],'String',{'CA2'},'LineStyle','none','FontWeight','bold');
annotation('textbox',[a(1:2)+([0.45 0.72].*a(3:4)) [0.08 0.06]],'String',{'CA3'},'LineStyle','none','FontWeight','bold');
annotation('textbox',[a(1:2)+([0.43 0.82].*a(3:4)) [0.08 0.06]],'String',{'CA4&DG'},'LineStyle','none','FontWeight','bold');

annotation('textbox',[a(1:2)+([0.8 -0.10].*a(3:4)) [0.08 0.06]],'String',{'tail'},'LineStyle','none');
annotation('textbox',[a(1:2)+([0.50 -0.10].*a(3:4)) [0.08 0.06]],'String',{'body'},'LineStyle','none');
annotation('textbox',[a(1:2)+([0.24 -0.10].*a(3:4)) [0.08 0.06]],'String',{'head'},'LineStyle','none');
annotation('textbox',[a(1:2)+([0.10 -0.10].*a(3:4)) [0.08 0.06]],'String',{'uncus'},'LineStyle','none');
annotation('textbox',[a(1:2)+([0.03 -0.00].*a(3:4)) [0.08 0.06]],'String',{sprintf('vert.\nunc.')},'LineStyle','none');

end