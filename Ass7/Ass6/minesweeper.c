#include "stdio.h"
#include "stdlib.h"
#include "time.h"

int K, M, N, **table;

void read();
void fill();
void count();
void print();
void printfInFile();

int main(void)
{
   read();
   fill();
   count();
   print();
   printfInFile();

   return 0;
}

void read()
{
   int i,j; 
   
   do
   {  
      printf("Give me a correct input for K, M, N: \n");
      scanf("%d %d %d", &K, &M, &N);
   }
   while( M < 2 && N < 2 && K > M*N );
   //Allocate the table
   table = (int **)malloc( (M+2) * sizeof(int) );
   for (i = 0; i <= (M+1); ++i){
      table[i] = (int *)malloc((N+2) * sizeof(int));
      //*(p + i)
   }
   
   //Clear garbage in case table[i][j] == 42
   for (i = 1; i <= M; ++i)
   {
      for (j = 1; j <= N; ++j)
      {
         table[i][j] = 0;
      } 
   }
}

void fill()
{
   int j, k;
   
   //fill random K bombs of type '*'
   srand( (unsigned int)time(NULL) );
   while( K > 0 ){
      
      //table's index limits: [0,M+1][0,N+1]
      //minesweeper's limits: [1,M][1,N]

      j = rand() % M + 1;
      k = rand() % N + 1;
      
      if( table[j][k] != '*' ) // '*' == 42
      {
         table[j][k] = '*';
         --K;
      }
   }
}

void count()
{
   int i, j, k, l, cnt;

   for (i = 1; i <= M; ++i)
   {
      for (j = 1; j <= N; ++j)
      {
         if( table[i][j] != '*' )
         {
            cnt = 0;

            for (k = i-1; k <= i+1; ++k)
            {
               for (l = j-1; l <= j+1; ++l)
               {   
                  if( table[k][l] == '*' )
                     cnt++;
               }
            } 
            
            table[i][j] = cnt;
         }
      }
   }
}

void print()
{  
   int i, j;
   
   printf("\n\n");
   for (i = 0; i <= N+1; ++i){
      printf(".");
   } 
   printf("\n");
   for( i = 1; i <= M; ++i )
   {
      for (j = 0; j <= N+1; ++j)
      {
         if( j == 0 || j == N+1 )
            printf(".");
         else
         {
            if( table[i][j] == 42 )
               printf("*");
            else
               printf("%d", table[i][j]);
         }
      }
      printf("\n");
   }
   for (i = 0; i <= N+1; ++i){
      printf(".");
   }
   printf("\n");
}

void printfInFile()
{
   
   FILE *fp;
   int i, j;

   fp = freopen("minesweeper.out","w", stdout);

   printf("\n\n");
   for (i = 0; i <= N+1; ++i){
      printf(".");
   } 
   printf("\n");
   for( i = 1; i <= M; ++i )
   {
      for (j = 0; j <= N+1; ++j)
      {
         if( j == 0 || j == N+1 )
            printf(".");
         else
         {
            if( table[i][j] == 42 )
               printf("*");
            else
               printf("%d", table[i][j]);
         }
      }
      printf("\n");
   }
   for (i = 0; i <= N+1; ++i){
      printf(".");
   } 
   printf("\n");
   fclose(fp);
   //printf("\n\nContents of minesweeper.out file:\n");
   //system("cat minesweeper.out");
}

