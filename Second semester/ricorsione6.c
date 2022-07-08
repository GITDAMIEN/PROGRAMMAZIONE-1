/*Scrivere una funzione ricorsiva che calcola il resto della divisione tra due interi positivi (avendo a disposizione solo somme e sottrazioni).*/


#include<stdio.h>
#define getName(var) #var     //permette di stampare il nome della variabile

void leggi(int *);
double funz(int , int );

int main(){
    int x, y;

    printf("Inserisci valore %s: ", getName(x));
    leggi(&x);
    printf("Inserisci valore %s: ", getName(y));
    leggi(&y);
    
    printf("Il resto della divisione tra gli interi %d e %d e' %d.\n", x, y, funz(x,y));
}

int funz(int x, int y){               //????????
    if(x%y==0)
        return 0;
    else
        return 1 + funz(x-y,y);
}

void leggi(int * num){

    do{
        scanf("%d", &(*num));
        if(*num<=0)
            printf("Il numero dev'essere positivo: ");
    }while(*num<=0);
}
