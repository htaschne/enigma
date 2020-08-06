#!/usr/bin/env bash

clear
g++ -O3 -o quick.out quick.c && ./quick.out < 0.in && rm quick.out
