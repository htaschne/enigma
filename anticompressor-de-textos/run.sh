#!/usr/bin/env bash

find * | grep '\.txt' | xargs -I % /bin/bash -c 'python3 anticompressor.py %'
