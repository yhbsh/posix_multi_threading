all: build run

build: main parallel_array_sum

run: main
	./main

main: main.c
	cc -g3 main.c -o main

parallel_array_sum: parallel_array_sum.c
	cc parallel_array_sum.c -o parallel_array_sum
