 

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <mpi.h>

#define N 1E8
#define d 1E-8

void main (int argc, char* argv[])
{
    int rank, size, error, i, result=0, sum=0;
    double pi=0.0,   x, y;
    
    MPI_Init (&argc, &argv);
    
     
    MPI_Comm_rank (MPI_COMM_WORLD, &rank);
    
     
    MPI_Comm_size (MPI_COMM_WORLD, &size);
    
   
    
    srand((int)time(0));
    
     for (i=rank; i<N; i+=size)
    {
        x=rand()/(RAND_MAX+1.0);
        y=rand()/(RAND_MAX+1.0);
        if(x*x+y*y<1.0)
            result++;
    }
    
     MPI_Reduce(&result, &sum, 1, MPI_INT, MPI_SUM, 0, MPI_COMM_WORLD);
    
     
    //Caculate and print PI
    if (rank==0)
    {
        pi=4*d*sum;
        printf("np=%d;       PI=%f\n   size=%d\n", size, pi,size);
    }
    
    MPI_Finalize();
    
   
}
