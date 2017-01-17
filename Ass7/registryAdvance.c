#include "stdio.h"
#include "stdlib.h"
#include "string.h"

#define AMSIZE 7
#define NAMESIZE 41
#define GRADESNUM 6

void writeFile( unsigned int, char**, char**, short*, double**);
void readInput( unsigned int, char**, char**, short*, double**, FILE*);

int main( int argc, char **argv)
{
   unsigned int N, i;
   short *Semester;
   char **Name, **AM;
   double **Grades; // 6 positions, last one is the Avrg
   FILE *fp;

   printf("Number of students: ");
   scanf("%d", &N);
   
   AM = (char **)malloc( N * sizeof(char));
   for (i = 0; i < N; ++i)
   {
      AM[i] = (char *)malloc( AMSIZE * sizeof(char));
   } 
   Semester = (short *)malloc( N*sizeof(short));
   
   Grades = (double **)malloc( N * sizeof(double));
   for (i = 0; i < N; ++i)
   {
      Grades[i] = (double *)malloc( GRADESNUM * sizeof(double)); 
   }
   
   Name = (char **)malloc( N * sizeof(char));
   for (i = 0; i < N; ++i)
   {
      Name[i] = (char *)malloc( NAMESIZE * sizeof(char));
   }
   //Prospa8isa na ta kanw function ^^ alla o gcc evgaze error gia uninitialized
   

   fp = freopen(argv[1], "r", stdin);
   readInput( N, AM, Name, Semester, Grades, fp);
   fclose(fp);

   writeFile( N, AM, Name, Semester, Grades);

   return 0;
}

void readInput( unsigned int size, char **AM, char **Name, short Semester[], double **Grades, FILE *fp )
{
   unsigned int i, j, maxPos = 0;
   double sum, max = 0.0;
   for (i = 0; i < size; ++i)
   {
      char buf[100], delim[2], *token;
      fscanf(fp,"%s", buf);  
     
      delim[0] = buf[6]; //first delimiter is at pos 6 of buf
      delim[1] = '\0';
    
      token = strtok(buf, delim);
      AM[i] = token;
      
      token = strtok(NULL, delim);
      Name[i] = token;
      
      token = strtok(NULL, delim);
      Semester[i] = atoi(token);

      printf("%s\n", AM[i]);   
      
      sum = 0.0;
      for (j = 0; j < 5; ++j)
      {
         token = strtok(NULL, delim);
         Grades[i][j] = atof( token ); //Suppose due to ambiguous def that grades are symbol separated
         sum += Grades[i][j];
      }
      if( sum > max )
      {
         max = sum;
         maxPos = i;
      }  
   }
   printf("\nThe one with the biggest Average is:\nStud Name: %s\t AM: %s\t Semester: %d\t Grades: [%.1lf][%.1lf][%.1lf][%.1lf][%.1lf]\n", Name[maxPos], AM[maxPos], Semester[maxPos], Grades[maxPos][0], Grades[maxPos][1], Grades[maxPos][2], Grades[maxPos][3], Grades[maxPos][4]);

}

void writeFile( unsigned int size, char **AM, char **Name, short Semester[], double **Grades )
{
   int i;

   for (i = 0; i < size; ++i)
   {
      
      printf("Stud Name: %s\t AM: %s\t Semester: %d\t Grades: [%.1lf][%.1lf][%.1lf][%.1lf][%.1lf]\n", Name[i], AM[i], Semester[i], Grades[i][0], Grades[i][1], Grades[i][2], Grades[i][3], Grades[i][4]);
   
   } 
}

