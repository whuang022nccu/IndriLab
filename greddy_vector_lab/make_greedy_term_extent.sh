#!/bin/bash

OUT=rel
LIBS="-lindri -lz -lpthread -lm"
INCLUDE="/home/whuang022/indri-5.8/include/indri"

LIB=""


g++ -O3 -Wall -DP_NEEDS_GNU_CXX_NAMESPACE=1 greedy_term_extent.cpp\
 -fopenmp -D_GLIBCXX_PARALLEL\
 -march=native\
 -o greedy_vector_termextent_ex /home/whuang022/indri-5.8/obj/libindri.a -I$INCLUDE -L$LIB $LIBS 
