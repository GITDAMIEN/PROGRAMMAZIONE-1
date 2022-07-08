/*Si scriva un programma in grado di gestire informazioni relative alla quantità di pioggia caduta in dieci città in un anno.
Si supponga che per ogni città vengano effettuate quattro misure.
Le informazioni relative ai vari eventi piovosi sono registrate in un array di strutture (struct) inizializzato da programma (ad esempio con un ciclo di letture).
Ogni struct ha la forma
typedef struct{
    char nome[10]; \\ il nome della città
    char data[5]; \\ la data rappresentata con una sequenza di 5 caratteri nel formato gg-mm
    float rain; \\ Quantità di pioggia caduta in mm
}city;
In base ad una opzione indicata dall'utente, il programma deve calcolare e visualizzare su video i seguenti risultati:
1. per ogni città, la quantità totale di pioggia caduta;
2. la città (o le città) in cui è stata rilevata la quantità totale massima di poggia;
3. il massimo scarto (la differenza massima) tra le quantità totali di pioggia nelle varie città.
*/

#include<stdio.h>
#include<math.h>

#define N 3
typedef struct{
    char nome[10];
    char data[5];
    float rain;
}city;

int main(){
    city città[N];
    int città1, città2;
    int index, index2, imax, choice, exit=0;
    float supp, rmax, scartomax;

    for(index=0;index<N;index++)
        città[index].rain=0;
    for(index=0;index<N;index++){
        printf("Inserisci nome città: ");
        scanf("%s", città[index].nome);
        printf("Inserisci data (gg-mm): ");
        scanf("%s", città[index].data);
        printf("Inserisci quantità di pioggia: "); //implementare somma cumulativa se la città è ripetuta
        scanf("%f", &supp);
        (città[index].rain)+=supp;
    }

    for(index=0, imax=0, rmax=città[0].rain;index<N;index++)
        if(città[index].rain>rmax){
            imax=index;
            rmax=città[index].rain;
        }

    scartomax=0;
    for(index=0;index<N;index++)
        for(index2=0;index2<N;index2++)
            if(fabs(città[index].rain-città[index2].rain)>scartomax){
                scartomax=fabs(città[index].rain-città[index2].rain);
                città1=index;
                città2=index2;
            }


    do{
        printf("Cosa vuoi visualizzare? Scegli:\n");
        printf("\t1. per ogni città, la quantità totale di pioggia caduta;\n");
        printf("\t2. la città (o le città) in cui è stata rilevata la quantità totale massima di pioggia;\n");
        printf("\t3. il massimo scarto (la differenza massima) tra le quantità totali di pioggia nelle varie città;\n");
        printf("\t4. Esci dal programma.\n");
        scanf("%d", &choice);
        //printf("\033c");

        switch(choice){
            case 1: for(index=0;index<N;index++)
                        printf("Quantità totale di pioggia caduta a %s: %.2fmm.\n", città[index].nome, città[index].rain);
                    break;
            case 2: printf("Città in cui è stata rilevata la quantità totale massima di pioggia: ");
                    for(index=0;index<N;index++)
                        if(città[index].rain==rmax)
                            printf("%s ", città[index].nome);
                    printf("\n");
                    break;
            case 3: printf("La scarto massimo tra le piovosità si ha avuto tra %s e %s, pari a %.2fmm.\n", città[città1].nome, città[città2].nome, scartomax);
                    break;
            case 4: exit=1;
                    printf("Fine programma.\n");
                    break;
            default: printf("Scelta non corretta, riprova.\n");
        }
    }while(!exit);



    return 0;
}
