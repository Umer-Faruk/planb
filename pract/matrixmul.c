#include<stdio.h>
#include<stdlib.h>
#include<omp.h>


void main(){

     int M[2][2]={{1,4},{4,7}};
     int V[2]={1,1};
     int RV[2];

     #pragma omp parallel for private(V)
     for(int i = 0;i<2;i++){
          for(int j=0;j<2;j++){
               printf("%d \t",M[i][j]);
               RV[i] = RV[i]+M[i][j]*V[j];
          }
          printf("\n");
          
     }

     for(int i=0;i<2;i++){
          printf("%d\n",RV[i]);
     }

      
}