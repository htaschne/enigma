#!/usr/bin/env bash

# c++ command:
# g++ -std=c++17 -O3 alt.cc && ./a.out < 0.in 20 && rm a.out
gcc main.c -O3 && cat 0.in | ./a.out 0.in 20 && rm a.out
