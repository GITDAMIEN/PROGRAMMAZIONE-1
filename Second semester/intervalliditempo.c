/*Definire un nuovo tipo di dato per memorizzare una durata temporale in termini di numero di giorni, ore, minuti e secondi.
Scrivere un programma che riceve da tastiera i dati sulla durata di una serie di intervalli di tempo (massimo 31).
Ciascun intervallo di tempo è specificato in termini di ore, minuti e secondi trascorsi. L'utente specifica quanti intervalli desidera inserire e poi procede al loro inserimento.
Il programma deve assicurarsi che i dati di ciascun intervallo inserito siano validi; in particolare, l'ora deve essere inclusa nell'intervallo [0; 23], i minuti in [0; 59], ed i
secondi in [0; 59]. Successivamente, il programma calcola la somma di tutti gli intervalli e la stampa a video nel formato: giorni, ore, minuti, secondi
(massimo 23 ore, massimo 59 minuti, massimo 59 secondi. Nessun limite al numero di giorni).
Esempio: per le seguenti durate di due intervalli di tempo (ore, minuti, secondi):
- 20 50 15
- 7 20 30
il risultato che dovrà essere stampato sarà:
1 giorno/i, 4 ora/e, 10 minuto/i e 45 secondo/i.*/

#include<stdio.h>

typedef struct{
	int giorni;
	int ore;
	int minuti;
	int secondi;
}durata;

void warning();
void inserimento(durata [], int);
void calcola(durata [], int, int *, int *, int *, int *);

int main(){
	int max;
	int secs=0, mins=0, hours=0, days=0;
	
	do{
		printf("Dimmi quanti intervalli di tempo devi inserire (massimo 31): ");
		scanf("%d", &max);
	}while(max<1||max>31);
	
	durata arr[max];
		
	printf("Perfetto. Procedi con l'inserimento.\n");
	inserimento(arr, max);
	
	calcola(arr, max, &secs, &mins, &hours, &days);
	
	printf("Il tempo totale trascorso è di %d giorno/i, %d ora/e, %d minuto/i e %d secondo/i.\n", days,hours,mins,secs);
	
}

void warning(){
	printf("Ricontrolla il formato.\n");
}

void inserimento(durata arr[], int max){
	int index;
	
	for(index=0;index<max;index++){
		do{
			printf("Intervallo %d: Inserisci i giorni: ", index+1);
			scanf("%d", &arr[index].giorni);
			if(arr[index].giorni<0)
				warning();
		}while(arr[index].giorni<0);	
			
		do{
			printf("Intervallo %d: Inserisci le ore: ", index+1);
			scanf("%d", &arr[index].ore);
			if(arr[index].ore>23||arr[index].ore<0)
				warning();
		}while(arr[index].ore>23||arr[index].ore<0);
				
		do{
			printf("Intervallo %d: Inserisci i minuti: ", index+1);
			scanf("%d", &arr[index].minuti);
			if(arr[index].minuti>59||arr[index].minuti<0)
				warning();
		}while(arr[index].minuti>59||arr[index].minuti<0);
		
		do{
			printf("Intervallo %d: Inserisci i secondi: ", index+1);
			scanf("%d", &arr[index].secondi);
			if(arr[index].secondi>59||arr[index].secondi<0)
				warning();
		}while(arr[index].secondi>59||arr[index].secondi<0);
	}
}


void calcola(durata a[], int max, int *ss, int *ms, int *hs, int *ds){
	int index;
	
	for(index=0; index<max; index++){
		//conto i secondi
		(*ss)+=a[index].secondi;
		while((*ss)>59){ //e li trasformo in minuti se superano i 60
			(*ss)=(*ss)-60;
			(*ms)=(*ms)+1;
		}
		//conto i minuti
		(*ms)+=a[index].minuti;
		while((*ms)>59){ // e li trasformo in ore se superano i 60
			(*ms)=(*ms)-60;
			(*hs)=(*hs)+1;
		}
		//conto le ore
		(*hs)+=a[index].ore;
		while((*hs)>23){ // e le trasformo in giorni se superano le 23
			(*hs)=(*hs)-24;
			(*ds)=(*ds)+1;
		}
		
		//conto i giorni
		(*ds)+=a[index].giorni;
		
	}
}

