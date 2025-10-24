CFLAGS = -O3 -ffast-math -mavx2 -fopenmp
CC = g++ 

all: init.o io.o jacobi.o main

init.o: init.cpp init.h
	$(CC) $(CFLAGS) -c init.cpp

io.o: io.cpp io.h
	$(CC) $(CFLAGS) -c io.cpp

jacobi.o: jacobi.cpp jacobi.h
	$(CC) $(CFLAGS) -c jacobi.cpp

main: init.o io.o jacobi.o main.cpp
	$(CC) $(CFLAGS) -o main main.cpp init.o io.o jacobi.o

clean:
	rm -f main init.o io.o jacobi.o

