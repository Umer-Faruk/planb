#include<stdio.h>
#include<gd.h>
#include<omp.h>
 

int main(){

     char *infile = "a1.png";
     char *outfile = "o1.png";

     int color ;

     FILE *fp;

     // read input image
     // downlad any color image and rename it is a1.png ans save it in same directry with program
     fp = fopen(infile,"r");
      
     int combined = 1;

     gdImagePtr img = gdImageCreateFromPng(fp);

     int width =  gdImageSX(img);
	int height = gdImageSY(img);

     #pragma omp parallel for private(color)
     for(int x=0;x< width;x++){
          #pragma omp creitical
          for(int y = 0 ; y < height;y++ ){
               color = gdImageGetPixel(img, x, y);
               combined = 0.3*gdImageRed(img, color) + 0.5*gdImageGreen(img,color)+ 0.11*gdImageBlue(img,color);
               color = gdImageColorAllocate(img, combined, combined, combined);
               gdImageSetPixel(img,x,y,color);
          }
     }

     
     
     fp = fopen(outfile,"w");
     
     
     gdImagePng(img,fp);
     gdImageDestroy(img);
     fclose(fp);
     printf("BAW image saved as o1.png");

     return 1;
}