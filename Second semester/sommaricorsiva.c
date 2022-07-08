/*Scrivere una funzione ricorsiva che dato un array di interi, la sua dimensione effettiva e qualsiasi altro parametro ritenuto utile,
calcola la somma degli elementi dell’array*/

#include<stdio.h>
#define N 10

int sommar(int [], int);

int main(){
    int index, arr[N]={1,2,3,4,5,6,7,8,9,10};
    int somma, pos=0;

    somma=sommar(arr, pos);
    printf("Somma: %d.\n", somma);

}

int sommar(int arr[N], int pos){

    if(pos==N-1)
        return arr[pos];
    else
        return arr[pos]+sommar(arr,pos+1);
}