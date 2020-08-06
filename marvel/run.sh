#!/usr/bin/env bash

clear
g++ -O3 -o quick.out main.cc -std=c++17 && ./quick.out < 0.in && rm quick.out
