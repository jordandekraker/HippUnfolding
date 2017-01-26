# HippUnfolding
Laplace_unfold.m will perform the entire unfolding. Before using, be sure to follow these steps:

Compile mex code for Fast Marching Toolbox in deps/toolbox_fast_marching_v1.2/toolbox_fast_marching, with compile_mex.m
    
MEX the laplace_iters.m file (new filename laplace_iters_mex). This is not necessary, but speeds things up a lot!

Test it out on the example data using the command:

Laplace_unfold('example/EPI_V073.segmentation.rHPC.nii.gz')

This should produce a subfolder with visualizations of each Laplacian gradient as a Nifti image, as well as a data.mat file containing all variables of interest. 

The plot_UnfoldedSpace.m function will show an example of how the gradients stored in data.mat can be used to index and map intensities from an MRimage (in the same space as the segmentation image). For example, run

plot_UnfoldedSpace('EPI_V073.segmentation.rHPC','EPI_V073.T1overT2.avg4.nii.gz')
