#!/bin/bash
PROGRAM=cholesky

export IFS=";"

# THREADS="01;02;03;04;05;06;07;08;09;10;11;12"
# MSIZES="64;128;256;512;1024;2048"
# BSIZES="2;4;8;16"

THREADS="08"
MSIZES="1024;2048;4096;8192"
BSIZES="32;64;1024"
ITS=5

for MS in $MSIZES; do
  for BS in $BSIZES; do
    for thread in $THREADS; do
      for (( it=1; it<=$ITS; it++ ))
      do
        bin/$PROGRAM $MS $BS $thread >> "$(date +"%Y-%m-%d_%H")h_cholesky_$MS.csv"
      done
    done
  done
done
