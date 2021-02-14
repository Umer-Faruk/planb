#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int a[4][4], b[4][4],c[4][4];

void main(int argc,char* argv[]){


     int rank,size;
     int n=4;

     MPI_Init(&argc,&argv);
     MPI_Comm_rank(MPI_COMM_WORLD,&rank);
     MPI_Comm_size(MPI_COMM_WORLD,&size);

     if(rank == 0){
          for(int i=0;i<n;i++){
               for(int j=0;j<n;j++){
                    a[i][j]=1;
                    b[i][j]=2;
               }
          }
     }
}