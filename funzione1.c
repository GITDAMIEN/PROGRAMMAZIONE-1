#include<stdio.h>

int fun();

int main (){
	int a, b, flag;
	
//chiedo i numeri
	printf("Scrivi 2 numeri interi:\n");

scanf("%d%d", &a, &b);

flag=fun(a,b);

if(flag)
printf("%d è multiplo di %d\n", a, b);
else
printf("%d non è multiplo di %d\n", a, b);

return 0;

}
int fun(int n1, int n2){

if(n1%n2!=0)
	return 0;
else
return 1;

}

