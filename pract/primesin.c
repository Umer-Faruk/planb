
#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#include<math.h>

void prim(int n){
     for(int i=2;i<=n;i++){
          int c=0;
          for(int j=1;j<=i;j++){
               if(i%j == 0){
                    c++;
               }
          }
          if(c == 2){
               printf("%d\n",i);
          }
     }
}

void sinn(int n){

     for(int i=0;i<=n;i++){
          float s = sin(i*M_PI/180);
          printf("%f\n",s);
     }
     
}


void main(){

     int n = 10;
     #pragma omp parallel sections
     {
          #pragma omp section
          prim(n);

          #pragma omp section
          sinn(n);


     }
      
     


     
}