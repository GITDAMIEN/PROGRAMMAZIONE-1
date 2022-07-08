/*Scrivi un programma che acquisisce 3 interi (non array) e li riordina in ordine crescente usando i puntatori*/
#include<stdio.h>

void sort(int *, int *, int *);

int main(){
	int a, b, c;
	
	printf("Inserisci valore 1: ");
	scanf("%d", &a);	
	printf("Inserisci valore 2: ");
	scanf("%d", &b);	
	printf("Inserisci valore 3: ");
	scanf("%d", &c);
	
	sort(&a, &b, &c);
	
	printf("I valori in ordine sono: %d, %d e %d", a, b, c);
}

void sort(int *m, int *n, int *o){
	int tmp;
	
	if(*m>*n){

		tmp=*m;
		*m=*n;
		*n=tmp;	
	}
	
	if(*n>*o){
		tmp=*n;
		*n=*o;
		*o=tmp;
	}	
	
	if(*m>*n){

		tmp=*m;
		*m=*n;
		*n=tmp;	
	}	
	
	
}


