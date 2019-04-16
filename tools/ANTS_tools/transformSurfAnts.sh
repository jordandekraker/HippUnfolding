#!/bin/bash

#this requires neuroglia-helpers 

in_surf_dir=$1
in_ants_dir=$2
out_surf_dir=$3

if [ "$#" -lt 3 ]
then
	 echo "Usage: $0 <in_surf_dir> <in_ants_warp_dir> <out_surf_dir>"
	 exit 1
 fi

mkdir -p $out_surf_dir

#apply to all points
for surf in `ls $in_surf_dir/*_polydata.vtk`
do

vert_csv=${surf%%_polydata.vtk}_vertices.csv
tri_csv=${surf%%_polydata.vtk}_tri.csv

file_prefix=${surf##*/}
file_prefix=${file_prefix%_polydata.vtk}

warped_vert_csv=$out_surf_dir/${file_prefix}_warped_vertices.csv
warped_vtk=$out_surf_dir/${file_prefix}_warped_polydata.vtk
warped_template=$out_surf_dir/template_warped.nii.gz

if [ ! -e $warped_vert_csv ]
then	
neuroglia	antsApplyTransformsToPoints \
            -d 3 \
	    -i $vert_csv\
	    -o $warped_vert_csv\
	    -t $in_ants_dir/ants_1Warp.nii.gz  \
	    -t $in_ants_dir/ants_0GenericAffine.mat 
fi



if [ ! -e $warped_vtk ]
then
echo "csvToVTK('$warped_vert_csv','$tri_csv','$warped_vtk')" |  matlab  
fi

done

