/*
Scrivere una funzione ricorsiva che stabilisce se due numeri interi x e y sono primi tra loro(ossia non hanno divisori comuni >1).
La funzione deve restituire 1 (vero) o 0 (falso). Attenzione: esistono 2 casi base (proprietà vera e proprietà falsa).
*/

#include<stdio.h>

int primi(int, int);

int main(){
    int x, y;

    printf("Inserisci x: ");
    scanf("%d", &x);
    printf("Inserisci y: ");
    scanf("%d", &y);
    
    if(primi(x,y))
        printf("Coprimi.\n");
    else
        printf("Non coprimi.\n");
}

int primi(int x, int y){
    if(x==1||y==1)
        return 1;
    else if (x==y)
        return 0;

    else if (x>y)
        return primi(x-y, y);

    else if (x<y)
        return primi(y-x, x);

}