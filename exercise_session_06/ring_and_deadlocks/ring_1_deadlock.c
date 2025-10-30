#include "mpi.h"
#include <stdio.h>

int main(int argc, char** argv) {
    MPI_Init(&argc, &argv);

    int size, my_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int my_sum = 0;
    int send_rank = my_rank;
    int recv_rank = -1;

    int left_rank = (my_rank - 1 + size) % size;
    int right_rank = (my_rank + 1) % size;

    // INTENTIONALLY WRONG/DEADLOCK-PRONE VERSION:
    // Everyone Ssend first, then Recv: circular wait for >=2 ranks.
    for (int i = 0; i < size; ++i) {
        MPI_Ssend(&send_rank, 1, MPI_INT, right_rank, i, MPI_COMM_WORLD);
        MPI_Recv(&recv_rank, 1, MPI_INT, left_rank,  i, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        my_sum += recv_rank;
        send_rank = recv_rank;
    }

    printf("I am processor %d out of %d, and the sum is %d\n", my_rank, size, my_sum);

    MPI_Finalize();
    return 0;
}
