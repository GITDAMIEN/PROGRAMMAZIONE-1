/*Si scriva un programma C che definisce la funzione ricorsiva int cifra_massima(int num) la quale deve restituire la cifra massima
nella rappresentazione decimale di num. Tale programma dovrà inoltre definire un main che
(1) chiede all’utente di inserire un numero non negativo,
(2) chiama la funzione cifra massima per calcolarne la cifra massima e
(3) stampa tale cifra massima trovata.
Esempi
$ ./a.out Inserisci un numero non negativo: 1232
La cifra massima di 1232 è 3
$ ./a.out Inserisci un numero non negativo: 0
La cifra massima di 0 è 0
$ ./a.out Inserisci un numero non negativo: -5
Inserisci un numero non negativo: 30756
La cifra massima di 30756 è 7 */


#include<stdio.h>
#define getName(var) #var

void leggi(int*);
int cifra_massima(int, int *);

void main(){
    int num, maxnum=0;
    
    leggi(&num);
    
    printf("La cifra massima di %d e' %d.\n", num, cifra_massima(num, &maxnum));
}

void leggi(int *num){

    printf("Inserisci %s: ", getName(num));
    do{
        scanf("%d", &(*num));
        if(*num<0)
            printf("Inserisci un numero non negativo: ");
    }while(*num<0);

}

int cifra_massima(int num, int *maxnum){

    if(num/10==0){
        if(num>(*maxnum))
            return num;
        else
            return (*maxnum);
    }
    else{
        if(num%10>(*maxnum))
            (*maxnum)=num%10;
        return cifra_massima(num/10, &(*maxnum));
    }
    
}
