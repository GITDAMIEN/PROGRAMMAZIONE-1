/*Scrivere una funzione ricorsiva int cifra(int num, int k) che ritorna la k-esima cifra di num partendo da destra. Ad esempio cifra(829,2) restituisce 2.*/

#include<stdio.h>
#define getName(var) #var     //permette di stampare il nome della variabile

void leggi(int *);
int cifra(int num, int k);

int main(){
    int k, num;

    printf("Inserisci valore %s: ", getName(num));
    leggi(&num);
    printf("Inserisci valore %s: ", getName(k));
    leggi(&k);

    if(cifra(num,k)==-1)
        printf("k non puo' essere piu' grande della lunghezza del numero.\n");
    else
        printf("La %d-esima cifra di %d e' %d.\n", k, num, cifra(num, k));
}


void leggi(int * num){

    do{
        scanf("%d", &(*num));
        if(*num<=0)
            printf("Il numero dev'essere positivo: ");
    }while(*num<=0);
}

int cifra(int num, int k){

    if(k==1)
        return num%10;
    if(k>1&&num/10==0) //caso in cui k sia maggiore della lunghezza del numero
        return -1;
    else
        return cifra(num/10,k-1);
    
}
