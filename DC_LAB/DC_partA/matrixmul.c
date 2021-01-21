#include<omp.h>
#include<stdio.h>
#include<stdlib.h>

void main(){

     int r=5,c=5,vects=5,i,j;
     int M[r][c],vect[vects],resvect[vects];

     for(i=0;i<r;i++){
          for(j=0;j<c;j++){
               M[i][j] = i+j;
               printf("%d \t",M[i][j]);
          }
          printf("\n");
     }

     for(i =0;i<vects;i++){
          vect[i]=i;
     }
     // omp_set_num_threads(32);
     #pragma omp parallel for 
     for(i=0;i<r;i++){
          for(j=0;j<c;j++){
               resvect[i] =  resvect[i] + M[i][j] * vect[j];
          }
     }


     printf("result\n");
     for(i=0;i<r;i++){
          printf("%d \n",resvect[i]);
     }

}
