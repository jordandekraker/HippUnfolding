# HippUnfolding

This provides all the tools to use Laplace's equation to computationally 'unfold' the grey matter of the hippocmapus. Note that the unfolding must be initialized using manual segmentations that separate the different 'folds' of hippocampal grey matter via the dark band, and extra-hippocampal structures must be delineated to mark boundary conditions  (see reference below + supplementary materials).

Before using, MEX the laplace_iters.m file (new filename laplace_iters_mex). Depending on your build, this may already work but otherwise can be easily re-done using the provided .prj file in the MATLAB coder (follow default instructions).

Test it out in MATLAB on the example data using the command from the /Laplace_unfolding directory:
>> Laplace_unfold('example/manual_masks/sub-073/anat/sub-073_T2w_space-T1w_hemi-R_label-HippUnfold_roi.nii.gz','example/HippUnfold');

or from terminal (using MATLAB runtime compiler) using:
>> MCC/HippUnfold/for_redistribution_files_only/run_HippUnfold.sh /usr/local/MATLAB/MATLAB_Runtime/v92 'example/manual_masks/sub-073/anat/sub-073_T2w_space-T1w_hemi-R_label-HippUnfold_roi.nii.gz' 'example/HippUnfold',
where </usr/local/MATLAB/MATLAB_Runtime/v92> is replaced by your local MATLAB_Runtime installation (free to download without MATLAB lisence).

If a T2w image is in the BIDS sourcedata directory, this will open a matlab window displaying each hippocampal voxels' T2 weight in native and unfolded space. Otherwise, you should be able to view binned nifty images for each gradient in the output folder. 
If using ITKsnap, apply a 'jet' colorscheme for better visualization by opening the labelviewer and go Actions > Import Label Descriptions > select 'misc/itksnapLabelDescription_Jet20.txt'. Non-binned gradients and other variables of interest will be stored in the _data.mat file.


DeKraker, J., Ferko, K. M., Lau, J. C., Köhler, S., & Khan, A. R. (2018). Unfolding the hippocampus: An intrinsic coordinate system for subfield segmentations and quantitative mapping. NeuroImage, 167, 408-418.
bioRxiv 146878; doi: https://doi.org/10.1101/146878

