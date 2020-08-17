#!/usr/bin/env bash

gcc -O3 comp.c && time ./a.out && rm a.out
