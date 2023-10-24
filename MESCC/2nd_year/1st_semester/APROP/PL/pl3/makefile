BIN= init mmult mandel_seq mandel_par mandel blocked_matrix

NUM_THREADS = 4
all: $(BIN)

init:
	mkdir -p bin
	
mmult: src/mmult.c
	gcc -Wall src/mmult.c -o bin/mmult -fopenmp 

mmult_run: mmult
	bin/mmult $(NUM_THREADS)

blocked_matrix: src/blocked_matrix.c
	gcc -Wall src/blocked_matrix.c -o bin/blocked_matrix -fopenmp 

blocked_matrix_run: blocked_matrix
	bin/blocked_matrix $(NUM_THREADS)

mandel: src/mandelbrot.c
	gcc -Wall src/mandelbrot.c -o bin/mandel -fopenmp -lm 

mandel_run: mandel
	bin/mandel $(NUM_THREADS)

quicksort: src/quick_sort.c
	gcc -Wall src/quick_sort.c -o bin/quicksort -fopenmp 

quicksort_run: quicksort
	bin/quicksort $(NUM_THREADS)

bubblesort: src/bubble_sort.c
	gcc -Wall src/bubble_sort.c -o bin/bubblesort -fopenmp 

bubblesort_run: bubblesort
	bin/bubblesort $(NUM_THREADS)
