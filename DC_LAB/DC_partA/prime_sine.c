#include<omp.h>
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int primtable[1000];
double sinetable[1000];

void prime_table(int n){
     int p = 0;
     for(int i = 2;i<=n;i++){
          int c=0;
          for(int j=1;j<=i;j++){
               if((i%j) == 0){
                    c++;
               }
          }
          if(c == 2){
               primtable[p++] = i;
               printf("%d \n",i);
          }
     }

     

}

void sine_table(int n){
     for(int i=0;i<n;i++){
          sinetable[i] = sin(i*M_PI/180);
     }
}

void main(){
     int n=9;
     #pragma omp parallel sections
     {
          printf("prime table\n");
          #pragma omp section
          {
                prime_table(n);
          }
          
         #pragma omp section
         {
               sine_table(n);
         }
    }
     
     printf("sine table\n");

     for(int i = 0;i<n;i++){
         printf("%f\n", sinetable[i]);
     }
}