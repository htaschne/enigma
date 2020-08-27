#!/usr/bin/env bash
# python3 7.py < 7.1
g++ 7.cc -O3 -std=c++17 && ./a.out < 7.1 && rm a.out
