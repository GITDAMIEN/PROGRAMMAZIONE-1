/*Si scriva un programma C che definisce le funzioni:
 leggi(), che legge da tastiera un numero intero non negativo e lo restituisce. Se fosse negativo, deve continuare a chiederlo all'utente;
 stampa(int numero), che stampa le cifre del numero indicato, in italiano. Per esempio, se numero e 4301 allora deve stampare quattro tre zero uno;
    se numero e 0 allora deve
stampare zero.
È possibile definire ulteriori funzioni ausiliarie, se servono.
La funzione stampa() deve essere ricorsiva o chiamare una vostra funzione ricorsiva.
 Caso base: numero = 0;
 Passo ricorsivo: stampa( numero/10 );
Infine, tale programma deve avere anche un main() che chiama leggi() per leggere un numero non negativo e poi chiama stampa() per stamparne le cifre in italiano.*/

#include<stdio.h>
#define getName(var) #var

void leggi(int*);
void stampa(int, int);
int conta(int);

void main(){
    int num, quanti;
    
    leggi(&num);
    
    quanti=conta(num);
    //printf("Quanti: %d\n", quanti);

    printf("Numero inserito in italiano: ");
    stampa(num, quanti);

}

void leggi(int *num){

    printf("Inserisci %s: ", getName(num));
    do{
        scanf("%d", &(*num));
        if(*num<0);
            printf("Inserisci un numero non negativo.\n")
    }while(*num<0);

}

void stampa(int num, int quanti){
    char zero, uno, due, tre, quattro, cinque, sei, sette, otto, nove; //non necessari ma per esercizio
    int pos, unity, numero;

    while(quanti>0){
        numero=num;
        pos=1;
        while(pos<quanti){
            numero=numero/10;
            pos++;
        }
        unity=numero%10;
        if(unity==0)
            printf("%s ", getName(zero));
        if(unity==1)
            printf("%s ", getName(uno));
        if(unity==2)
            printf("%s ", getName(due));
        if(unity==3)
            printf("%s ", getName(tre));
        if(unity==4)
            printf("%s ", getName(quattro));
        if(unity==5)
            printf("%s ", getName(cinque));
        if(unity==6)
            printf("%s ", getName(sei));
        if(unity==7)
            printf("%s ", getName(sette));
        if(unity==8)
            printf("%s ", getName(otto));
        if(unity==9)
            printf("%s ", getName(nove));
        quanti--;
    }
}

int conta(int num){
    
    if(num/10==0)
        return 1;
    else 
        return 1+conta(num/10);
}
