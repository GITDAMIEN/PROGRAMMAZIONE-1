/*
Scrivere una funzione ricorsiva che data una stringa e un carattere, restituisce la prima occorrenza del carattere nella stringa (-1 se il carattere non e' presente)
*/

#include<stdio.h>
#define N 20
int cerca(char [], char);

int main(){
    char str[N+1];
    char c, bin;
    int esito;

    printf("Inserisci stringa: ");
    fgets(str,N+1,stdin);

    printf("Inserisci carattere da cercare: ");
    scanf("%c%c", &c, &bin);

    esito=cerca(str, c);

    if(esito==-1)
        printf("%c non presente nella stringa.\n", c);
    else
        printf("Prima occorrenza di %c in posizione %d,\n", c, esito);
}

int cerca(char str[N+1], char c){
    int trovato=0;
    // printf("Str: %d.\n", str);

    if(*str=='\0'&&!trovato)
        return -1;
    else if(*str==c){
        return cerca(str,c)+(cerca(str+1,c));    // ???????
        trovato=1;
    }
    else
        return (cerca(str+1,c));
}