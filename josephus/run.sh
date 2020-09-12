#!/usr/bin/env bash

# C version
# g++ -O3 main.cc && time ./a.out < 1.in
gcc -O3 main.c && time ./a.out < input
