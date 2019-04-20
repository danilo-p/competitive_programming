#!/bin/bash

g++ -std=c++11 Q$1.cpp && ./a.out < Q$1.in > Q$1.out
# diff Q$1.out Q$1.res.out