#include<stdlib.h>
#include<stdio.h>
#include<mpi.h>


void main(int argc,char* argv[]){

     int rank;
     double V1[100],V2[100];
     MPI_Init(&argc,&argv);
     MPI_Comm_rank(MPI_COMM_WORLD,&rank);

      
          for(int i=0;i<100;i++){
               V1[i]=2.0;
               V2[i]=1.0;
          }
     
     double mysum = 0.0;

     for(int j=0;j<100;j++){
          mysum += V1[j]*V2[j];
     }

     double allsum;
     printf("\nTask %d partial sum is %f",rank,mysum);


     
     MPI_Reduce(&mysum,&allsum,1,MPI_DOUBLE,MPI_SUM,0,MPI_COMM_WORLD);


      if(rank == 0)
        printf("\nCompleted process : global sum is %f\n",allsum);
    
    MPI_Finalize();





}