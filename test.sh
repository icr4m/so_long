#!/bin/bash

make re

clear

for map in maps/*.ber; do
    valgrind ./so_long "$map"
done
