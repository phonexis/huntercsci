main: main.o funcs.o
	g++ -o main main.o funcs.o

main.o: main.cpp funcs.cpp
	g++ -c main.cpp

funcs.0: funcs.cpp funcs.h

test: test.o funcs.o
	g++ -o test test.o funcs.o

test.o: test.cpp
	g++ -c test.cpp

clean:
	rm -f funcs.o main.o test.o
