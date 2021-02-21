# MakeFile для компиляции моего вектора

# переменная всавте свой компилятор

CC=g++

# флаги передачи компилятору

CFFLAGS=-c -Wall

all: prog

prog: main.o Vector.o
	$(CC) main.o Vector.o -o prog

main.o: main.cpp
	$(CC) $(CFFLAGS) main.cpp

Vector.o: Vector.cpp
	$(CC) $(CFFLAGS) Vector.cpp

clear:
	rm -rf *.o prog