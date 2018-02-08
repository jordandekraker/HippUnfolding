# HippUnfolding

This provides all the tools to use Laplace's equation to computationally 'unfold' the grey matter of the hippocmapus. Note that at this stage the unfolding must be initialized using manual segmentations that separate the different 'folds' of hippocampal grey matter via the dark band, and extra-hippocampal structures must be delineated to mark boundary conditions  (see reference below + supplementary materials).

Before using, MEX the laplace_iters.m file (new filename laplace_iters_mex). Depending on your build, this may already work but otherwise can be easily re-done using the provided .prj file in the MATLAB coder (follow default instructions).

Test it out on the example data using the command:
Laplace_unfold('example/EPI_V073.segmentation.rHPC.nii.gz')

You should be able to view binned nifty images for each gradient in the output folder. If using ITKsnap, open the labelviewer and go Actions > Import Label Descriptions > select 'dependencies/itksnapLabelDescription_Jet20.txt' to apply a 'jet' colorscheme. 

View the T1overT2 MR image in unfolded space using the example below:
plot_UnfoldedSpace('example/EPI_V073.segmentation.rHPC_Unfolded', 'example/EPI_V073.T1overT2.cropped.nii.gz')

Note that these functions are meant to provide a high-level example of how these gradients can be used. They can be visualized in other ways using the 'data.mat' output, and these scripts can be modified for other labelmap schemes or structures of interest.

Avg_borders.mat contains the unfolded coordinates of each subfield border, averaged across a set of 8 manual segmentations used in the current study.

DeKraker, J., Ferko, K. M., Lau, J. C., Köhler, S., & Khan, A. R. (2018). Unfolding the hippocampus: An intrinsic coordinate system for subfield segmentations and quantitative mapping. NeuroImage, 167, 408-418.
bioRxiv 146878; doi: https://doi.org/10.1101/146878

