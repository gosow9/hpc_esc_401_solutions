# Use Cray MPI wrapper
CC      ?= cc
CFLAGS  ?= -O3 -Wall -Wextra
LDFLAGS ?=

all: mpi_pi

mpi_pi_integral: mpi_pi.c
	$(CC) $(CFLAGS) -o $@ $< $(LDFLAGS)

clean:
	rm -f mpi_pi

