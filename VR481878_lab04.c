/* Scrivere un programma C (matricola_lab04.c, sostituendo "matricola" col proprio numero di matricola universitaria) che implementi i seguenti sottoprogrammi:

Sottoprogramma 1: riceve come parametro una matrice quadrata NxN (con N definito staticamente, ma ipotizzando che potrebbe cambiare) di caratteri, di cui individuarne il carattere che compare con maggiore frequenza e lo restituisce (in caso di molteplici caratteri, si tenga il primo trovato);

Sottoprogramma 2: riceve come parametri un carattere e una matrice quadrata NxN di caratteri, visualizzando su terminale la stessa matrice però con uno spazio al posto di tutti i caratteri uguali al carattere passato come parametro;

In fine si scriva un programma main che, utilizzando i sottoprogrammi 1 e 2, individua il carattere che compare più frequentemente in una matrice NxN di caratteri, riempita dall'utente, per poi stamparla a schermo mostrando però uno spazio al posto dei caratteri uguali al carattere individuato.

    
            Esempio input:
            a.cde
            fdffr
            tQfrd
            yyfwe
            f1bpf

            Relativo output:
            a.cde
             d  r
            tQ rd
            yy we
             1bp 
    

Si ricorda che verranno considerati nel punteggio anche la presenza di commenti e la corretta indentazione. */


#include<stdio.h>
#define N 5    //dimensioni della matrice definiti staticamente, ma modificabili

//prototipi
char prog1(char [][N]);  //sottoprogramma 1, che individua il carattere con maggiore frequenza della matrice
void prog2(char , char [][N]);  //sottoprogramma 2, che sostituisce il carattere con maggiore frequenza della matrice con uno spazio

//programma main che chiama le funzioni 1 e 2
int main (){
	char mat[N][N]; //matrice di caratteri NxN
	int i, j;  //indici per scorrere la matrice
	char bin;  //variabile cestino in cui scartare gli \n inseriti da input nello scanf
	char car;  //variabile in cui salvare il carattere di maggiore frequenza restituito da prog1
	
	//chiedo all'utente di inserire la matrice
	printf("Inserisci i caratteri della matrice:\n");
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			scanf("%c%c", &mat[i][j], &bin);

	//stampo la matrice inserita
	printf("\nMatrice inserita:\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++)
			printf("%c", mat[i][j]);
		printf("\n");
	}
	printf("\n");

	//chiamo il primo sottoprogramma per rilevare il carattere con maggiore frequenza, poi lo stampo
	car=prog1(mat);
	
	printf("Il carattere con maggiore frequenza è: %c\n", car);
	
	//chiamo il secondo sottoprogramma che sostituisce car con uno spazio e stampa la matrice ottenuta
	prog2(car, mat);

return 0;
}

//primo sottoprogramma con parametro la matrice
char prog1(char m[][N]){
	int i, j; //indici per scorrere la matrice (primo giro)
	int h, k; //indici per scorrere la matrice (secondo giro)
	int cont, max;	//cont= conteggio frequenza del valore in esame
			//max= frequenza massima attuale
	char val;	//val= carattere con maggiore frequenza

	cont=0; //contatore da zero
	max=0; //definisco zero la frequenza massima attuale
	
	//doppio giro della matrice per confrontare il valore attuale con gli altri della matrice
	for(i=0;i<N;i++)
		for(j=0;j<N;j++){
			for(h=0;h<N;h++)
				for(k=0;k<N;k++)
					if(m[h][k]==m[i][j])
						cont++;
			if(cont>max){
				max=cont;
				val=m[i][j];
			}
			/* stampe di test
			printf("Cont: %d\n", cont);
			printf("Max: %d\n",max);
			printf("Val: %c\n",val);
			*/
			cont=0;
		}
	
	//restituisco al chiamante il carattere con maggior frequenza
	return val;
}

//il secondo sottoprogramma non restituisce nulla al main ma stampa direttamente la matrice con il carattere sostituito, quindi è un void (è una procedura)
void prog2(char c, char m[][N]){
	int i, j; //indici per scorrere la matrice

	//scorro la matrice e la stampo sostituendo il carattere con maggior frequenza con uno spazio
	//in questo modo la matrice nel main non viene sovrascritta, rimane "pulita" e posso riutilizzarla
	printf("\nMatrice ottenuta:\n");
	for(i=0;i<N;i++){
		for(j=0;j<N;j++){
			if(m[i][j]==c)
				printf(" ");
			else
				printf("%c", m[i][j]);
		}
		printf("\n");
	}
	printf("\n");
}






