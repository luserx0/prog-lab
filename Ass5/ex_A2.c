#include "stdio.h"
#include "stdlib.h"

long power(long, long);
long combinations(long, long);
long factorial(long);
void count_pow(long, long);
void count_facts(long, long);
void count_comb(long, long);


void MENU(long A, long B){
	
	int ch, count = 0;
	do{
		
		//system("cls");	
		
		system("clear");
		
		printf("[1] Power of A^B\n");
		printf("[2] Factorials of A & B\n");
		printf("[3] Combinations of A per B\n");
		printf("\n[4] Exit");
	   printf("\n\n#:");

		scanf("%d", &ch);
		
		switch(ch){
			
			case 1: count_pow(A,B); break;
			case 2:	count_facts(A,B); break;
			case 3: count_comb(A,B); break;
			
		}
      
      ++count;

	}while( ch != 4);
	
	printf("The number of decisions on the menu: %d\n", count);
}

int main(){
	
	long A, B; 
	
	printf("Give me two numbers: ");
	scanf("%ld %ld", &A, &B);
	
	MENU(A, B);
	
	return 0;
}

long power( long A, long B){
	
	
	if( B >= 0 ){
		
		long result, i;
		
		result = 1;	
		for( i=0; i < B; ++i){
			
			result *= A;
			
		}
		
	   return result;
   }
   
}

long factorial(long N) 
{
   long res = 1, i;

   if( N == 0 || N == 1 ) return 1;

   else{
      
      for (i = 2; i <= N; ++i){
         res *= i;
      }
      
      //stupid but within the assignment's limits
      //"implement everything yourself
      //I would use the gamma function and stuff..
      
      return res;
   }
}

long combinations( long A, long B)
{
   /*          n!
    *    -------------
    *       k!(n-k)!
   */

   return ( factorial(A) / ( factorial(B) * factorial(A-B) ) );
}

void count_pow(long A,long B)
{
   printf("A ^ B: %ld\n", power(A,B) );
   printf("Press enter to continue...");
   getchar();
   system("pause");
}

void count_facts(long A,long B)
{
   printf("Fact of A: %ld \n", factorial(A) );
   printf("Fact of B: %ld \n", factorial(B) );
   printf("Press enter to continue...");
   getchar();
   system("pause");
}

void count_comb(long A,long B)
{
   printf("Combinations of B on set A: %ld \n", combinations(A,B) );
   //printf("Press enter to continue...");
   //getchar();
   system("pause"); //meh
}

