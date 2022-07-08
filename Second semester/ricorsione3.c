/*
Scrivere una funzione ricorsiva TIME(n) per il calcolo dei numeri T(n) definiti dalle seguenti relazioni: T(0) se n = 0, T(1) se n = 1, T(n) = 2T(n − 2) + 5 se n ≥ 2
*/

//NON HO CAPITO LA RELAZIONE T(n) = 2T(n − 2) + 5 se n ≥ 2

#include<stdio.h>

int TIME(int num);

int main(){
    int num;

    printf("Inserisci numero: ");
    scanf("%d", &num);

    printf("Esito: %d.\n",TIME(num));
}

int TIME(int num){

    if(num==0)
        return 0;
    else if(num==1)
        return 1;

    else return TIME(2*num-2+5);
}