/*Scrivere un programma per gestire i dati di una gara dei cento metri.
Dichiarare un tipo di dato per definire (1) ciascun atleta con: nome e cognome (lunghezza massima 20 caratteri), età, tempo di gara (in secondi, con decimali);
e (2) ciascuna delle 10 batterie. Ogni batteria è caratterizzata dalla categoria (maschile o femminile, «m» o «f») e contiene un massimo di 8 atleti.
Il programma richiede anzitutto di inserire i dati degli atleti. Per ogni batteria, l’inserimento degli atleti termina quando si inserisce come nome la stringa «null».
Il programma visualizza i tempi medi di gara per ogni batteria maschile, e il numero di atlete che hanno fatto registrare un tempo inferiore alla media di
tutti gli atleti maschi.*/

#include<stdio.h>
#define N 20
#define M 8
#define B 2

typedef struct{
    char name[N+1];
    char surname[N+1];
    int age;
    double timing;
}typeAthlete;

typedef struct{
    char cat;
    typeAthlete athlete[M];
    int counter;
}typeBattery;

void acquire(typeBattery []);
double mediantiming(typeBattery []);
int betterfemales(typeBattery [], double);

int main(){
    typeBattery battery[B];
    double malemedian;
    int index;

    printf("Inserisci i dati degli atleti.\n");
    acquire(battery);
    malemedian=mediantiming(battery);

    //for(index=0;index<B;index++)
    //printf("Counter %d: %d.\n", index+1, battery[index].counter);
    //printf("\033c");
    printf("\nLa media di timing maschile è di %.4f secondi.\n", malemedian);
    printf("Le atlete che hanno fatto registrare un tempo inferiore alla media di tutti gli atleti maschi sono %d.\n\n", betterfemales(battery,malemedian));
}

void acquire(typeBattery battery[B]){
    int index, index2, stop;
    char bin;

    for(index=0;index<B;index++){
        stop=0;
        battery[index].counter=0;
        printf("Batteria %d - ", index+1);
        printf("Categoria (m/f): ");
        scanf("%c%c", &battery[index].cat, &bin);
        for(index2=0;index2<M&&!stop;index2++){
            printf("Atleta %d - ", index2+1);
            printf("Nome atleta (X per terminare): ");
            fgets(battery[index].athlete[index2].name, N+1,stdin);
            //scanf("%c", &bin);
            if(battery[index].athlete[index2].name[0]!='X'){
                printf("Cognome atleta: ");
                fgets(battery[index].athlete[index2].surname, N+1,stdin);
                //scanf("%c", &bin);
                printf("Età atleta: ");
                scanf("%d", &battery[index].athlete[index2].age);
                printf("Timing atleta (in secondi): ");
                scanf("%lf", &battery[index].athlete[index2].timing);
                //printf("%.4f", battery[index].athlete[index2].timing);
                scanf("%c", &bin);
                battery[index].counter++;
            }
            else
                stop=1;
        }
    }
}

double mediantiming (typeBattery battery[B]){
    int index, index2, count=0;
    double tot=0, malemedian;

    for(index=0;index<B;index++)
        if(battery[index].cat=='m')
            for(index2=0;index2<battery[index].counter;index2++){
                count++;
                tot+=battery[index].athlete[index2].timing;
                //printf("Count: %d\n", count);
                //printf("Tot: %.4f\n", tot);
            }

    malemedian=tot/count;
    
    return malemedian;

}

int betterfemales(typeBattery battery[B], double malemedian){
    int count=0;
    int index, index2;

    for(index=0;index<B;index++)
        if(battery[index].cat=='f')
            for(index2=0;index2<battery[index].counter;index2++)
                if(battery[index].athlete[index2].timing<malemedian)
                    count++;

    return count;
}
