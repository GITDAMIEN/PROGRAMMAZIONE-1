/*Scrivere una funzione ricorsiva potenza(int base, int esp) che riceve due parametri e calcola l’elevamento a potenza (nel caso di esponente positivo).*/

#include<stdio.h>

int potenza(int, int);

int main(){
    int base, esp, esito;

    printf("Inserisci base: ");
    scanf("%d", &base);
    do{
        printf("Inserisci esponente: ");
        scanf("%d", &esp);
        if(esp<0)
            printf("Inserisci un esponente positivo.\n");
    }while(esp<0);

    esito=potenza(base, esp);

    printf("Esito: %d.\n", esito);
}

int potenza(int base, int esp){

    if(esp==0)
        return 1;
    if(esp==1)
        return base;
    else
        return base*potenza(base,esp-1);
    
}