/*Scrivere un programma che acquisisce una stringa di al più 100 caratteri che può contenere spazi e segni di punteggiatura.
Il programma conta quante consonanti doppie sono presenti nella stringa.
NOTE: assumere che la stringa NON sia vuota ed inoltre che non contenga lettere maiuscole.
Infine non possono verificarsi casi di consonanti triple o più. */

#include<stdio.h>

#define N 100
void acquisisci(char [], int);

int main (){
    char arr[N+1];
    int index, count=0;

    acquisisci(arr,N);
    for(index=1;arr[index]!='\0';index++)
        if(arr[index]>='b'&&arr[index]<='z'&&arr[index]!='e'&&arr[index]!='i'&&arr[index]!='o'&&arr[index]!='u'){
            if(arr[index]==arr[index-1])
                count++;
        }

    printf("Consonanti doppie: %d", count);

}


void acquisisci(char a[], int dim){
    int index, flag=1;
    char var;

    printf("Inserisci stringa:");
    for(index=0;index<dim&&flag;index++){
        var=getchar();
        if(var=='\n')
            flag=0;
        else
            a[index]=var;
    }

    a[index]='\0';

}
