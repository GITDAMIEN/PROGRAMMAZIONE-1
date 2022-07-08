/*Si consideri la spesa al supermercato dove ogni articolo comprato è caratterizzato da un codice, un prezzo e un eventuale sconto
espresso in percentuale (che potrebbe essere 0). Si scriva un programma C che permetta di:
inserire da tastiera una sequenza a priori illimitata di articoli comprati (la sequenza termina quando viene inserito il valore -1 come
codice di un articolo, tale codice ovviamente non fa parte della sequenza).
Calcolare e stampare il numero di articoli scontati acquistati e la spesa totale.*/

#include<stdio.h>

typedef struct{
    int code;
    int price;
    int discount;
}article;

int main(){
    article piece;
    int onsale=0, tot=0;
    int valid=1;

    do{
        printf("Inserisci codice articolo: ");
        scanf("%d", &piece.code);
        if(piece.code==-1)
            valid=0;
        else{
            printf("Inserisci prezzo: ");
            scanf("%d", &piece.price);

            printf("Inserisci sconto: ");
            scanf("%d", &piece.discount);

            onsale++;
            tot+=((piece.price)-(piece.price*piece.discount/100));
        }
    }while(valid);

    printf("Sono stati acquistati %d articoli.\n", onsale);
    printf("Totale spesa: %deuro.\n", tot);

}