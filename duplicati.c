#include <stdio.h> 
#define MAX 100

int main ( ) {
	int seq[MAX], seqU[MAX], num, nIns = 0, nU = 0, x, y; 
	int flag ; // uguale a zero se numero mai ripetuto
	
	// acquisizione sequenza
	scanf("%d", &num);
	while( nIns < MAX && num != 0) {
		seq[nIns] = num; 
		nIns++;
		if (nIns<MAX) 
			scanf("%d", &num);
	}

	// ricerca unici
	for(x = 0, flag = 0; x < nIns; x++) { // ciclo su tutti i numeri inseriti
		for(y=0, flag=0; y<nU &&!flag; y++){ 
			if(seqU[y] == seq[x])
				flag = 1;
		}
		if (!flag) { // se non ho trovato doppioni, inserisco 
			seqU[nU] = seq[x];
			nU++;
		} 	
	}
	// visualizzo unici
	for(x = 0; x<nU; x++) 
		printf("%d \t ", seqU[x]);
	printf("\nnUnici: %d", nU); 

}