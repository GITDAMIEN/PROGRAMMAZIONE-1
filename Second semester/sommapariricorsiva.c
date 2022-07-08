/*Funzione ricorsiva che ritorna la somma dei primi n numeri pari */

#include<stdio.h>

int somma_pari(int);

int main(){
    int n=3;
    printf("%d", somma_pari(n));
}

int somma_pari(int n){
    if(n==1)
        return 2;
    else return 2*n+somma_pari(n-1);
}