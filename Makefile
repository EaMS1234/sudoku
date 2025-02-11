all: build run

board.a:
	gcc -c src/board/board.c -o board.o
	ar rs board.a board.o

build: board.a
	gcc src/main.c board.a -l raylib -o sudoku

run: build
	./sudoku
