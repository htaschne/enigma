#!/usr/bin/env bash

# C version
# gcc -O3 main.c && ./a.out < 0.in
g++ -O3 main.cc && time ./a.out < 0.in
