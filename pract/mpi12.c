#include<stdio.h>
#include<stdlib.h>
#include<mpi.h>

int f(int i){
     return i*i;
}


int search(int a,int b,int c,int rank,int size){

     int fi;

     for(int i=a+rank;0<i&&i<=b;i+=size){
          fi=f(i);

          if(fi == c){
               printf("%d proces ",rank);
               return 1;
               
          }

     }
     return 0;
}



void main(int argc,char* argv[]){
     
     int rank,j,size;

     MPI_Init(&argc,&argv);
     MPI_Comm_rank(MPI_COMM_WORLD,&rank);
     MPI_Comm_size(MPI_COMM_WORLD,&size);

     int a=1,b=10000000,c=25;

     // if(rank==0){
     //      printf("A=%d,\tB=%d,\tC=%d\n",a,b,c);
     // }

     if(search(a,b,c,rank,size)){
          printf("integer found\n");
     }
     else{
          printf("integer not found ####\n");
     }

     MPI_Finalize();
}