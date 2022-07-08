#include<stdio.h>
/*Scrivere un sottoprogramma che ricevuto in ingresso un intero positivo conta e restituisce al chiamante il numero di cifre che compongono il numero in ingresso e ne sono divisori.*/

int fun();

int main(){
int num, ret;


//chiedo il numero
printf("Inserisci un numero intero positivo:\n");
do{
	scanf("%d", &num);
	if(num<=0)
		printf("Valore errato. Inserisci un numero intero positivo:\n");
	}while(num<=0);


ret=fun(num);

//stampo risultato
printf("Il numero di cifre che compongono il numero e ne sono divisori è: %d\n", ret);

return 0;

}
int fun(int num){
	int resto, i, cont=0;

	i=num;
	while(i>0){
		resto=i%10;
		if(num%resto==0)
			cont++;
		i=i/10;

	return cont;

	}
}





