all: main run

run: main
	./main

main: main.c
	cc main.c -o main
