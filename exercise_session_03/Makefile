CC = cc
CFLAGS = -O3

all: cpi_omp cpi_mpi sum

gettime.o: gettime.c gettime.h
	$(CC) $(CFLAGS) -c gettime.c

cpi_omp: cpi_omp.c gettime.o
	$(CC) -O0 -fopenmp -o cpi_omp cpi_omp.c gettime.o

cpi_mpi: cpi_mpi.c gettime.o
	$(CC) $(CFLAGS) -o cpi_mpi cpi_mpi.c gettime.o

sum: sum.c gettime.o
	$(CC) -O3 -o sum sum.c gettime.o
clean:
	rm -f sum cpi_omp cpi_mpi *.o

