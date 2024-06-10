#!/bin/bash

make re

clear

for map in maps/*.ber; do
    ./so_long "$map"
done
