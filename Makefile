all: build clean run

board.a:
	gcc -c src/board/board.c -o board.o
	ar rs board.a board.o

sudoku.a:
	gcc -c src/sudoku/sudoku.c -o sudoku.o
	ar rs sudoku.a sudoku.o

build: board.a sudoku.a
	gcc src/main.c board.a sudoku.a -l raylib -o sudoku.out

clean: build
	rm *.a
	rm *.o

run: build
	./sudoku.out
