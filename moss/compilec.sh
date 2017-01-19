#!/bin/bash

gcc -Wall -Werror -std=gnu99 $1 -o run

echo "Compiled successfully!"

./run.exe
