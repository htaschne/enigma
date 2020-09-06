#!/usr/bin/env bash

gcc -O3 regex.c && ./a.out < input.1 && rm a.out
