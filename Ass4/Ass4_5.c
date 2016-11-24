#include "stdio.h"
#include "math.h"

#define pi 3.1415926535

double count_nth( long fact, double power ){
   
   return (power / fact);
}

double sine( double x ){
   
   double diff, result=0, power = x;
   short flag_minus = 0;
   long n=1, fact=1;
 
   do{   
      if( n != 1 ){ //skip first iteration
         fact = fact * (n-1) * n; 
         power = power * x * x; 
      }//step

      diff = count_nth( fact, power ); //oros

      if( flag_minus ){
         
         result -= diff;
         flag_minus = 0;
      }
      else{
         
         result += diff;
         flag_minus = 1;

      }  
      //printf("%ld %lf\n", fact, diff);  troubleshoot
      
      n+=2;
   
   }while( diff > 10e-8 );

   return result;
}


int main(){
   
   double x;
   
   printf("\nGive me the # of degrees to count its sine: \n");
   
   scanf("%lf", &x);
   
   //assert everything is in place
   x = x * pi / 180; //transform to radians

   printf("My sine: %.6lf\n", sine(x));
   printf("C's sine function: %.6lf\n", sin(x) );
   return 0;

}
