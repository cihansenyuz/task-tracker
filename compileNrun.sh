#!/bin/bash
rm app 2>/dev/null
clear
g++ -g -std=c++17 main.cpp src/* -I inc/ $1 -o app
./app