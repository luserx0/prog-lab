#include "stdio.h"
#include "string.h"

int main(){

   int n, m, i, j, k;
   int start, end; //3rd

   printf("Insert a number >= 2: ");
   scanf("%d", &n);
   
   //1st
   printf("First:\n");
   for (i = 1; i <= n; ++i ){
      for (j = 0; j < i; ++j){

         printf("%s", ( j == i-1 ) ? "*\n" : "*");
      
      }
      
   } 
   
   //2nd
   printf("\nSecond:\n");
   k = n;
   for (i = 1; i <= n; ++i){
      
      for (j = 1; j <= n; ++j){

         printf("%c", (j < k) ? ' ' :  '*' ); //whitespace or asterisk
         
      }
      
      printf("\n");
      --k;
   } 

   //3rd
   printf("\nThird:\n");

   m = 2*n-1; //the number of asterisks at he n-th line, m is always odd
   
   //char buffer[m]
   //memset( buffer, ' ' , m-1 );
   start = end = m/2 + 1;
   
   for (j = 1; j <= n; ++j){

      for (i = 1; i <= m; ++i){
      
         printf("%c", ( i >= start && i <= end ) ? '*' : ' ');

      }
      --start;
      ++end;
      printf("\n");
   }

   //4th
   printf("\nFourth:\n");
   
   /*
    * OLD
    *
   for (i = 0; i < n; ++i){ //initializer
      printf( "%s", ( i != n-1 ) ? "*" : "*\n" );
   }
   
   odd = 1;
   for (j = 2; j <= n-1; ++j){//line counter
      
      printf("*");
      for (i = 2; i <= n-1; ++i){//pattern printer
         
         if( odd ){
            printf("%c", ( i % 2 == 0 ) ? '.' : ' ');   
         }
         
         else{
            printf("%c", ( i % 2 == 0 ) ? ' ' : '.');   
         }
      }
      printf("*\n");
      (odd == 1) ? (odd = 0) : (odd = 1); //change it
   }
   
   for (i = 0; i < n; ++i){ //ender
      printf( "%s", ( i != n-1 ) ? "*" : "*\n" );
   }
   */
   
   for (i = 0; i < n; ++i){
      for (j = 0; j < n; ++j){
         
         if( i==0 || j==0 || i==(n-1) || j==(n-1) )
            printf("*");
         else{
               
            printf("%c", ( i == j || (i+j == n-1) ) ? '.' : ' ');

         }
      } 
      printf("\n");
   } 


   return 0;
}  
