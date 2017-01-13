# HippUnfolding
Laplace_unfold.m will perform the entire unfolding. Be sure to MEX the laplace_iters.m file (with filename laplace_iters_mex), otherwise process will be very slow! 
Test it out on the example data using the command:

Laplace_unfold('example/EPI_V073.segmentation.rHPC.nii.gz')

This should produce a subfolder with visualizations of each Laplacian gradient as Nifti images, as well as a data.mat file containing all variables of interest. 

The plot_UnfoldedSpace.m function will show an example of how the gradients stored in data.mat can be used to index and map intensities from an MRimage (in the same space as the segmentation image). For example, run

plot_UnfoldedSpace('EPI_V073.segmentation.rHPC','EPI_V073.T1overT2.avg4.nii.gz')
