#!/bin/bash

set -eo pipefail
cflags="-Wall -Wextra -ansi -pedantic"

dir=$(dirname ${BASH_SOURCE[0]})
original=$(pwd)

cd $dir

files=($(ls -A ./*.c))
arr_len="${#files[@]}"

compile_cmd="gcc $cflags -o a.out"
for (( i=0; i<$arr_len; i++ )); do
    file=${files[$i]}
    obj_file=$(echo $file | sed -r 's/\.c$/\.o/')

    gcc $cflags $file -o $obj_file -c
    compile_cmd="$compile_cmd $obj_file"
done

# TODO (GM): Remove
echo $compile_cmd
eval $compile_cmd

cd $original
