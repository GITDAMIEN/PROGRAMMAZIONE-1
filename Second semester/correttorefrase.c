/*Scrivere un programma in linguaggio C che legga una frase introdotta da tastiera. La frase è terminata dall’introduzione del carattere di invio.
La frase contiene sia caratteri maiuscoli che caratteri minuscoli, e complessivamente al più 100 caratteri. Il programma deve svolgere le seguenti operazioni:
● visualizzare la frase inserita
● costruire una nuova frase in cui il primo carattere di ciascuna parola nella frase di partenza è stato reso maiuscolo.
Tutti gli altri caratteri devono essere resi minuscoli. Il programma deve memorizzare la nuova frase in una opportuna variabile
● visualizzare la nuova frase.
Ad esempio la frase cHe bElLA gIOrnaTa diviene Che Bella Giornata */

#include<stdio.h>
#include<ctype.h>
#define N 100

int main(){
    char str[N+1];
    int index;

    printf("Inserisci stringa: ");
    fgets(str, N+1, stdin);

    printf("La stringa inserita è: %s", str);

    for(index=0;str[index]!='\0';index++)
        if(index==0||str[index-1]==' '){                //se sei ad inizio parola
            if(str[index]>=97&&str[index]<=122)              //e il carattere è minuscolo
                str[index]-=32;                      //rendilo maiuscolo
        }
        else if(str[index]>=65&&str[index]<=90)              //altrimenti se sei in mezzo alla parola ed è un carattere maiuscolo
                str[index]+=32;                      //rendilo minuscolo


    printf("La stringa corretta è: %s", str);

}