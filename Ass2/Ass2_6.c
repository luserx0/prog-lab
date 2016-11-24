#include "stdio.h"

#define pi 3.1415926535

double cube_area( double n ){
   
   return (6 * n * n);
}

double cube_vol( double n ){
   
   return ( n*n*n );
}

double sphere_area( double n ){
   
   return ( 4*pi*n*n );
}

double sphere_vol( double n ){
   
   double help = (double) 4 / (double) 3;

   return ( help * pi * n * n * n );
}

int main(){
   
   double radius;

   printf("\nGive me the length of the radius in meters: ");
   scanf("%lf", &radius);
   
   printf("Cube: \n");
   printf("Surface Area: %.2lf\n", cube_area( radius ) );
   printf("Volume: %.2lf\n", cube_vol( radius ) );
   
   printf("\nSphere: \n");
   printf("Surface Area: %.2lf\n", sphere_area( radius ) );
   printf("Volume: %.2lf\n", sphere_vol( radius ) );

   return 0;
}
