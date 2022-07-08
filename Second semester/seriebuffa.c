/*La serie “buffa” di interi è così definita: gli elementi di posizione 1, 2 e 3 valgono tutti e tre 1, e in generale l'elemento di posizione i (con i >= 4) è
uguale alla somma degli elementi di posizione i - 1 e i - 3. A partire da questa definizione si ricava ad esempio che i numeri della serie buffa di
posizione da 1 a 9 sono 1, 1, 1, 2, 3, 4, 6, 9, 13.
Scrivere la versione ricorsiva della funzione che calcola l’elemento di posizione z della serie buffa.*/

#include<stdio.h>

int buffa(int);

int main(){
    int k;

    printf("Inserisci posizione k: ");
    do{
        scanf("%d", &k);
        if(k<=0)
            printf("Inserisci un valore positivo.\n");
    }while(k<=0);

    printf("L'elemento in posizione %d della serie buffa e' %d.\n", k, buffa(k));
}

int buffa(int k){

    if(k<=3)
        return 1;
    else
        return buffa(k-1)+buffa(k-3);
}
