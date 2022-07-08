/*Scrivere una funzione ricorsiva che calcola la somma di tutti i naturali compresi tra 0 e x (x viene letto da tastiera nel main, deve essere positivo, e viene
passato come parametro alla funzione).*/

#include<stdio.h>

int funz(int);

int main(){
    int x;

    printf("Inserisci valore x: ");
    do{
        scanf("%d", &x);
        if(x<=0)
            printf("x dev'essere positivo: ");
    }while(x<=0);

    printf("La somma di tutti i naturali compresi tra 0 e %d e' %d.\n", x, funz(x));
}

int funz(int x){
    if(x==0)
        return 0;
    else
        return x + funz(x-1);
}