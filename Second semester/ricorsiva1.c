//Scrivi funzione ricorsiva che dice se un numero è presente in un array di numeri

#include<stdio.h>
#define MAX 10

int funz(int[], int, int, int);

int main(){
    int arr[MAX];
    int index, num, stop=0, count=0;

    printf("Inserisci array (-100 per terminare): ");
    for(index=0;index<MAX&&!stop;index++){
        scanf("%d", &arr[index]);
        if(arr[index]==-100)
            stop=1;
        else
            count++;
    }

    printf("Inserisci numero da cercare: ");
    scanf("%d", &num);

    //printf("Count: %d, num: %d.\n", count, num);

    if(funz(arr,num,count,0))
        printf("%d e' presente nell'array.\n", num);
    else
        printf("%d NON e' presente nell'array.\n", num);
}

int funz(int arr[MAX], int num, int count, int pos){

    if(pos==count)
            return 0;
    if(arr[pos]==num)
        return 1;
    else
        return funz(arr,num,count,pos+1);
}
