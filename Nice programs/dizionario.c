/*Si vuole realizzare un programma per la gestione di un dizionario italiano-inglese.
Definire un tipo di dato traduzione_t per rappresentare una parola in italiano e la sua corrispondente traduzione in inglese (rappresentate con due stringhe
da al massimo 30 caratteri).
Definire in seguito un tipo dizionario_t che permette di rappresentare un dizionario contenente al massimo 100 coppie parola italiana e traduzione inglese.
Scrivere un programma che presenta all'utente un menù contenenti le seguenti voci:
1- inserire una nuova parola
2- visualizzazione del dizionario
3- cancellazione di una parola
4- ricerca di una parola italiana per visualizzare la corrispondente traduzione in inglese
5- uscita
Una volta che l'utente inserisce la sua scelta il programma esegue la funzionalità corrispondente e ripresenta il menu finché non viene chiesto di uscire.
Note:
* nell'inserimento di una nuova parola tener conto del fatto che il dizionario sia in grado di contenere al massimo 100 elementi quindi nel caso non ci sia
più spazio il programma deve visualizzare un apposito messaggio di errore;
* eseguire l'inserimento senza considerare un ordine alfabetico ma appendendo la nuova coppia in fondo alla lista;
* per cancellare una parola è necessario specificare l'indice della linea che si vuole cancellare (partendo da 0);
* nella ricerca della parola, tener conto del fatto che ciascuna parola potrebbe avere più traduzioni possibili quindi potrebbero esserci più posizioni del
dizionario che contengono la stessa parola italiana. Nel caso visualizzarle tutte.*/

#include<stdio.h>
#include<string.h>
#define N 30
#define MAX 10

typedef struct{
    char italianword[N+1];
    char englishword[N+1];
}traduzione_t;

typedef struct{
    traduzione_t couple[MAX];
}dizionario_t;

void visualizza(dizionario_t, int);
void cancella(dizionario_t *, int);
void ricerca(dizionario_t);
void inserisci(dizionario_t *, int *);

int main(){
    dizionario_t dictionary;
    int uscita=0, selection, count=0;

    printf("Benvenuto nel dizionario.\n");
    do{
        printf("\nMENU' PRINCIPALE.\nScegli cosa fare. Digita:\n");
        printf("1- inserire una nuova parola\n");
        printf("2- visualizzazione del dizionario\n");
        printf("3- cancellazione di una parola\n");
        printf("4- ricerca di una parola italiana per visualizzare la corrispondente traduzione in inglese\n");
        printf("5- uscita\n");
        scanf("%d", &selection);
        switch (selection){
            case 1: inserisci(&dictionary, &count);
                    break;
            case 2: visualizza(dictionary, count);
                    break;
            case 3: cancella(&dictionary, count);
                    break;
            case 4: ricerca(dictionary);
                    break;
            case 5: uscita=1;
                    break;
            default: printf("Selezione non corretta. Riprova.");
        }
    }while(!uscita);

    printf("Dizionario chiuso.\n");
    
}

void visualizza(dizionario_t dictionary, int count){
    int index;
    char nullword[6]={'-','-','-','-','-','\0'};

    printf("Visualizzazione del dizionario:\n");
    printf("    Italiano -> Inglese\n\n");
    for(index=0;index<count;index++)
        if(strcmp(dictionary.couple[index].italianword, nullword)!=0){
            printf("%2d. %s -> ", index, dictionary.couple[index].italianword);
            printf("%s\n", dictionary.couple[index].englishword);
        }
    printf("\nFine del dizionario.\n\n");

}

void cancella(dizionario_t *dictionary, int count){
    int canx=-1, index;
    char nullword[6]={'-','-','-','-','-','\0'};

    printf("Indica l'indice di riga della parola che vuoi cancellare (%d per annullare): ", MAX);
    do{
        scanf("%d", &canx);
        if(canx!=MAX)
            if(canx<0||canx>=count)
                printf("Digita un numero tra 0 e %d: ", count-1);
    }while((canx<0||canx>=count)&&canx!=MAX);
    if (canx!=MAX){
        strcpy(dictionary->couple[canx].italianword, nullword);
        strcpy(dictionary->couple[canx].englishword, nullword);
        printf("Parola cancellata.\n");
    }
    else
        printf("Operazione di cancellazione annullata.\n");
}

void ricerca(dizionario_t dictionary){
    char wordtosearch[N+1], bin;
    int index, trovato, ricomincia, ln;
    scanf("%c", &bin);
    do{
        printf("Inserisci parola italiana di cui cercare la/le traduzione/i in inglese: ");
        fgets(wordtosearch,N+1,stdin);
        ln = strlen(wordtosearch) - 1;
        if (*wordtosearch && wordtosearch[ln] == '\n') 
            wordtosearch[ln] = '\0';
        printf("Parola inserita: %s\n", wordtosearch);
        trovato=0;

        for(index=0;index<MAX;index++)
            if(!strcmp(dictionary.couple[index].italianword,wordtosearch)){ //se le stringhe sono uguali
                trovato=1;
                printf("%s -> %s.\n", wordtosearch, dictionary.couple[index].englishword);
            }
        
        if(!trovato)
            printf("Parola non presente nel dizionario.\n");

        printf("Premi 1 per cercare un'altra parola oppure 0 per tornare al menù principale: ");
        scanf("%d%c", &ricomincia, &bin);
    }while(ricomincia);

}

void inserisci(dizionario_t *dictionary, int *count){
    int ricomincia, ln;
    int index, exit;
    char bin, nullword[6]={'-','-','-','-','-','\0'};

    scanf("%c", &bin);

    do{
        exit=0;
        for(index=0;index<*count&&!exit;index++)
            if(!strcmp(dictionary->couple[index].italianword,nullword))
                exit=1;

        if(exit)
            index--;
        
        if(!exit&&(*count)>=MAX){
            printf("Il dizionario è pieno. Cancellare una parola prima di inserirne una nuova.\n");
            ricomincia=0;
        }
        else{
            printf("\nDigita la parola italiana da inserire nel dizionario: ");
            fgets(dictionary->couple[index].italianword,N+1,stdin);
            ln = strlen(dictionary->couple[index].italianword) - 1;
            if (*dictionary->couple[index].italianword && dictionary->couple[index].italianword[ln] == '\n') 
                dictionary->couple[index].italianword[ln] = '\0';
            printf("Ora inserisci la sua traduzione in inglese: ");
            fgets(dictionary->couple[index].englishword,N+1,stdin);
            ln = strlen(dictionary->couple[index].englishword) - 1;
            if (*dictionary->couple[index].englishword && dictionary->couple[index].englishword[ln] == '\n') 
                dictionary->couple[index].englishword[ln] = '\0';
            
            if(!exit)
                (*count)++;
            
            printf("\nPerfetto! La parola è stata aggiunta al dizionario.\n");
            printf("Premi 1 per inserire un'altra traduzione oppure 0 per tornare al menù principale: ");
            scanf("%d%c", &ricomincia, &bin);
        }
    }while(ricomincia);

}
