all: main run

run: main
	./main

main: main.c
	cc -g3 main.c -o main
