/*
Scrivere una funzione ricorsiva che calcola la somma di tutti i naturali compresi tra 0 e x
(x viene letto da tastiera nel main, deve essere positivo, e viene passato come parametro alla funzione).
*/

#include<stdio.h>
int somma(int x);

int main(){
    int x;
    int tot=0;

    do{
        printf("Inserisci il valore x: ");
        scanf("%d", &x);
    }while(x<=0);

    tot+=somma(x);

    printf("\nSomma dei valori da 0 a %d: %d.\n", x, tot);

}

int somma(int x){
    if(x==1)
        return 1;
    else
        return x+somma(x-1);
}
