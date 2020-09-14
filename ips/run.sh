#!/usr/bin/env bash

gcc main.c -O3 && cat 0.in | ./a.out 0.in 20 && rm a.out
