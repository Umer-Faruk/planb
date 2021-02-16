#include<stdio.h>
#include<stdlib.h>
#include<omp.h>


void main(){

     int M[2][2]={{0,1},{1,2}};

     int V[2]={1,2};

     int RV[2];

     #pragma omp parallel for 
     for(int i = 0;i<2;i++){
          for(int j=0;j<2;j++){
               printf("%d \t",M[i][j]);
               RV[i] = RV[i]+M[i][j]*V[j];
          }
          printf("\n");
          
     }

     printf("Result vector\n");
     for(int i=0;i<2;i++){
          printf("%d\n",RV[i]);
     }

      
}