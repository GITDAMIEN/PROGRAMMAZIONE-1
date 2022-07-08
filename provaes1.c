/*Scrivere un programma C che:
○ Richiede all’utente di inserire 20 caratteri e li salva in un array.
○ Produce due risultati:
● Un array costruito con i caratteri inseriti in cui ogni vocale (maiuscola o minuscola) è sostituita da una cifra corrispondente (A=1, E=2, I=3, O=4, U=5).
● Un numero contenente la somma delle cifre (caratteri da 0 a 9) contenute nella stringa prodotta.*/

#include<stdio.h>
#define N 20

int main(){
	char arr[N], bin;
	int i, sum=0;
	
	printf("Inserisci 20 caratteri: ");
	for(i=0;i<N;i++)
		scanf("%c%c", &arr[i], &bin);
	/*in alternativa posso usare la funzione getchar (contenuta nella libreria stdlib, da includere) e scrivere:

	scanf("%c ", &arr[i]);
	bin=getchar();

	 */
	printf("Array inserito: ");
	for(i=0;i<N;i++)
		printf("%3c", arr[i]);
	printf("\n");

	for(i=0;i<N;i++){
		if(arr[i]=='A')
			arr[i]='1';
		if(arr[i]=='E')
			arr[i]='2';
		if(arr[i]=='I')
			arr[i]='3';
		if(arr[i]=='O')
			arr[i]='4';
		if(arr[i]=='U')
			arr[i]='5';
		if(arr[i]=='a')
			arr[i]='6';
		if(arr[i]=='e')
			arr[i]='7';
		if(arr[i]=='i')
			arr[i]='8';
		if(arr[i]=='o')
			arr[i]='9';
		if(arr[i]=='u')
			arr[i]='0';
	}
	
	printf("Array convertito: ");
	for(i=0;i<N;i++)
		printf("%3c", arr[i]);
	printf("\n");	

	for(i=0;i<N;i++)
		if(arr[i]>='0'&&arr[i]<='9')
			sum+=arr[i]-48;

	printf("Sum: %d\n", sum);

}
