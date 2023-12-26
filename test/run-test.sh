#!/bin/bash
dir=$(dirname ${BASH_SOURCE[0]})

builddir="$dir/bin"
mkdir -p $builddir

base_compile_cmd='gcc'
for file in $dir/../src/*.c; do
    if [[ $file != *main.c ]]; then
        base_compile_cmd="$base_compile_cmd $file"
    fi
done

for file in $dir/*.c; do
    outfile="$builddir/$(echo $file | sed 's/\.c/\.out/')"

    echo -e "\033[32mBuilding tests '$file' to '$outfile'...\033[0m"
    eval "$base_compile_cmd $file $dir/Unity/src/unity.c -o $outfile"

    if [[ $? != 0 ]]; then
        echo -e "\033[31mFailed building tests for $file, continuing anyway!\033[0m"
    fi
done

echo -e "\033[32mDone\033[0m"

for outfile in $builddir/*.out; do
    echo -e "\033[32mRunning tests in $outfile\033[0m"
    ./$outfile
done

echo -e "\033[32mDone!\033[0m"
