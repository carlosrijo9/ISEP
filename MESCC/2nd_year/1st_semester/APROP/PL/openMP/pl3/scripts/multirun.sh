#!/bin/bash
export IFS=";"

THREADS="01;02;04;08;16"
MSIZES="500;1000;2000;5000"
BSIZES="1;2;5;10;100"
ITS=1

cargo run --release &>/dev/null

for MS in $MSIZES; do
  for BS in $BSIZES; do
    for thread in $THREADS; do
      for ((it = 1; it <= $ITS; it++)); do
        ./bin/mandel $MS $MS $BS $thread >>"$(date +"%Y-%m-%d_%H")h_mandelbrot_$MS.csv"
      done
    done
  done
done
