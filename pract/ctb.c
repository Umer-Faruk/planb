#include<stdio.h>
#include<gd.h>
#include<omp.h>

void main(){

     char *inf = "a1.png";
     char *otf = "out.png";

     int color;

     FILE *fp;

     fp = fopen(inf,"r");

     int comb = 1;

     gdImagePtr img = gdImageCreateFromPng(fp);

     int w= gdImageSX(img);
     int h = gdImageSY(img);
     
     #pragma omp parallel for private(color)
     for(int i=0;i<w;i++){
          for(int j=0;j<h;j++){
               
               color = gdImageGetPixel(img,i,j);
               comb = 0.3*gdImageRed(img,color)+0.5*gdImageGreen(img,color)+0.11*gdImageBlue(img,color);
               color = gdImageColorAllocate(img,comb,comb,comb);
               gdImageSetPixel(img,i,j,color);
          }
     }

     fp = fopen(otf,"w");

     gdImagePng(img,fp);
     gdImageDestroy(img);
     fclose(fp);


}