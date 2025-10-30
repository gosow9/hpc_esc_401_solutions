#include "mpi.h"
#include <stdio.h>

int main(int argc, char** argv) {
   // Initialize the MPI environment 
    MPI_Init(&argc, &argv);

    // Get the number of processes and rank of the process
    int size, my_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);

    int my_sum = 0;
    int send_rank = my_rank;
    int recv_rank = -1;

    int left_rank  = (my_rank - 1 + size) % size;
    int right_rank = (my_rank + 1) % size;

    for (int i = 0; i < size; ++i) {
        if (my_rank % 2 == 0) {
            // even: send then receive
            MPI_Ssend(&send_rank, 1, MPI_INT, right_rank, i, MPI_COMM_WORLD);
            MPI_Recv(&recv_rank, 1, MPI_INT, left_rank,  i, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
        } else {
            // odd: receive then send
            MPI_Recv(&recv_rank, 1, MPI_INT, left_rank,  i, MPI_COMM_WORLD, MPI_STATUS_IGNORE);
            MPI_Ssend(&send_rank, 1, MPI_INT, right_rank, i, MPI_COMM_WORLD);
        }
        my_sum += recv_rank;
        send_rank = recv_rank;
    }

    printf("I am processor %d out of %d, and the sum is %d\n", my_rank, size, my_sum);

    // Finalize the MPI environment.
    MPI_Finalize();
    return 0;
}
