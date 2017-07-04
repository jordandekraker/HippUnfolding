function out = extract_hippocampalGM(fn)

load([fn '_Unfolded/data.mat']);

GM = zeros(size(labelmap));
GM(Laplace_AP>=0) = 1;

save_var = orig_labelmap;
if ~isleft
    save_var.img(cropping) = GM;
elseif isleft
    save_var.img(cropping) = flipdim(GM,3);
end
save_fn = sprintf('GM_temp.nii.gz',fn_noFT);
save_untouch_nii(save_var,save_fn);
end
