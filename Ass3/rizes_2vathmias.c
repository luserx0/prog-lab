#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char *argv[]) {
	float a,b,c,d;
	printf("Dilwste tous suntelestes tis eksiswsis:\n");
	scanf(" %f %f %f",&a,&b,&c);
	
	if(a==0){
		if(b==0){
			if(c==0){
				printf("i eksiswsi  exei suntelestes ta a=0 kai b=0 kai c=0.\n Legetai taytotita.\n");
			}
			else
			{	printf("i eksiswsi  exei suntelestes ta a=0 kai b=0 kai c=%f.\n Legetai adunati.\n",c);
		}
	}else
		{   printf("i eksiswsi  exei suntelestes ta a=0 kai b=%d kai c=%f.\n kai lusi exei x=%f .\n",b,c,-c/b);
	}
	
	}else 
	if(a!=0){
	
	d=b*b-4*a*c;
	
	if(d==0){
		printf("I eksiswsi exei mia lusi pragmatiki, tin x=%f",-b/2*a);
	}else 
	if(d>0){
		printf("i eksiswsi exei 2 rizes pragmatikes tis %.2f, %.2f",(-b+sqrt(d))/2*a,(-b-sqrt(d))/2*a);
	}else
	if(d<0){
		printf("i eksiswsi den exei kamia pragmatiki riza.");
	}
}
	return 0;
}
