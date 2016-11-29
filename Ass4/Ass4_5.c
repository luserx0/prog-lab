#include "stdio.h"
#include <math.h>

#define pi 3.1415926535
#define lim 1e-6

#ifndef abs
#define abs(x)  (x < 0) ? x*-1 : x 
#endif

double sine(double);

int main(){
   
   double x;
   
   do{
      printf("\nGive me the # of degrees[0,360] to count its sine: ");
      scanf("%lf", &x);
   }while( x < 0 || x > 360); //assert everything is in place
   
   x = x * pi / 180; //transform to radians

   printf("My sine: %lf\n", sine(x));
   printf("C's sine function: %.6lf\n", sin(x) );
   
   return 0;
}

double sine( double x ){
   
   double result=x, last, cond_help=x;
   short sign=-1; 
   long n; 
   
   n = 3;
   
   //tried to use fact and power vars but they got to big
   do
   {   
      last = cond_help;
      
      cond_help = cond_help * x * x / ( n * (n-1) ); //cond_help = power / fact
      
      //printf("%lf\n", cond_help);
      result += ( cond_help * sign );
       
      n+=2;
      sign *= -1;
   }
   while( abs(cond_help - last) > lim );

   return result;
}

