/*
Si scriva un programma C che calcoli il quoziente della divisione tra interi x e y usando una funzione ricorsiva.
Caso base: x<y, allora il quoziente è zero.
Passo ricorsivo: il quoziente è 1 + il quoziente della divisione di (x-y) per y.
*/

#include<stdio.h>

int lab(int x, int y);

int main(){
    int x, y;
    int quoziente;

    printf("Inserisci valore x: ");
    scanf("%d", &x);

    printf("Inserisci valore y: ");
    scanf("%d", &y);

    quoziente=lab(x,y);

    printf("Il quoziente di %d e %d è: %d.\n", x, y, quoziente);

}

int lab(int x,int y){
    
    if(x<y)
        return 0;
    else 
        return 1+lab(x-y,y);
}