/*Scrivere un programma che calcola la radice quadrata di un intero e restituisce:
- la radice quadrata 
- 1 se radice esatta, 0 se radice non esatta */

#include<stdio.h>

int radice(int, int *);

int main (){
	int a , ris, intera;
	do{
		scanf("%d", &a);
	}while(a<=0);
	
	intera=radice(a,&ris);
	
	printf("Esito: %d, %d", ris, intera);
}

int radice (int n, int *ris){
	*ris=1;
	while(!((*ris)*(*ris)>n))
		(*ris)++;
	(*ris)--;
	
	return ((*ris)*(*ris)==n); //restituisco il risultato di un confronto
}
