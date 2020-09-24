#!/usr/bin/env bash

# java version
# javac Main.java && java Main < 0.in

# python version
# python3 reactions.py

g++ -std=c++17 -O3 main.cc && ./a.out < 0.in && rm a.out
