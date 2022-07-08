/*Scrivere un programma che chiede in input una stringa (senza spazi) di al massimo 50 caratteri e verifica che la stringa sia ben parentesizzata.
Una stringa e`ben parentesizzata se le parentesi (che possono essere solo tonde) sono chiuse correttamente nell’ordine in cui vengono aperte.
Esempio di stringa ben parentesizzata: bla(bla)(bla(bla))(bla()(bla)())*/

#include<stdio.h>
#define N 50

int main(){
	char car[N+1];
	int index, conto=0;

	printf("Inserisci stringa: ");
	scanf("%s", car);
	
	for(index=0;car[index]!='\0'&&conto>=0;index++){
		if(car[index]==40)
			conto++;
		else if(car[index]==41)
			conto--;
	}
	
	
	if(conto>=0)
		printf("Stringa correttamente parentesizzata\n");
	else
		printf("Stringa non correttamente parentesizzata\n");	
}
