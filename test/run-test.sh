#!/bin/bash
dir=$(dirname ${BASH_SOURCE[0]})
gcc $dir/../src/mines.c $dir/test_mines.c $dir/Unity/src/unity.c -o $dir/test.out && $dir/test.out
