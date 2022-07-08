//scrivi un sottoprogramma che fa inserimento da tastiera usando gli array come puntatori, conta i pari e dispari nell'array,
//tutto lavorando con la corrispondenza tra array e puntatori

#include<stdio.h>
#define N 100

void conta(int [N], int, int *, int *);

void main(){
	int a[N], index, count;
	int pari, dispari, exit, termina=0;
	
	do{
		exit=0, count=0, pari=0, dispari=0;
		printf("Inserisci numeri (termina con -1): ");
		for(index=0;index<N,!exit; index++){
			scanf("%d", &a[index]);
			if(a[index]==-1)
				exit=1;
			else
				count++;
		}
		
		conta(a, count, &pari, &dispari);
		
		printf("Hai inserito %d numeri pari e %d numeri dispari.\n", pari, dispari);
		printf("Premi 1 per terminare il programma, 0 per riavviarlo.\n");
		scanf("%d", &termina);
	}while(!termina);
	
	printf("Programma terminato.\n");
}

void conta(int arr[N], int lungh, int *p, int *d){
	int index;
	
	for(index=0;index<lungh;index++)
		if(arr[index]%2==0)
			*p=*p+1;
		else
			*d=*d+1;
}
