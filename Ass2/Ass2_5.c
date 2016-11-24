#include "stdio.h"
#include "math.h"

int main(){

   unsigned long a,b;
   
   printf("Give me 2 positive integer numbers\n\n");
   
   printf("Number a: ");
   scanf("%ld", &a);

   printf("Number b: ");
   scanf("%ld", &b);
   
   printf("------------------------------------------------------\n");
   printf("Sum: %ld\n", a+b);
   printf("Difference: %ld\n", a-b);
   printf("Product: %ld\n", a*b);
   printf("Quotient: %ld \t Remainder: %ld\n", a/b, a%b);
   
   printf("\nReal Quotient: %.4lf \n", (double) a/b);

   printf("\na in the power of 2: %ld\n", (long)pow(a,2));
   printf("Square root of b: %.4lf\n", sqrt(b) );
   
   printf("\n\t Bye");
   return 0;
}
