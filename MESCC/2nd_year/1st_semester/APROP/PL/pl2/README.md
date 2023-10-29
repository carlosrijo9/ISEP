# Requirements

- GCC compiler and openmp library (should be included in gcc).

- An IDE for programming is recommended (we suggest: VSCode) 

# Setup

Run the following command
```
make init
```
This will simply to create a "bin" folder

## Build
To build the exercises:

```
make mmult
```
or
```
make mandel
```
or
```
make quicksort
```

## Running
To run the exercises:

```
./bin/mmult [num_threads]
```
or
```
./bin/mandel [num_threads]
```
or
```
./bin/quicksort [num_threads]
```
Note that num_threads is optional and will default to the defined DEFAULT_NUM_THREADS

# Excercises
## 1 - Matrix multiplication
STATUS: DONE

TODO: REPORT
## 2 - Area of Mandelbrot Set
STATUS: DONE

TODO: REPORT

## 4 - Quick Sort
REPORT

RESULT NOT AS EXPECTED!!

![Quick Sort - Short Array](/img/quick_short.png "Quick Sort - Short Array")

![Quick Sort - Long Array](/img/quick_long.png "Quick Sort - Long Array")

## 5 - Bubble Sort
REPORT

![Bubble Sort - Short Array](/img/bubble_short.png "Bubble Sort - Short Array")

![Bubble Sort - Long Array](/img/bubble_long.png "Bubble Sort - Long Array")

## 6 - Linked List
REPORT

RESULT NOT AS EXPECTED!!
![Linked List](/img/linked.png "Linked List")