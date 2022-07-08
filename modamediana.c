/*Scrivere un programma C composto da:
 - Una funzione leggi che richiede all’utente 10 numeri interi non negativi nell’intervallo [0,10] e li memorizza in un array.
 - Una funzione media che calcola la media dei voti inseriti.
 - Una funzione moda (=valore più frequente; ) che calcola la moda dei voti inseriti.
	- La moda è il valore che compare più frequentemente. In caso ci siano più numeri con la stessa frequenza ritornare uno qualsiasi di essi.
	- Usare un array aggiuntivo per memorizzare le frequenze.
 - Una funzione mediana (=valore che divide a metà una serie di valori) che calcola la mediana dei voti inseriti:
	- Dato un array di n elementi ordinati, la mediana è il valore centrale:
	- Se n è dispari la mediana è il valore che occupa la posizione (n+1)/2.
	- Se n è pari la mediana è la media dei valori che occupano la posizione n/2 e (n/2)+1.
	- Tale funzione richiamerà una funzione ordina che ordina gli elementi dell’array e li memorizza in un altro array.
 - Una funzione main che richiama le altre funzioni e stampa i risultati ottenuti.
	- Le funzioni parametriche nella dimensione dell’array.
*/

#include<stdio.h>
#define N 10

void leggi(int a[]);
void stampa(int a[]);
float media(int a[]);
int moda(int a[], int freq[]);
float mediana(int a[]);
void sort(void );
int a[N];

int main(){
	int freq[N]={0};
	int i;
	
	leggi(a);
	stampa(a);
	printf("Media: %.2f\n", media(a));
	printf("Moda: %d\n", moda(a, freq));
	sort();
	printf("Array ordinato: ");
	for(i=0;i<N; i++)
		printf("%d  ", a[i]);
	printf("\nMediana: %.2f\n", mediana(a));
	printf("\n");



return 0;
}

void leggi(int a[]){
	int i;

	printf("Inserisci 10 numeri interi non negativi nell'intervallo [0,10]:\n");
	for(i=0;i<N;i++)
		do{
			scanf("%d", &a[i]);
			if(a[i]<0||a[i]>10)
				printf("Valore non valido. Inserisci numeri interi non negativi nell'intervallo [0,10]");
		}while(a[i]<0||a[i]>10);
}

void stampa(int a[]){
	int i;
	
	printf("Array: ");
	for(i=0;i<N;i++)
		printf("%3d", a[i]);
	printf("\n");
}

float media(int a[]){
	float m;
	int i, somma=0, tot=0;

	for(i=0;i<N;i++){
		somma+=a[i];
		tot++;
	}
	
	m=(float)somma/tot;
	
return m;
}

int moda(int a[], int freq[]){
	int i, j, tot=-1, max;
	
	for(i=0;i<N;i++)
		for(j=0;j<N;j++)
			if(a[j]==i)
				freq[i]++;
	
	for(i=0;i<N;i++)
		if(freq[i]>tot){
			tot=freq[i];
			max=i;
		}
			
return max;
}

void sort(void){
	int flag=1, i, scambio;

	//BUBBLESORT
	while(flag==1){
		flag=0;
		for(i=0;i<N-1;i++)
			if(a[i]>a[i+1]){
				scambio=a[i];
				a[i]=a[i+1];
				a[i+1]=scambio;
				flag=1;
			}
	}
}

float mediana(int a[]){
	float med;

	if(N%2!=0)
		med=a[(N+1)/2];
	else
		med=(float)(a[N/2-1]+a[N/2])/2;
	
return med;
}

/*BUBBLESORT - per ordinare i valori
faccio ciclo while, creo un flag per sapere se nel for dentro il while ho o meno scambiato valori. Metto a 1 il flag ad ogni inizio del while. a 0 ad ogni inizio ciclo for*/

/*INSEPTIONSORT
uguale ma 2 cicli for e con un valore sentinella di cui controllare se c'è un più piccolo
*/
