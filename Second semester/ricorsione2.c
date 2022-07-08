/*
Scrivere una funzione ricorsiva che dato un array di interi, la sua dimensione e un intero n, restituisce 1 se un multiplo di n è presente nell'array, 0 altrimenti.
*/

 ////////////////////////// ?????????????????
 
#include<stdio.h>
#define N 10

int multiplo(int [N], int);

int main(){
    int arr[N];
    int n, index;

    printf("Inserisci array di %d interi: ", N);
    for(index=0;index<N;index++)
        scanf("%d", &arr[index]);

    printf("Inserisci numero n: ");
    scanf("%d", &n);
    
    if(multiplo(arr,n))
        printf("Nell'array è presente un multiplo di %d", n);
    else
        printf("Nell'array non è presente alcun multiplo di %d", n);
}

int multiplo(int a[N], int n){

    if(a==N-1&&*a%n!=0)
        return 0;
    else if(*a%n==0)
        return 1;
    else 
        return multiplo(a+1,n);
}