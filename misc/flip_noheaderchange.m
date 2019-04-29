function out = flip_noheaderchange(filename,dimension)

nii = load_untouch_nii(filename);
nii.img = flipdim(nii.img,dimension);
save_untouch_nii(nii,filename);
