# HippUnfolding

This provides all the tools to use Laplace's equation to computationally 'unfold' the grey matter of the hippocmapus. Note that at this stage the unfolding must be initialized using manual segmentations that separate the different 'folds' of hippocampal grey matter via the dark band, and extra-hippocampal structures must be delineated to mark boundary conditions  (see reference below + supplementary materials).

Before using, MEX the laplace_iters.m file (new filename laplace_iters_mex). Depending on your build, this may already work but otherwise can be easily re-done using the provided .prj file in the MATLAB coder (follow default instructions).

Test it out on the example data using the command:

Laplace_unfold('example/EPI_V073.segmentation.rHPC.nii.gz')
plot_UnfoldedSpace('example/EPI_V073.segmentation.rHPC_Unfolded', 'example/EPI_V073.T1overT2.cropped.nii.gz')

Laplace_unfold should produce a subfolder with a data.mat file containing all variables of interest.

plot_UnfoldedSpace shows an example of how the gradients stored in data.mat can be used to index and map intensities from an MRimage (in the same space as the segmentation image), shown here for various linear interpolations between the native and unfolded spaces.

Avg_borders.mat contains the unfolded coordinates of each subfield border, averaged across a set of 8 manual segmentations used in the current study.

DeKraker, J., Ferko, K. M., Lau, J. C., Köhler, S., & Khan, A. R. (2017). Unfolding the hippocampus: An intrinsic coordinate system for subfield segmentations and quantitative mapping. bioRxiv, 146878.
bioRxiv 146878; doi: https://doi.org/10.1101/146878

