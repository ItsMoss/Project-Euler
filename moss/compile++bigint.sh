#!/bin/bash

g++ -Wall -Werror -std=gnu++98 $1 bigint.o -o run

echo "Compiled successfully!"

./run.exe
