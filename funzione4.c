#include<stdio.h>
/*Scrivere un sottoprogramma che ricevuto in ingresso un 
numero intero, calcola e restituisce il numero intero ottenuto mettendo le cifre in ordine opposto. Per esempio, se il valore ricevuto in ingresso e 1245 il sottoprogramma 
restituisce 5421. Se il valore ricevuto in ingresso e 190 il sottoprogramma restituisce 91.*/

int fun();

int main (){
int num, ris;

printf("Dammi un numero:\n");
scanf("%d", &num);

ris=fun(num);

printf("Il numero inverso è: %d\n", ris);

return 0;
}
int fun(int num){
int resto=0;

while(num>0){
	resto=resto*10+num%10;
	num=num/10;
}

return resto;

}
