#include<stdio.h>
#include<omp.h>

void main()
{
     int fact1 = 1,fact2 =1;
     int a=6,i;

     #pragma omp parallel for firstprivate(a)
     // printf("%d\n",a);
     for(i=2;i<=a;i++)
     {
          fact1 = fact1*i;
          printf("%d \n",fact1);
     }
     
     
     printf("with private\n");
     printf("fact1 :%d\n",fact1);

     printf("\n\n");
     #pragma omp parallel for firstprivate(a,fact2)
          // printf("%d\n",a);

     for(i=2;i<=a;i++)
     {
          fact2 = fact2*i;
          printf("%d \n",fact2);
     }
     
     
     printf("with firstprivate\n");
     printf("fact :%d\n",fact2);

}