/*Scrivere un programma per la verifica dei codici ISBN-10. Un codice ISBN-10 è una sequenza numerica di 10 cifre (da 0 a 9) e, per verificarne la validità: (i) si moltiplica ogni cifra per un peso in base alla posizione della cifra stessa: la prima cifra per 10, la seconda per 9, la terza per 8 e così via, (ii) si sommano i risultati, (iii) la somma deve essere un multiplo intero di 11.
Ad esempio:
○ ISBN: 0078818095
0*10 + 0*9 + 7*8 + 8*7 + 8*6 + 1*5 + 8*4 + 0*3 + 9*2 + 5*1 = 220 220 è un multiplo di 11, di conseguenza il codice ISBN è valido
Nella risoluzione dell’esercizio si implementi la seguente funzione: int valido (int isbn[]) che riceve in ingresso un codice ISBN e restituisce 1 se è valido, 0 altrimenti.*/

#include<stdio.h>
#define N 10

int valido (int isbn[]);

int main(){
	int i, arr[N];
	
	printf("Inserisci codice ISBN-10: ");
	for(i=0;i<N;i++)
		do{
			scanf("%d", &arr[i]);
			if(arr[i]<0||arr[i]>9)
				printf("Valore non valido");
		}while(arr[i]<0||arr[i]>9);
	
	printf("Esito: %d\n", valido(arr));

return 0;
}

int valido (int isbn[]){
	int i, j, somma=0;

	//si può usare anche solo una variabile mettendo, al posto di j, "10-i"

	for(i=0, j=10;i<N;i++,j--){
		somma+=isbn[i]*j;
	}
	
	printf("Somma: %d\n", somma);

	if(somma%11==0)
		return 1;
	else
		return 0;

}
