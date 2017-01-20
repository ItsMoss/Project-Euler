#!/bin/bash

g++ -Wall -Werror -std=gnu++98 $1 -o run

echo "Compiled successfully!"

./run.exe
