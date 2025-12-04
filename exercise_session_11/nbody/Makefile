# module load cray

nbody	: nbody.cpp Makefile
	CC -O3 -march=native -fopt-info-vec -fopenmp -ffast-math -g -o nbody nbody.cpp

clean:
	rm -f nbody nbody1 nbody2 nbody3
