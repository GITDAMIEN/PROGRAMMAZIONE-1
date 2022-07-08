//Scrivere un programma con una funzione ricorsiva che conta quante volte un numero è presente nell'array

//perchè non funziona funz() ??


#include<stdio.h>
#define MAX 10

int funz(int[], int, int);

int main(){
    int arr[MAX];
    int index, num, stop=0, count=0, tot=0;

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

    printf("Count: %d, num: %d.\n", count, num);

    tot=funz(arr,num,count);

    printf("%d e' presente %d volte nell'array.\n", num, tot);

}

int funz(int arr[MAX], int num, int count){

    if(arr==count){
        if(*arr==num)
            return 1;
        else
            return 0;
    }
    else{
        if(*arr==num)
            return 1+funz(arr+1,num,count);
        else
            return funz(arr+1,num,count);
    }
}
