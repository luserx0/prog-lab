#include<stdio.h>
#include<stdlib.h>

void hanoi(int diskSize, char a, char b, char c)
{    
   if(diskSize == 1){
      printf("%c %c\n", a , b);
   }
    
    else{
        hanoi(diskSize - 1, a , c , b);
        
        printf("%c %c\n", a , b);
        
        hanoi(diskSize - 1, c , b , a);
    }
}

int main()
{    
    //freopen("qubits.in","r",stdin);
    //freopen("qubits.out","w",stdout);
    
   printf("Property of luserx0\nHellenico Problem: Qubits solution\n");
    printf("Give N and see the moves that have to be performed in A B and C bars\n");
    
    int N;
    
    scanf("%d", &N);

    hanoi(N, 'A', 'C', 'B');

    return 0;
}
