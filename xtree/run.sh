#!/usr/bin/env bash

gcc xtree.c -O3 && time ./a.out < casos/casoj13.txt && rm a.out

