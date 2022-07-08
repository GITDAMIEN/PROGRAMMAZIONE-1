#include<stdio.h>
int main (){
	//dichiarazione
	int num1, num2, r, r1, r2;
	int somma;
	
	//verifico che num1 e num2 siano costituiti da uni e zeri
	scanf("%d", &num1);
	while (num1>=0){
		r=num1%10;
		if(r!==1||r!==0);
			printf("Il primo numero inserito non è binario\n");
		else
			num1=num1/10;
	}
	scanf("%d", &num2);
	while (num2>=0){
		r=num2%10;
		if(r!==1||r!==0);
			printf("Il secondo numero inserito non è binario\n");
		else
			num2=num2/10;
	}
	while(num1>=0&&num2>=0)
		r1=num1%10;
		r2=num2%10;
		if(r1+r2==0)
			somma
	
}
