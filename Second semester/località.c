/*Dichiarare un tipo di dato per rappresentare una località su una cartina in termini di longitudine e latitudine (due interi) ed un nome (una stringa di al max 30 caratteri).
Scrivere un programma che acquisisce i dati di dieci località ed individua la coppia di punti a distanza massima visualizzandone i nomi.
Nel caso ci siano più punti con la stessa distanza massima stampare soltanto la prima coppia individuata.
Per il calcolo della radice quadrata utilizzare la funzione sqrt() presente nella libreria math.h. La funzione riceve come parametro un numero in virgola mobile
e ne restituisce la radice quadrata, anch'essa un numero in virgola mobile. Esempio di utilizzo: ris = sqrt(dato); dove ris e dato sono due variabili float.
VARIANTE: Nel caso ci siano più punti con la stessa distanza massima stampare TUTTE le coppie individuate.*/

#include<stdio.h>
#include<math.h>
#include<unistd.h>
#define N 30
#define D 5

typedef struct{
	int longitudine;
	int latitudine;
	char cityname[N+1];
}cartina;

void acquisiscidati(cartina []);
void suspence();
void totaldistance(cartina [], int *, int *);


int main(){
	cartina local[D];
	int maggiore1, maggiore2;

	acquisiscidati(local);
	suspence();
	totaldistance(local,&maggiore1,&maggiore2);
	
	printf("\nLe località più distanti sono %s e %s.\n", local[maggiore1].cityname, local[maggiore2].cityname);
}

// acquisizione dati delle località

void acquisiscidati(cartina dati[D]){
	int index=0;
	
	do{
		printf("Località %d; Inserisci nome località: ", index+1);
		scanf("%s", dati[index].cityname);
		printf("Località %d; Inserisci latitudine: ", index+1);
		scanf("%d", &dati[index].latitudine);
		printf("Località %d; Inserisci longitudine: ", index+1);
		scanf("%d", &dati[index].longitudine);
		index++;
	}while(index<D);
}

//faking calculations just for fun :)

void suspence(){
	int ansia=0;
	//printf("\033c");
	
	do{
		if(!ansia){
			printf("Calcolo delle distanze");
			sleep(1);
		}
		printf(".");
		sleep(1);
		printf(".");
		sleep(1);
		printf(".");
		sleep(1);
		ansia++;
	}while(ansia<2);
}

//calcolo delle distanze massime

void totaldistance(cartina local[D], int *loc1, int *loc2){
	int index, max=0;
	int n;
	float y, x;
	
	for(index=0;index<D-1;index++){
		for(n=1;n<D;n++){
			y=local[index].latitudine-local[index+n].latitudine;
			if(y<0)
				y=-y;
			x=local[index].longitudine-local[index+n].longitudine;
			if(x<0)
				x=-x;
			if(sqrt(y*y+x*x)>max){
				max=sqrt(y*y+x*x);
				*loc1=index;
				*loc2=index+n;
			}
		}
	}
}

