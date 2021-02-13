
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
int prim[100];
void main(){
     int k=0;
     int n=10;
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
 
     printf("sin table\n");
     for(int i=0;i<=n;i++){
          printf("%f\n",sin(i*M_PI/180));
     }
}