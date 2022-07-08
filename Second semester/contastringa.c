//conta i caratteri di una stringa usando i puntatori.

#include<stdio.h>
#define N 100

int conta(char []);

int main (){
    char a[N+1];

    printf("Inserisci stringa: ");

    scanf("%s", a);

    printf("La stringa è lunga %d caratteri.\n", conta(a));
}

int conta(char arr[N+1]){
    int index, count=0;

    for(index=0;arr[index]!='\0';index++)
        count++;

    return count;
}
