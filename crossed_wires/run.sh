#!/bin/bash

# C version:
# gcc -O3 main.c && ./a.out < input && rm a.out

# C++ version:
g++ wire.cc -O3 -std=c++17 && ./a.out < input && rm a.out

# for part I just change lines 41 and 42, in wire.cc, to:
#   if (w1[pos] < min)
#     min = w1[pos];
