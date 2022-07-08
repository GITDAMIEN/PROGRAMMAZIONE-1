/*Specificare le strutture dati C necessarie ad un programma per la gestione di un archivio di album musicali (al massimo 100). Ogni Album è caratterizzato
da un titolo e un autore (entrambe stringhe di al massimo 30 caratteri), un anno di pubblicazione, il numero di tracce, la durata complessiva
(rappresentata in termini di ore, minuti e secondi); inoltre si vuole memorizzare anche il prezzo del disco ed il numero di copie disponibili per la
vendita. Scrivere poi un programma che acquisisce un numero n (definito dall’utente) di album e visualizza l’album con durata massima.*/

// programma ulteriormente implementabile con funzioni aggiuntive, un menù di scelta su che info visualizzare

#include<stdio.h>
#include<string.h>
#define N 30
#define M 100

typedef struct{
    char titolo[N+1];
    char autore[N+1];
    int anno;
    int tracce;
    struct{
        int ore;
        int minuti;
        int secondi;
    }durata;
    double prezzo;
    int copie;
}typeAlbum;

void acquisisci(typeAlbum album[M], int n);
int longestalbum(typeAlbum album[M], int num);

int main(){
    int n, num, ind;
    typeAlbum album[M];

    printf("Inserisci numero di album da registrare: ");
    scanf("%d", &n);
    num=n;

    do{
        acquisisci(album, n);
        n--;
    }while(n>0);

    ind=longestalbum(album, num);

    printf("L'album con durata massima è: %s\n", album[ind].titolo);
}

void acquisisci(typeAlbum album[M], int n){
    char bin;

    printf("\nInserisci titolo dell'album: ");
    scanf("%c", &bin);
    fgets(album[n].titolo, N+1,stdin);

    printf("\nInserisci autore dell'album: ");
    fgets(album[n].autore, N+1,stdin);

    printf("\nInserisci anno di pubblicazione dell'album: ");
    scanf("%d", &album[n].anno);

    printf("\nInserisci durata dell'album:\n");
    printf("Ore: ");
    scanf("%d", &album[n].durata.ore);

    printf("Minuti: ");
    do{
        scanf("%d", &album[n].durata.minuti);
        if(album[n].durata.minuti<0||album[n].durata.minuti>59)
            printf("Formato minuti errato. Riprova: ");
    }while(album[n].durata.minuti<0||album[n].durata.minuti>59);

    printf("Secondi: ");
    do{
        scanf("%d", &album[n].durata.secondi);
        if(album[n].durata.secondi<0||album[n].durata.secondi>59)
            printf("Formato secondi errato. Riprova: ");
    }while(album[n].durata.secondi<0||album[n].durata.secondi>59);

    printf("\nInserisci il prezzo dell'album: ");
    scanf("%f", &album[n].prezzo);

    printf("\nInserisci numero di copie disponibili per la vendita: ");
    scanf("%d", &album[n].copie);
}

int longestalbum(typeAlbum album[M], int num){
    int index, indexmax, valuemax;

    indexmax=0;
    valuemax=(((album[0].durata.ore)*360)+((album[0].durata.minuti)*60)+(album[0].durata.secondi));

    for(index=1;index<num;index++)
        if((((album[index].durata.ore)*360)+((album[index].durata.minuti)*60)+(album[index].durata.secondi))>valuemax){
            valuemax=(((album[index].durata.ore)*360)+((album[index].durata.minuti)*60)+(album[index].durata.secondi));
            indexmax=index;
        }

    return indexmax;

}