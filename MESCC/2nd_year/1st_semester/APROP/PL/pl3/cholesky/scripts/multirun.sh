#!/bin/bash
PROGRAM=cholesky

export IFS=";"

# THREADS="01;02;03;04;05;06;07;08;09;10;11;12"
# MSIZES="64;128;256;512;1024;2048"
# BSIZES="2;4;8;16"

# THREADS="02;04;08;12"
# MSIZES="64;256;1024;2048"
# BSIZES="2;4;8;16"
# ITS=10

THREADS="08"
MSIZES="1024;2048"
BSIZES="16"
ITS=1

for MS in $MSIZES; do
  for BS in $BSIZES; do
    for thread in $THREADS; do
      for (( it=1; it<=$ITS; it++ ))
      do
        bin/$PROGRAM $MS $BS $thread >> "$(date +"%Y_%m_%d")_cholesky.csv"
      done
    done
  done
done
