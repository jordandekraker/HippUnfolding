# HippUnfolding

This provides all the tools to use Laplace's equation to computationally 'unfold' the grey matter of the hippocmapus. Note that the unfolding must be initialized using manual segmentations that separate the different 'folds' of hippocampal grey matter via the dark band, and extra-hippocampal structures must be delineated to mark boundary conditions  (see reference below + supplementary materials).

Before using, MEX the laplace_iters.m file (new filename laplace_iters_mex). Depending on your build, this may already work but otherwise can be easily re-done using the provided .prj file in the MATLAB coder (follow default instructions).

Test it out in MATLAB on the example data using the command from the /Laplace_unfolding directory:
> Laplace_unfold('example/manual_masks','example/HippUnfold','example/CoronalOblique0.3mm');

If using ITKsnap, apply a 'jet' colorscheme for better visualization by opening the labelviewer and go Actions > Import Label Descriptions > select 'misc/itksnapLabelDescription_Jet20.txt'. 


DeKraker, J., Ferko, K. M., Lau, J. C., Köhler, S., & Khan, A. R. (2018). Unfolding the hippocampus: An intrinsic coordinate system for subfield segmentations and quantitative mapping. NeuroImage, 167, 408-418.
bioRxiv 146878; doi: https://doi.org/10.1101/146878

