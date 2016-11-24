#include "stdio.h"
#include "math.h"

#define ll long long

int main(){

      ll even=0, Avg_counter = 0, Prod_Neg = 1, Sum=0, step;
      double Avg_P = 0;
      short Neg_FLAG = 0;   
      
      printf("Give numbers or terminate with 0\n");
      scanf("%lld", &step);
      
      while( step != 0 ){

         if( step % 2 == 0 )
            ++even;
         else
            printf( "%lld is odd and its %.2lf to the power of 2\n", step, pow(step, 2) );

         if( step >= 0 ){
            ++Avg_counter;
            Sum += step;
            
         }
         
         else{
            Neg_FLAG = 1;
            Prod_Neg *= step;
         }

         scanf("%lld", &step);
      }
      
      Avg_P = (double) Sum / Avg_counter;

      printf("\n\nThe average of positive numbers is: %.2lf \n", Avg_P);
      printf("The product of negative numbers is: %lld \n", (Neg_FLAG) ? Prod_Neg : 0);
      printf("The number of even number is: %lld \n", even);

      return 0;
}
