/*Scrivere un programma che acquisisce una matrice di caratteri quadrata 3x3 da standard input e verifica quale carattere occorre più volte
nella matrice stessa (quale ha più doppioni).
Stampa quindi a video il carattere che è comparso più volte e la matrice con tale carattere sostituito da '*'.
*/

#include <stdio.h> 
#define MAXD 3

int main ( ) {
 char matr[MAXD][MAXD]; //matrice
 int i, j, h, k; //indici per scorrere 2 volte in contemporanea la matrice
 int maxconto, conto; //maxconto = n°massimo di volte in cui è comparso un carattere, conto = n° di volte che è comparso il carattere in esame
 int maxc; //maxc = carattere che è finora comparso il maggior numero di volte

 // acquisisco caratteri
for(i=0; i<MAXD; i++) 
	for(j=0; j<MAXD; j++)
		scanf(" %c", &matr[i][j]);

// ricerco il carattere che compare piu volte
// per ciascuna posizione ripeto il conteggio
/* Eseguo un doppio giro di tutta la matrice, prima con gli indici i,j e poi con h,k;
in questo modo confronto ogni singolo valore in ogni singola posizione della matrice con tutti i valori della matrice stessa */
for (i =0, maxconto=0, maxc=matr[0][0]; i<MAXD; i++) {
	for(j=0; j<MAXD; j++) {
		for(h=0, conto=0; h<MAXD; h++) {  
			for(k=0; k<MAXD; k++) {
				if(matr[i][j]==matr[h][k])    //se il valore attualmente in confronto è ritrovato uguale in un'altra posizione della matrice
					conto++;                  //aumento il conteggio singolo

			} 			
		}

		if( conto>maxconto ) {    //finito il ciclo di confronto del singolo elemento per tutta la matrice, se questo è comparso più volte
			maxconto=conto;       //rispetto al valore finora salvato (in maxconto il n° di volte che compare, in maxc il valore stesso)
			maxc=matr[i][j];      //aggiorno il n° massimo di volte trovato per un carattere in maxconto e il carattere stesso in maxc
		}
	}
}    //arrivato qui avrò confrontato tutti i caratteri di tutta la matrice con tutti i caratteri della matrice stessa,
	//ottenendo il carattere con il maggior numero di comparse (doppioni)


 // visualizzo carattere
 printf("\nMAX: %c\n", maxc);

 // stampo matrice, visualizzando '*' al posto di ogni posizione in cui comparirebbe il carattere che compare di più
 for(i=0; i<MAXD; i++) { 
 	for(j=0; j<MAXD; j++) {
		if(matr[i][j]!= maxc)
			printf("%c", matr[i][j]);
		else printf("*");
	}
	printf("\n");
	
 }
}
