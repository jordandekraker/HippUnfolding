#!/bin/bash

in_template_nii=$1
in_target_nii=$2
out_dir=$3

if [ "$#" -lt 3 ]
then
	 echo "Usage: $0 <in_ref_seg_nii> <in_floating_seg_nii> <out_dir>  [optional arguments]"
	 echo ""
	 echo " -r cc_radius (default 3)"
	 echo " -N specify custom output filename"
	 echo " -s SyN_stepsize (default 0.1)"
	 echo " -u SyN_updatefieldsigma (default 3)"
	 echo " -t SyN_totalfieldsigma (default 0)"
	 echo " -i interpolation method (Linear, NearestNeighbor"
	 echo ""

	 exit 1
 fi

 shift 3

tp=${in_template_nii##*/} # remove path template
tp=${tp%.nii.gz} # remove extension template
tg=${in_target_nii##*/} # remove path target
tg=${tg%.nii.gz} # remove extension target
out_fn=$tp'_space-'$tg # combine names

convergence="[100x50x50,1e-6,10]"
shrink_factors="4x2x1"
smoothing_sigmas="4x2x1vox"
radiusnbins=3
stepsize=0.1
updatefield=3
totalfield=0
interp=Linear
dim=3
cost=CC

while getopts "r:N:s:u:t:i:" options; do
 case $options in
  r ) echo "CC radius $OPTARG"
	  radiusnbins=$OPTARG;;
  N ) echo "Custom output filename $OPTARG"
	  out_fn=$OPTARG;;
  s ) echo "SyN stepsize $OPTARG"
	  stepsize=$OPTARG;;
  u ) echo "SyN update field sigma $OPTARG"
	  updatefield=$OPTARG;;
  t ) echo "SyN total field sigma $OPTARG"
	  totalfield=$OPTARG;;
  L ) echo "Interpolation $OPTARG"
	  interp=$OPTARG;;
    * ) usage
	exit 1;;
 esac
done



mkdir -p $out_dir


#template is fixed
#target is moving
metric="--metric ${cost}[${in_template_nii},${in_target_nii},1,${radiusnbins}]"
multires="--convergence $convergence --shrink-factors $shrink_factors --smoothing-sigmas $smoothing_sigmas"
rigid="$multires $metric --transform Rigid[0.1]"
affine="$multires $metric --transform Affine[0.1]"
syn="$multires $metric --transform SyN[${stepsize},$updatefield,$totalfield]"

out="--output [$out_dir/ants_$out_fn]"

echo neuroglia antsRegistration -d $dim --interpolation $interp $rigid $affine $syn $out
neuroglia antsRegistration -d $dim --interpolation $interp $rigid $affine $syn $out

