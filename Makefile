all: build run

build:
	gcc src/main.c -l raylib -o sudoku

run: build
	./sudoku
