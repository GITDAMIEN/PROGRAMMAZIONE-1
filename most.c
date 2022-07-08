#include<stdio.h>

int most(int);

int main (){
	int num;

	printf("Inserisci numero intero positivo:");
	do{
		scanf("%d", &num);
		if(num<=0)
			printf("Il numero deve essere intero positivo: ");
	}while(num<=0);

	
	printf("\nLa cifra più significativa è: %d\n", most(num));



	return 0;

}

int most(int n){
	int cifra;	
	
	while(n>0){
		cifra=n%10;
		n/=10;
	}

	return cifra;
}

