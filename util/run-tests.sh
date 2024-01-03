#!/bin/bash
dir=$(dirname ${BASH_SOURCE[0]})
testdir="$dir/../test"

base_compile_cmd='gcc'
for file in $dir/../src/*.c; do
    if [[ $file != *main.c ]]; then
        base_compile_cmd="$base_compile_cmd $file"
    fi
done

for file in $testdir/*.c; do
    sanitized_testdir="$(echo $testdir | sed 's/\//\\\//g' | sed 's/\./\\\./g')"
    outfile="$(echo $file | sed "s/$sanitized_testdir/$sanitized_testdir\/bin/" | sed 's/\.c/\.out/')"

    echo -e "\033[32mBuilding tests '$file' to '$outfile'...\033[0m"
    eval "$base_compile_cmd $file $testdir/Unity/src/unity.c -o $outfile"

    if [[ $? != 0 ]]; then
        echo -e "\033[31mFailed building tests for $file, continuing anyway!\033[0m"
    fi
done

echo -e "\033[32mDone\033[0m"

for outfile in $testdir/bin/*.out; do
    echo -e "\033[32mRunning tests in $outfile\033[0m"
    $outfile
done

echo -e "\033[32mDone!\033[0m"
