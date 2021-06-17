all: txtform clear

txtform: source.o
	g++ source.o -o txtform

source.o: source.cpp
	g++ source.cpp -c

clear:
	rm source.o
