#include <iostream>
#include "mpi.h"

int main()
{
    MPI_Init(NULL, NULL);
    int rank, size;
    MPI_Comm_size(MPI_COMM_WORLD, &size);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    printf("%d %d", rank, size);
    MPI_Finalize();
    return 0;
}

