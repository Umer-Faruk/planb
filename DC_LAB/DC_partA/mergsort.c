#include<omp.h>
#include<stdio.h>
#include<stdlib.h>


void merge(int a[] , int x1 , int y1 , int x2 , int y2)
{
    int p = x1, q = x2, k = 0, temp[1000],i,j;
    while(p <= y1 && q <= y2 ){
        if(a[p] < a[q])
            temp[k++] = a[p++];
        else
            temp[k++] = a[q++];
    }

    while( p <= y1 )
        temp[k++] = a[p++];
    
    while( q <= y2 )
        temp[k++] = a[q++];

    for(i = x1 , j = 0; i <= y2; i++,j++ )
        a[i] = temp[j];
}

void margesort(int a[], int s, int e)
{
     int mid =0;
     if(s < e)
     {
          mid = (s+e)/2;

          #pragma omp parallel sections 
          
          {
               #pragma omp section
               {
                    margesort(a,s,mid);
               }
               #pragma omp section
               {
                    margesort(a,mid+1,e);
               }
          }

          merge(a,s,mid,mid+1,e);
     }
}

void main()
{
     int a [10] = {5,47,9,87,3,57,7,9,3,6};
     int n =10;
     int i=0;
     for(i = 0 ;i < n;i++){
          printf("%d \t",a[i]);
     }
     margesort(a,0,n-1);
     printf("after sorting \n");

     for(i = 0 ;i < n;i++){
          printf("%d \t",a[i]);
     }
}