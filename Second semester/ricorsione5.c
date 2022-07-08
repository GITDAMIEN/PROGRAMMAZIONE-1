/*Si scriva un programma C che calcoli il quoziente della divisione tra interi x e y usando una funzione ricorsiva.
 Caso base: x < y, allora il quoziente è zero.
 Passo ricorsivo: il quozionte è 1 + il quoziente della divisione di (x-y) per y.

Il programma dovrà contenere anche una funzione leggi() richiede all’utente un intero non negativo (controllare l’input). Tale funzione
sarà chiamata due volte all’interno della funzione main() per inizializzare x e y*/


#include<stdio.h>
#define getName(var) #var     //permette di stampare il nome della variabile

void leggi(int *);
int funz(int , int );

int main(){
    int x, y;

    printf("Inserisci valore %s: ", getName(x));
    leggi(&x);
    printf("Inserisci valore %s: ", getName(y));
    leggi(&y);
    
    printf("Il quoziente della divisione tra interi %d e %d e' %d.\n", x, y, funz(x,y));
}

int funz(int x, int y){
    if(x<y)
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
