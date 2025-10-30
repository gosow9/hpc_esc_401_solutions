#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include "mpi.h"

/* Default steps can override via argv[1] */
static unsigned long long nSteps = 3000000000ULL;
static const double PI_REF =3.14159265358979323846;

static double getTime(void) {
    struct timeval tv;
    struct timezone tz;
    gettimeofday(&tv, &tz);
    return tv.tv_sec + 1e-6 * (double)tv.tv_usec;
}

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int nProcs = 0, myRank = 0;
    MPI_Comm_size(MPI_COMM_WORLD, &nProcs);
    MPI_Comm_rank(MPI_COMM_WORLD, &myRank);

    if (argc >= 2) {
        char *endp = NULL;
        unsigned long long tmp = strtoull(argv[1], &endp, 10);
        if (endp && *endp == '\0' && tmp > 0ULL) nSteps = tmp;
    }

    const double h = 1.0 / (double)nSteps;
    double sum = 0.0, mypi = 0.0, pi = 0.0;

    double tStart = getTime();

    /* Strided distribution: i = myRank, myRank + nProcs, ... */
    for (unsigned long long i = (unsigned long long)myRank; i < nSteps; i += (unsigned long long)nProcs) {
        const double x = h * ((double)i + 0.5);
        sum += 4.0 / (1.0 + x * x);
    }
    mypi = h * sum;

    /* Send partial to master (rank 0) */
    MPI_Reduce(&mypi, &pi, 1, MPI_DOUBLE, MPI_SUM, 0, MPI_COMM_WORLD);

    if (myRank == 0) {
        const double tElapsed = getTime() - tStart;
        const double err = pi - PI_REF;
        printf("nSteps=%llu, ranks=%d\n", (unsigned long long)nSteps, nProcs);
        printf("pi ≈ %.16f, error = %.16e\n", pi, err);
        printf("time = %.4f s\n", tElapsed);
    }

    MPI_Finalize();
    return 0;
}

