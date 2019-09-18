#!/bin/bash

in_template_nii=$1
in_target_nii=$2
in_template_img=$3
in_target_img=$4
out_dir=$5

if [ "$#" -lt 3 ]
then
	 echo "Usage: $0 <in_ref_seg_nii> <in_floating_seg_nii> <in_ref_img_nii> <in_flo_img_nii> <out_dir>  [optional arguments]"
	 echo ""
	 echo " -r cc_radius (default 3)"
	 echo " -s SyN_stepsize (default 0.1)"
	 echo " -u SyN_updatefieldsigma (default 3)"
	 echo " -t SyN_totalfieldsigma (default 0)"
	 echo " -L \"label1 label2 ...\" (labels to extract, default 1)"
	 echo ""

	 exit 1
 fi

 shift 3

convergence="[100x50x50,1e-6,10]"
shrink_factors="4x2x1"
smoothing_sigmas="4x2x1vox"
radiusnbins=3
stepsize=0.1
updatefield=3
totalfield=0
labellist=1
interp=Linear
dim=3
cost=CC

while getopts "r:s:u:t:L:" options; do
 case $options in
  r ) echo "CC radius $OPTARG"
	  radiusnbins=$OPTARG;;
  s ) echo "SyN stepsize $OPTARG"
	  stepsize=$OPTARG;;
  u ) echo "SyN update field sigma $OPTARG"
	  updatefield=$OPTARG;;
  t ) echo "SyN total field sigma $OPTARG"
	  totalfield=$OPTARG;;
  L ) echo "Extracting labels $OPTARG"
	  labellist=$OPTARG;;
    * ) usage
	exit 1;;
 esac
done



mkdir -p $out_dir


metric=""
for label in $labellist
do
	echo label: $label
	template_bin=$out_dir/template_label-$label.nii.gz
	target_bin=$out_dir/target_label-$label.nii.gz




if [ ! -e $template_bin ]
then
echo fslmaths $in_template_nii -thr $label -uthr $label -bin $template_bin
fslmaths $in_template_nii -thr $label -uthr $label -bin $template_bin
fi

if [ ! -e $target_bin ]
then
echo fslmaths $in_target_nii -thr $label -uthr $label -bin $target_bin
fslmaths $in_target_nii -thr $label -uthr $label -bin $target_bin
fi

#template is fixed
#target is moving
metric="$metric --metric ${cost}[${template_bin},${target_bin},1,${radiusnbins}]"
metric2="$metric --metric ${cost}[${in_template_img},${in_target_img},1,${radiusnbins}]"

done


if [ ! -e $out_dir/ants_1Warp.nii.gz ]
then


multires="--convergence $convergence --shrink-factors $shrink_factors --smoothing-sigmas $smoothing_sigmas"
rigid="$multires $metric $metric2 --transform Rigid[0.1]"
affine="$multires $metric $metric2 --transform Affine[0.1]"
syn="$multires $metric $metric2 --transform SyN[${stepsize},$updatefield,$totalfield]"

out="--output [$out_dir/ants_]"

echo neuroglia antsRegistration -d $dim --interpolation $interp $rigid $affine $syn $out
neuroglia antsRegistration -d $dim --interpolation $interp $rigid $affine $syn $out



fi


for label in $labellist
do
	echo label: $label
	template_bin=$out_dir/template_label-$label.nii.gz
	target_bin=$out_dir/target_label-$label.nii.gz

	warped_target=$out_dir/target_label-${label}_warped.nii.gz
	warped_template=$out_dir/template_label-${label}_warped.nii.gz

if [ ! -e $warped_template ]
then	  
	echo neuroglia antsApplyTransforms \
	    -d 3 \
	    --interpolation NearestNeighbor \
	    -i $template_bin\
	    -o $warped_template\
	    -r $target_bin\
	    -t [$out_dir/ants_0GenericAffine.mat, 1] \
	    -t $out_dir/ants_1InverseWarp.nii.gz 

	neuroglia antsApplyTransforms \
	    -d 3 \
	    --interpolation NearestNeighbor \
	    -i $template_bin\
	    -o $warped_template\
	    -r $target_bin\
	    -t [$out_dir/ants_0GenericAffine.mat, 1] \
	    -t $out_dir/ants_1InverseWarp.nii.gz 

fi

if [ ! -e $warped_target ]
then	  
	echo antsApplyTransforms \
	    -d 3 \
	    --interpolation NearestNeighbor \
	    -i $target_bin\
	    -o $warped_target\
	    -r $template_bin\
	    -t $out_dir/ants_1Warp.nii.gz \
	    -t $out_dir/ants_0GenericAffine.mat # removed affine inversion

	antsApplyTransforms \
	    -d 3 \
	    --interpolation NearestNeighbor \
	    -i $target_bin\
	    -o $warped_target\
	    -r $template_bin\
	    -t $out_dir/ants_1Warp.nii.gz \
	    -t $out_dir/ants_0GenericAffine.mat # removed affine inversion

fi

done


