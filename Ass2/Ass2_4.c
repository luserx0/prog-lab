#include "stdio.h"

int main(){
   
   printf("This program calculates the size of C data types in this system\n\n");

   printf("The size of char is: %ld\n", sizeof(char) );
   printf("The size of int is: %ld\n", sizeof(int) );
   printf("The size of float is: %ld\n", sizeof(float) );
   printf("The size of double is: %ld\n", sizeof(double) );

   printf("\n\t Bye\n");
   return 0;
}
