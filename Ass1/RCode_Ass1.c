#include <stdio.h>

#define ll long long
int main(int argc, int **argv) {
    ll A, B;
    ll C, D, E, F; 
    
    printf ("Βασικές αριθμητικές πράξεις με Ακεραίους\n");
    printf ("========================================\n\n");
    
    printf ("Εισάγετε τον πρώτο αριθμό  : ");
    scanf ("%lld", &A);
    printf ("Εισαγετε το δεύτερο αριθμό : " ); //1st
    scanf ("%lld", &B);
    
    C = A + B;
    D = A - B;
    E = A * B;
    F = A / B;

    printf ("Άθροισμα  : %lld\n", C); //2nd
    printf ("Διαφορά   : %lld\n", D);
    printf ("Γινόμενο  : %lld\n", E); //3rd
    printf ("Πηλίκο    : %lld\n", F); //4th
    
    return 0;
}
