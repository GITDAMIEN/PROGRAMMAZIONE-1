#include <stdio.h>

 //SOLUZIONE PRESA DAL PROF, LA MIA NON ERA CORRETTA (vedi rettangolo2err.c)

int main(){
	int a,b;
	int i,j;
	do{
		scanf("%d",&a);
	}while(a<=0);
	
	do{
		scanf("%d",&b);
	}while(b<=0);
	
	for(i=0;i<a;i++)
	{
		for(j=0;j<b;j++)
			if(i==0 || i==a-1 || j==0 || j==b-1)
				printf("*");
			else printf("X");
			
		printf("\n");
	}
	



}