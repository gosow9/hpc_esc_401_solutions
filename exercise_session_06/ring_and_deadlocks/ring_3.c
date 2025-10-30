#include "mpi.h"
#include <stdio.h>

int main(int argc, char** argv) {
    // Initialize the MPI environment
    MPI_Init(&argc, &argv);

    int world_size, world_rank;
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    // Create 1D cartesian communicator with periodic boundary (ring)
    MPI_Comm cart;
    int ndims = 1;
    int dims[1] = { world_size };
    int periods[1] = { 1 };  // cyclic
    int reorder = 1;
    MPI_Cart_create(MPI_COMM_WORLD, ndims, dims, periods, reorder, &cart);

    int size, my_rank;
    MPI_Comm_size(cart, &size);
    MPI_Comm_rank(cart, &my_rank);

    // Compute the ranks of left/right neighbours 
    int left_rank, right_rank;
    MPI_Cart_shift(cart, 0, 1, &left_rank, &right_rank);

    int my_sum = 0;
    int send_rank = my_rank;
    int recv_rank = -1;

    for (int i = 0; i < size; ++i) {
        MPI_Request reqs[2];
        MPI_Irecv(&recv_rank, 1, MPI_INT, left_rank,  i, cart, &reqs[0]);
        MPI_Isend(&send_rank, 1, MPI_INT, right_rank, i, cart, &reqs[1]);
        MPI_Status sts[2];
        MPI_Waitall(2, reqs, sts);

        my_sum += recv_rank;
        send_rank = recv_rank;
    }

    printf("I am processor %d out of %d, and the sum is %d\n", my_rank, size, my_sum);

    MPI_Comm_free(&cart);
    MPI_Finalize();
    return 0;
}
