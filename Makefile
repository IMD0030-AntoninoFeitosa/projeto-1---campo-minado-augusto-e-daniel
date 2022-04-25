all: compile execc

compile:
	g++ -c src/main.cpp
	g++ -c src/minesweeper.cpp
	g++ main.o minesweeper.o
	rm *.o
exec:
	./a.out
execc:
	./a.out
	rm *.out