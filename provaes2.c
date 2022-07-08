/*Si scriva un programma C che definisce la funzione int cifra_minima(int num) la quale deve restituire la cifra più bassa nella rappresentazione decimale di num.
Tale programma dovrà inoltre definire un main che
(1) chiede all’utente di inserire un numero non negativo,
(2) chiama la funzione cifra_minima per calcolarne la cifra più bassa e
(3) stampa tale cifra minima trovata.
*/

#include<stdio.h>

int cifra_minima(int num);

int main (){
	int n;

	printf("Inserisci un numero non negativo: ");
	do{
		scanf("%d", &n);
		if(n<0)
			printf("Valore non valido. Inserisci un numero non negativo: ");
	}while(n<0);

	printf("Cifra minima trovata: %d\n", cifra_minima(n));

return 0;

}


int cifra_minima(int num){
	int cifra, minima;
	
	minima=num;

	while(num>0){
		cifra=num%10;
		num/=10;
		if(cifra<minima)
			minima=cifra;
	}

return minima;

}
