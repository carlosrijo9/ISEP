#!/bin/bash
PROGRAM=cholesky

export IFS=";"

THREADS="01;02;03;04;05;06;07;08;09;10;11;12"
MSIZES="64;128;256;512;1024;2048"
BSIZES="2;4;8;16"
ITS=10
for it in $(seq 1 $ITS)
do
  echo "$it"
  # ./$PROGRAM $MS $BS $thread
done

for MS in $MSIZES; do
  for BS in $BSIZES; do
    for thread in $THREADS; do
      for (( it=1; it<=$ITS; it++ ))
      do
        ./$PROGRAM $MS $BS $thread
      done
    done
  done
done
