# HippUnfolding

This provides all the tools to use Laplace's equation to computationally 'unfold' the grey matter of the hippocmapus. Note that the unfolding must be initialized using manual segmentations that separate the different 'folds' of hippocampal grey matter via the dark band, and extra-hippocampal structures must be delineated to mark boundary conditions  (see reference below + supplementary materials).

Test it out in MATLAB on the example data using the command from the /Laplace_unfolding directory:
> Laplace_unfold_BIDS('example/manual_masks','example/HippUnfold','example/CoronalOblique0.3mm');

# Dependencies

- MCC code is available so everything can be run without a Matlab lisence. This code may not be up-to date. Otherwise:
- MATLAB + Image Processing toolbox
- (Optional) Use the Matlab Coder to improve speed. MEX the laplace_iters.m file by double clicking matlab_src/dependencies/laplace_iters_mex.prj and follow the default instructions.

DeKraker, J., Ferko, K. M., Lau, J. C., Köhler, S., & Khan, A. R. (2018). Unfolding the hippocampus: An intrinsic coordinate system for subfield segmentations and quantitative mapping. NeuroImage, 167, 408-418.
bioRxiv 146878; doi: https://doi.org/10.1101/146878

