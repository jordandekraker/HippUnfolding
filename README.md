# HippUnfolding


This provides all the tools to use Laplace's equation to computationally 'unfold' the grey matter of the hippocmapus. Note that at this stage the unfolding must be initialized using manual segmentations that separate the different 'folds' of hippocampal grey matter via the dark band, and extra-hippocampal structures must be delineated to mark boundary conditions  (see reference below + supplementary materials).

Before using, be sure to follow these steps:

-Download Nifti_tools toolbox for MATLAB and add to path
-Download toolbox_fast_marching toolbox for MATLAB and add to path
-MEX the laplace_iters.m file (new filename laplace_iters_mex). Depending on your build, this may already work but otherwise can be easily re-done using the provided .prj file in the MATLAB coder.


Test it out on the example data using the command:

Laplace_unfold('example/EPI_V073.segmentation.rHPC.nii.gz')


This should produce a subfolder with visualizations of each Laplacian gradient in Nifti format, as well as a data.mat file containing all variables of interest.



The plot_UnfoldedSpace.m function will show an example of how the gradients stored in data.mat can be used to index and map intensities from an MRimage (in the same space as the segmentation image). For example, run

plot_UnfoldedSpace('example/EPI_V073.segmentation.rHPC_Unfolded', 'example/EPI_V073.T1overT2.cropped.nii.gz')


Avg_borders.mat contains the unfolded coordinates of each subfield border, averaged across a set of 8 manual segmentations used in the current study.


Unfolding the hippocampus: An intrinsic coordinate system for subfield segmentations and quantitative mapping
Jordan DeKraker, Kayla M. Ferko, Jonathan C. Lau, Stefan Köhler, Ali R. Khan
bioRxiv 146878; doi: https://doi.org/10.1101/146878


