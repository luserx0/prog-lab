/* 
 * Intellectual property of luserx0
 * check  https://github.com/luserx0/prog-lab
 * for license 
*/

#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#define print(x) printf("%d\n", x)

void read(int, int*, int*, int*, int*, int*);
void getN();
void fillArray(int, int *);
void readXs(int *, int *);
void readYs(int *, int *);
void sortArr( int, int, int*);
int partition( int , int, int *);
void createCombs( int*, int, int, int, int, int, int, int*);
int Xtest( int*, int, int, int);
int Ytest( int*, int, int, int);
void Print_Freq( int *, int *, int);


int main( int argc, char **argv)
{
   int N, *arr, X1, X2, Y1, Y2, *frequalizer, i;
   FILE *fp;

   fp = freopen( argv[1], "r", stdin );
   
   getN( &N );
   //print(N);   
   
   arr = (int *)malloc( N * sizeof(int));
   frequalizer = (int *)malloc( N * sizeof(int));
   for (i = 0; i < N; ++i){
      *(frequalizer+i) = 0;
   }
   // Mou evgaze error o gcc sto unitliazed array, opote sorry gia tis 3 ksemparkes grammes
   
   read( N, arr, &X1, &X2, &Y1, &Y2);  
   fclose(fp);

   sortArr( N-1, 0, arr);
   createCombs( arr, N, X1, X2, Y1, Y2, 6, frequalizer );

   return 0;
}

void read( int N, int *arr, int *X1, int *X2, int *Y1, int *Y2) 
{
   
   fillArray(N, arr); 
   readXs( X1, X2 );
   readYs( Y1, Y2 );
}

void getN( int *N)
{
   system("clear");
   do
   {
      printf("Give me N [7,49]: ");
      scanf("%d", N);
   } while( *N < 7 || *N > 49 );
}

void fillArray( int size, int *array )
{
   int i, j, FLAG;
   
   printf("Insert N distinct numbers within [1,49]: ");
   
   for (i = 0; i < size; ++i){
      do
      {
         FLAG = 1;
         scanf("%d", (array + i));
         for( j = 0; j < i; ++j)
         {
            if( *(array + j) == *(array + i) ){
               FLAG = 0;
               printf("Numbers must be distinct !\n Re-enter: ");
            }
         }

      }
      while( (*(array + i) < 1 || *(array + i) > 49 ) || FLAG == 0);
   } 
}

void readXs( int *X1, int *X2 )
{
   printf("Give me X1 & X2 [0,X1,X2,6]: \n");
   do
   {
      scanf("%d", X1);
   }
   while(*X1 < 0 || *X1 > 6 );

   do
   {
      scanf("%d", X2);
   }
   while( *X2 < *X1 || *X2 > 6);
}

void readYs( int *Y1, int *Y2 )
{
   printf("Give me Y1 & Y2 [21,Y1,Y2,279]: \n");
   do
   {
      scanf("%d", Y1);
   }
   while( *Y1 < 21 || *Y1 > 279 );

   do
   {
      scanf("%d", Y2);
   }
   while( *Y2 < *Y1 || *Y2 > 279);
}

void sortArr( int size, int low, int *array )
{
   int p;
   if( low < size )
   {
      p = partition( low, size, array);
      sortArr( p - 1, low, array);
      sortArr( size, p + 1, array);
   }
}

int partition( int low, int hi, int *arr)
{
   int pivot, i, j, temp;
   
   pivot = *(arr + hi);
   i = low;
   
   for( j = low; j < hi; ++j)
   {
      if( *(arr + j) <= pivot)
      {
         temp = *(arr+i);
         *(arr+i) = *(arr+j);
         *(arr+j) = temp;
         ++i;
      }
   }
   temp = *(arr+i);
   *(arr+i) = *(arr+hi);
   *(arr+hi) = temp;

   return i;
}

void createCombs( int *array, int N, int X1, int X2, int Y1, int Y2, int K, int *frequalizer)
{
   int i, k, j, l, m, x, n, *COMB, X_counter, Y_counter, Y_FLAG, N_K_Combs, Prntd_Combs;
   
   COMB = (int *)malloc( K * sizeof(int));
   printf("\nCOMBINATIONS BASED ON THE GIVEN CRITERIA: \n\n");

   N_K_Combs = Prntd_Combs = X_counter = Y_counter = 0;

   for (i = 0; i < N-5; ++i)
   {
      for (j = i+1; j < N-4; ++j)
      {
         for (k = j+1; k < N-3; ++k)
         {
            for (l = k+1; l < N-2; ++l)      
            {
               for (m = l+1; m < N-1; ++m)
               {
                  for (x = m+1; x < N; ++x)
                  {
                     *(COMB) = *(array+i);   //perissotero kopo para kalo 8a edine oi omadopoihsh twn parakatw entolwn
                     *(COMB + 1) = *(array+j);
                     *(COMB + 2) = *(array+k);
                     *(COMB + 3) = *(array+l);
                     *(COMB + 4) = *(array+m);
                     *(COMB + 5) = *(array+x);
                     

                     Y_FLAG = Ytest( COMB, K, Y1, Y2);
                     X_counter = Y_counter = 0;

                     if( Xtest( COMB, K, X1, X2) )
                     {
                        
                        if( Y_FLAG )
                        {
                           Prntd_Combs++;
                           for ( n = 0; n < K; ++n )
                              printf("%d ", *(COMB+n));
                           printf("\n");

                           ++*(frequalizer+i);
                           ++*(frequalizer+j);
                           ++*(frequalizer+k);
                           ++*(frequalizer+l);
                           ++*(frequalizer+m);
                           ++*(frequalizer+x);
                        }
                     }                  
                     else
                     {
                        X_counter++;
                        if( Y_FLAG )
                           Y_counter++;
                     }

                     N_K_Combs++;
                  
                  }
               } 
            }
         } 
      } 
   }
   printf("\n\nStatistics:");
   printf("\n\nNumber of Combinations N choose K: %d\n", N_K_Combs);
   printf("Number of Combinations that failed Xtest: %d\n", X_counter);
   printf("Number of Combinations that failed only Ytest: %d\n", Y_counter);
   printf("Number of Printed Combinations: %d\n", Prntd_Combs);
   Print_Freq( array, frequalizer, N);   
}

int Xtest( int *Comb, int K, int X1, int X2)
{
   int i, count = 0;
   for (i = 0; i < K; ++i){
      if( *(Comb+i) % 2 == 0 )
         count++;
   } 
   return ( count >= X1 && count <= X2 );
}

int Ytest( int *Comb, int K, int Y1, int Y2)
{
   int i, sum = 0;
   for (i = 0; i < K; ++i){
      sum += *(Comb+i);
   } 
   return( sum >= Y1 && sum <= Y2);
}

void Print_Freq( int *array, int *frequalizer, int N)
{
   int i;
   printf("\n Element Frequencies:\n");
   for (i = 0; i < N; ++i){
      printf("%d's frequency: %d\n", *(array+i), *(frequalizer+i));
   }
}
