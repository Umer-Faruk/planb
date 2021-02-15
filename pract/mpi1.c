#include<stdio.h>
#include<mpi.h>
#include<stdlib.h>

void main(int argc , char* argv[]){
      
      int rank;
      MPI_Init(&argc,&argv);
      MPI_Comm_rank(MPI_COMM_WORLD,&rank);
      MPI_Status status;

      if(rank == 0){
           int x=10;

           MPI_Send(&x,1,MPI_INT,1,1,MPI_COMM_WORLD);
      }
      else if(rank == 1){
           int y;
           MPI_Recv(&y,1,MPI_INT,0,1,MPI_COMM_WORLD,&status);
           printf("%d receive \n",y);
      }
      MPI_Finalize();
}


