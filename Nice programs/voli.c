/*DESCRIZIONE PROGRAMMA
Si vuole realizzare un’applicazione per la gestione dei voli di una compagnia aerea. Ogni volo è caratterizzato da un codice (una stringa di al massimo 5 caratteri),
una città di partenza ed una di destinazione (due stringhe di al massimo 20 caratteri), il costo, il numero massimo di passeggeri, e il numero di posti liberi per
ciascun giorno dell’anno (per semplicità i giorni dell’anno sono rappresentati con un intero da 0 a 364). Si vogliono gestire un numero variabile di voli (al massimo 50).
All’avvio il programma presenta un menù all’utente e chiede cosa vuole fare:
0 - inserire i dati di un nuovo volo
1 - visualizzare i voli disponibili
2 - prenotare un volo specificando il codice e il giorno
3 - visualizzare il numero di posti disponibili per un volo, specificati il codice ed il giorno
4 - cancellare un volo dall’elenco
5 - mostrare tutti voli (con al massimo uno scalo) che collegano due città
6 - uscire
Il programma permette di eseguire la funzionalità richiesta dall’utente, ed al termine ripresenta il menù. Il programma termina quando viene specificata l’opzione 6.

• Implementare le strutture dati necessarie per rappresentare i voli .
• Implementare lo scheletro del programma specificando il codice che presenta il menù che permette di eseguire la selezione delle varie funzionalità;
    lasciare un commento laddove devono essere implementate le varie funzionalità.
• Implementare la funzionalità 0 stando attenti al fatto che:
    • deve esserci ancora spazio in memoria,
    • il codice del volo non deve esser già stato utilizzato altrove,
    • la città di partenza e destinazione devono essere diverse,
    • costo e posti devono essere positivi.
• Implementare la funzionalità 1.
• Implementare la funzionalità 2 verificando se c’è effettivamente posto sul volo.
• Implementare la funzionalità 3.
• Implementare la funzionalità 4.*/

    /********************************************************************************************************************************************************
    *                                                        PROGRAMMA DI GESTIONE VOLI                                                                     *    
    *********************************************************************************************************************************************************/

/*migliorabile con:
- giorni effettivi dell'anno
- orari dei voli
- scelta all'utente sull'inizializzazione dei posti liberi in modo manuale giorno per giorno, randomico o fisso alla disponibilità massima
- vincolo di lunghezza codice volo a 5 char
*/

//includo le librerie che mi servono
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#define CodeMax 5               //dimensione massima di un codice volo
#define CityMax 20              //dimensione massima del nome di una città
#define FlightsMax 50           //numero massimo di voli registrabili
#define SeatMax 10              //giorni dell'anno; messo a 10 anzichè 365 per non impazzire nei test

//type struct che mi serve per gestire il catalogo voli
typedef struct{
    char code[CodeMax+1];
    char departure[CityMax+1];
    char destination[CityMax+1];
    double price;
    int paxmax;
    int freeSeats[SeatMax];
}typeFlight;

char CodeNull[6]={'-','-','-','-','-','\0'};            //codice utilizzato per cancellare un volo
char CancelOp[3]={'-','1','\0'};                        //stringa di confronto per l'annullamento di un'operazione

void welcomeMessage(int *);                             //funzione che stampa messaggio di benvenuto
void insertFlight(typeFlight [], int *);                //funzione per la gestione dell'inserimento di un nuovo volo
void showAvailableFlights(typeFlight [], int);          //funzione per mostrare tutti i voli disponibili
void bookFlight(typeFlight [], int);                    //funzione che gestisce la prenotazione di un volo
void exitOperation(int *);                              //funzione usata per l'annullamento di un'operazione, poichè ricorrente
void noFlights();                                       //funzione che stampa il messaggio di 'nessun volo registrato'
void showAvailableSeats(typeFlight [], int);            //funzione che mostra i posti disponibili su un volo specificando codice volo e giorno
void cancelFlight(typeFlight [], int);                  //funzione che gestisce la cancellazione di un volo
void showFlightConnections(typeFlight [], int);         //funzione che mostra i voli che collegano due città
void initialize(typeFlight [], int*);                   //funzione che inizializza dei voli ad inzio programma

int main(){
    typeFlight flights[FlightsMax];                     //variabile struct contenente tutti i dati dei voli
    int closeApp=0, selection, count=0;

    initialize(flights, &count);                        

    do{
        welcomeMessage(&selection);

        //gestione back-end del menu' di selezione, con chiamata alla giusta funzione in base alla selezione dell'utente
        switch(selection){
            case 0: insertFlight(flights, &count);
                    break;
            case 1: showAvailableFlights(flights, count);
                    break;
            case 2: bookFlight(flights, count);
                    break;
            case 3: showAvailableSeats(flights, count);
                    break;
            case 4: cancelFlight(flights, count);
                    break;
            case 5: showFlightConnections(flights, count);
                    break;
            case 6: closeApp=1;
                    break;
            default: printf("\nSelezione errata. Seleziona una delle opzioni proposte.\n");
        }
    }while(!closeApp);

    printf("\nGrazie per averci fatto visita. Ti aspettiamo per il tuo prossimo volo!\n\n");
}

void welcomeMessage(int *selection){

    printf("\nBENVENUTO NEL PORTALE DI PRENOTAZIONE VOLI DI DB AIRLINES!\n\n");
    printf("Seleziona l'operazione da effettuare:\n");
    printf("0 - Inserire i dati di un nuovo volo\n");
    printf("1 - Visualizzare i voli disponibili\n");
    printf("2 - Prenotare un volo\n");
    printf("3 - Visualizzare il numero di posti disponibili per un volo\n");
    printf("4 - Cancellare un volo dall'elenco\n");
    printf("5 - Mostrare tutti voli (con al massimo uno scalo) che collegano due citta'\n");
    printf("6 - Uscire\n");
    scanf("%d", &(*selection));
}

void insertFlight(typeFlight flights[FlightsMax], int *count){          
    int index, index2, dayIndex, empty=0, abort=0, length, duplicate;
    char bin;
    //scanf("%c", &bin);

    //se trovo una posizione con un volo che era stato cancellato, mi fermo lì e sovrascrivo il nuovo volo in quella posizione anzichè in coda
    for(index=0;index<(*count)&&!empty;index++)
        if(!strcmp(flights[index].code,CodeNull)){
            empty=1;
            index--;
        }
    
    //se non ho trovato una posizione libera e count è al massimo, non ho spazio dove salvare il nuovo volo
    if((*count)>=FlightsMax-1&&!empty)
        printf("Il portale dei voli e' al completo. Prego eliminare un volo prima di poterne inserire un altro.\n");

    else{
        do{
            duplicate=0;
            scanf("%c", &bin);
            printf("\nInserisci codice del volo (-1 per annullare): ");
            fgets(flights[index].code,CodeMax+1,stdin);
            length = strlen(flights[index].code) - 1;
            if (*flights[index].code && flights[index].code[length] == '\n') 
                flights[index].code[length] = '\0';

            //printf("Code 0: %s\n", flights[index].code);

            //se è stato inserito -1, annullo tutta l'operazione
            if(!strcmp(flights[index].code,CancelOp))
                abort=1;
            //altrimenti controllo che il codice volo inserito non sia già presente in sistema
            else
                for(index2=0;index2<(*count);index2++)
                    if(!strcmp(flights[index].code,flights[index2].code)){
                        printf("Questo volo e' gia' presente nel portale.\n");
                        duplicate=1;
                    }
        }while(duplicate&&!abort);

        //se il codice volo è nuovo, proseguo con la richiesta dati
        if(!abort){
            scanf("%c", &bin);
            printf("\nInserisci citta' di partenza: ");
            fgets(flights[index].departure,CityMax+1,stdin);
            length = strlen(flights[index].departure) - 1;
            if (*flights[index].departure && flights[index].departure[length] == '\n') 
                flights[index].departure[length] = '\0';

            do{
                printf("\nInserisci citta' di destinazione: ");
                fgets(flights[index].destination,CityMax+1,stdin);
                length = strlen(flights[index].destination) - 1;
                if (*flights[index].destination && flights[index].destination[length] == '\n') 
                    flights[index].destination[length] = '\0';
                
                //controllo che non venga inserita la stessa città come partenza e destinazione
                if(!strcmp(flights[index].destination,flights[index].departure))
                    printf("Citta' di partenza e di destinazione devono essere diverse. Riprova.");
            }while(!strcmp(flights[index].destination,flights[index].departure));

            printf("\nInserisci prezzo del volo in Euro: ");
            do{
                scanf("%lf", &flights[index].price);
                if(flights[index].price<=0)
                    printf("Il prezzo deve essere positivo. Riprova: ");
            }while(flights[index].price<=0);

            printf("\nInserisci numero massimo di passeggeri sul volo: ");
            do{
                scanf("%d", &flights[index].paxmax);
                if(flights[index].paxmax<=0)
                    printf("Il numero massimo di passeggeri sul volo deve essere positivo. Riprova: ");
            }while(flights[index].paxmax<=0);

            for(dayIndex=0;dayIndex<SeatMax;dayIndex++){
                printf("\nInserisci numero di posti liberi rimasti sul volo (giorno %d di %d): ", dayIndex, SeatMax-1);

                //verifico che i posti liberi sul volo siano in linea con la capienza massima del volo
                do{
                    scanf("%d", &flights[index].freeSeats[dayIndex]);
                    if(flights[index].freeSeats[dayIndex]<0||flights[index].freeSeats[dayIndex]>flights[index].paxmax)
                        printf("Il valore deve essere compreso tra 0 e %d, riprova: ", flights[index].paxmax);
                }while(flights[index].freeSeats[dayIndex]<0||flights[index].freeSeats[dayIndex]>flights[index].paxmax);
            }

            //se il volo l'ho inserito in coda e non in uno spazio nullo nel mezzo, aumento count
            if(!empty)
                (*count)++;

            printf("Perfetto! Dati volo inseriti.\n");
        }
        else
            exitOperation(&abort);
    }
}

void showAvailableFlights(typeFlight flights[SeatMax], int count){
    int index, availabilityIndex, available;

    //se non ci sono voli registrati a sistema, stampo relativo messaggio e torno al menu' principale
    if(!count)
        noFlights();
    else{
        printf("Ecco l'elenco dei voli disponibili:\n");
        for(index=0;index<count;index++){
            if(strcmp(flights[index].code,CodeNull)){           //stampo i voli se non nulli (nulli = cancellati)
                available=0;
                for(availabilityIndex=0;availabilityIndex<SeatMax;availabilityIndex++)  //e li stampo solo se almeno in 1 giorno dell'anno hanno disponibilità
                    if(flights[index].freeSeats[availabilityIndex]!=0)
                        available=1;
                if(available){
                    printf("%2d. Codice volo: %s\n", index, flights[index].code);
                    printf("    Citta' di partenza: %s\n",flights[index].departure);
                    printf("    Citta' di destinazione: %s\n", flights[index].destination);
                    printf("    Prezzo del volo: %.2f\n", flights[index].price);
                    printf("    Posti volo massimi: %d\n\n", flights[index].paxmax);
                }
            }
        }
    }
}

void bookFlight(typeFlight flights[FlightsMax], int count){
    int index, length, exit, found, book, seatsToBook, cancel, dayToBook;
    char bin, codeToBook[CodeMax+1];

    scanf("%c", &bin);

    do{
        exit=0, found=0, book=0, cancel=0;
        //se non ci sono voli registrati a sistema, stampo relativo messaggio e torno al menu' principale
        if(!count){
            noFlights();
            exit=1;
        }

        else{
            printf("Inserisci il codice del volo da prenotare (-1 per annullare): ");
            fgets(codeToBook,CodeMax+1,stdin);
            length = strlen(codeToBook) - 1;
                if (*codeToBook && codeToBook[length] == '\n') 
                    codeToBook[length] = '\0';
            
            //se è stato inserito -1, annullo operazione
            if(!strcmp(codeToBook,CancelOp))
                exitOperation(&exit);

            //altrimenti
            else{
                //trovo la posizione del codice volo inserito
                for(index=0;index<count&&!found;index++)
                    if(!strcmp(codeToBook,flights[index].code)){
                        found=1;
                        index--;
                    }

                //se non trovo il codice lo comunico
                if(!found){
                    printf("Volo non presente. Riprova.\n");
                    scanf("%c", &bin);
                }
                //altrimenti
                else{
                    printf("Hai selezionato il volo %s che parte da %s con destinazione %s.\n", flights[index].code, flights[index].departure, flights[index].destination);
                    printf("Per quale giorno vuoi prenotare? (da 0 a %d): ", SeatMax-1);
                    do{
                        scanf("%d", &dayToBook);
                        if(dayToBook<0||dayToBook>SeatMax-1)
                            printf("Digita un giorno tra 0 e %d: ", SeatMax-1);
                    }while(dayToBook<0||dayToBook>SeatMax-1);

                    //se nel giorno richiesto non c'è disponibilità lo comunico
                    if(!flights[index].freeSeats[dayToBook]){
                        printf("Spiacenti, sul volo non ci sono piu' posti disponibili. Ritorno al menu' principale.\n");
                        exit=1;
                    }
                    else{
                        do{
                            printf("Sul volo selezionato sono rimasti %d posti disponibili.\n", flights[index].freeSeats[dayToBook]);
                            printf("Il prezzo del biglietto e' di %.2f Euro. Quanti ne vuoi prenotare? (-1 per annullare): ", flights[index].price);
                            scanf("%d", &seatsToBook);
                            if(seatsToBook==-1)
                                cancel=1;

                            //mi assicuro che il numero di posti che si vuole prenotare siano disponibili
                            if(seatsToBook>flights[index].freeSeats[dayToBook])
                                printf("Spiacenti, non ci sono abbastanza posti disponibili.\n");
                            if(seatsToBook<-1||seatsToBook==0)
                                printf("Selezione non valida.\n");
                        }while(seatsToBook>flights[index].freeSeats[dayToBook]||seatsToBook<-1||seatsToBook==0);

                        if(!cancel){
                            printf("Confermi di voler prenotare %d posti volo per un totale di %.2f Euro? (0 per confermare, -1 per annullare)", seatsToBook, (flights[index].price)*seatsToBook);
                            do{
                                scanf("%d", &cancel);
                                if (cancel!=-1&&cancel!=0)
                                    printf("Seleziona 0 per confermare la prenotazione, -1 per annullare.\n");
                            }while(cancel!=-1&&cancel!=0);

                            if(!cancel){
                                flights[index].freeSeats[dayToBook]-=seatsToBook;
                                printf("Perfetto! Hai prenotato %d posti volo per un totale di %.2f Euro.\n", seatsToBook, (flights[index].price)*seatsToBook);
                                printf("Su questo volo rimangono a disposizione %d posti.\n", flights[index].freeSeats[dayToBook]);
                                printf("Ritorno al menu' principale.\n");
                                exit=1;
                            }
                            else
                                exitOperation(&exit);
                        }
                        else
                            exitOperation(&exit);
                    }
                }
            }
        }
    }while(!exit);

}

void exitOperation(int *exit){
    printf("Operazione annullata. Ritorno al menu' principale.\n");
    (*exit)=1;
}

void noFlights(){
    printf("Nessun volo registrato ancora. Procedi con l'inserimento.\n");
}

void showAvailableSeats(typeFlight flights[FlightsMax], int count){
    char flightToCheck[CodeMax+1], bin;
    int length, index, found, exit, dayToCheck;

    scanf("%c", &bin);

    //se non ci sono voli registrati a sistema, stampo relativo messaggio e torno al menu' principale
    if(!count)
        noFlights();
    
    else{
        do{
            exit=0, found=0;
            printf("Inserisci il codice del volo di cui vuoi controllare la disponibilita' (-1 per annullare): ");
            fgets(flightToCheck,CodeMax+1,stdin);
            length = strlen(flightToCheck) - 1;
                if (*flightToCheck && flightToCheck[length] == '\n') 
                    flightToCheck[length] = '\0';
            
            printf("Codice volo inserito: %s\n", flightToCheck);

            //se è stato inserito -1, annullo l'operazione e torno al menù principale
            if(!strcmp(flightToCheck,CancelOp))
                exitOperation(&exit);
            
            //altrimenti
            else{
                //cerco la posizione del volo
                for(index=0;index<count&&!found;index++){
                    if(!strcmp(flightToCheck, flights[index].code)){
                        found=1;
                        index--;
                    }
                    //printf("Index: %d, Code: %s.\n", index, flights[index].code);
                }

                //printf("Index: %d\n", index);

                //se il codice non è presente lo comunico
                if(!found){
                    printf("Il codice non e' presente in sistema. Riprova.\n");
                    scanf("%c", &bin);
                }
            }
        }while(!found&&!exit);

        if(!exit){
            printf("Indicami per quale giorno vuoi controllare le disponibilita' (da 0 a %d): ", SeatMax);
            do{
                scanf("%d", &dayToCheck);
                if(dayToCheck<0||dayToCheck>SeatMax)
                    printf("Il giorno deve essere tra 0 e %d. Riprova: ", SeatMax);
            }while(dayToCheck<0||dayToCheck>SeatMax);

            printf("Il giorno %d, sul volo %s che parte da %s con destinazione %s, sono rimasti %d posti disponibili.\n", dayToCheck, flights[index].code, flights[index].departure, flights[index].destination, flights[index].freeSeats[dayToCheck]);
        }
    }
}

void cancelFlight(typeFlight flights[FlightsMax], int count){
    int index, exit, authorized=0, attempt, access=1234, length, found, cancel, daysIndex;
    char flightToCancel[CodeMax+1], bin;

    //se non ci sono voli registrati a sistema, stampo relativo messaggio e torno al menu' principale
    if(!count)
        noFlights();

    else{
        do{
            exit=0;
            printf("!!ATTENZIONE!! PER CANCELLARE UN VOLO DEVI AVERE I PERMESSI !!\n");
            printf("Inserisci il codice di autorizzazione: ");
            scanf("%d", &attempt);
            if(attempt!=access){
                printf("Accesso negato. Premi 0 per riprovare, qualunque altro tasto per annullare: ");
                scanf("%d", &exit);
                if(exit)
                    exitOperation(&exit);
            }
            else
                authorized=1;
        }while(!authorized&&!exit);
        
        if(!exit){
            printf("Accesso autorizzato.\n");
            do{
                found=0;
                scanf("%c",&bin);
                printf("Inserisci il codice del volo da cancellare (-1 per annullare): ");
                fgets(flightToCancel,CodeMax+1,stdin);
                length = strlen(flightToCancel) - 1;
                    if (*flightToCancel && flightToCancel[length] == '\n') 
                        flightToCancel[length] = '\0';

                //se è stato inserito -1, annullo l'operazione e torno al menù principale
                if(!strcmp(flightToCancel,CancelOp))
                    exitOperation(&exit);
                
                else{
                    //altrimenti cerco la posizione del volo
                    for(index=0;index<count&&!found;index++)
                        if(!strcmp(flights[index].code,flightToCancel)){
                            found=1;
                            index--;
                        }

                    //se non lo trovo lo comunico
                    if(!found)
                        printf("Codice volo non trovato. Riprova.\n");

                    //chiedo conferma di voler cancellare il volo
                    else{
                        printf("Stai per cancellare il volo %s con partenza da %s e destinazione %s.\n", flightToCancel, flights[index].departure, flights[index].destination);
                        do{
                            printf("Premi 1 per cancellare il volo, -1 per annullare l'operazione: ");
                            scanf("%d", &cancel);
                        }while(cancel!=1&&cancel!=-1);

                        //azzero tutti i valori del volo, rendendolo nullo
                        if(cancel==1){
                            strcpy(flights[index].code,CodeNull);
                            strcpy(flights[index].departure,CodeNull);
                            strcpy(flights[index].destination,CodeNull);
                            flights[index].price=0;
                            flights[index].paxmax=0;
                            for(daysIndex=0;daysIndex<SeatMax;daysIndex++)
                                flights[index].freeSeats[daysIndex]=0;
                            printf("Volo cancellato.\n");
                        }

                        else
                            exitOperation(&exit);
                    }
                }
            }while(!found&&!exit);
        }
    }
}

void showFlightConnections(typeFlight flights[FlightsMax], int count){
    int index, index2, daysIndex, length, exit=0, found=0, direct=0, indirect=0, samecity;
    char city1ToFind [CityMax+1], city2ToFind [CityMax+1], bin;

    scanf("%c", &bin);

    //se non ci sono voli registrati a sistema, stampo relativo messaggio e torno al menu' principale
    if(!count)
        noFlights();

    else{
        do{
            printf("Inserisci citta' di partenza (-1 per annullare): ");
            fgets(city1ToFind, CityMax+1,stdin);
            length = strlen(city1ToFind) - 1;
                    if (*city1ToFind && city1ToFind[length] == '\n') 
                        city1ToFind[length] = '\0';

            //se è stato inserito -1, annullo l'operazione e torno al menù principale
            if(!strcmp(city1ToFind,CancelOp))
                exitOperation(&exit);
            
            //cerco nel portale la città inserita
            for(index=0;index<count&&!exit&&!found;index++)
                if(!strcmp(city1ToFind,flights[index].departure)||!strcmp(city1ToFind,flights[index].destination))
                    found=1;

            //se non viene trovata, lo comunico
            if(!found&&!exit)
                printf("Nessun volo parte da questa citta'. Riprova.\n");

        }while(!found&&!exit);

        if(!exit){
            do{
                found=0, samecity=0;
                printf("Inserisci citta' di destinazione (-1 per annullare): ");
                fgets(city2ToFind, CityMax+1,stdin);
                length = strlen(city2ToFind) - 1;
                    if (*city2ToFind && city2ToFind[length] == '\n') 
                        city2ToFind[length] = '\0';

                //se è stato inserito -1, annullo l'operazione e torno al menù principale
                if(!strcmp(city2ToFind,CancelOp))
                    exitOperation(&exit);

                if(!exit){
                    //mi assicuro che non sia stata inserita la stessa città 2 volte
                    if(!strcmp(city1ToFind,city2ToFind)){
                        printf("Hai inserito due volte %s. Le due citta' devono essere diverse. Riprova.\n", city1ToFind);
                        samecity=1;
                    }
                    else
                        //verifico quindi che la seconda città richiesta sia presente nel portale
                        for(index=0;index<count&&!found;index++)
                            if(!strcmp(city2ToFind,flights[index].departure)||!strcmp(city2ToFind,flights[index].destination))
                                found=1;
                }
                    
                //se non viene trovata, lo comunico
                if(!samecity)
                    printf("Non e' presente alcun collegamento da %s a %s. Riprova.\n", city1ToFind, city2ToFind);

            }while(!exit&&!found);

            //a questo punto ho registrato le 2 città tra cui mostrare le connessioni.

            if(!exit){   //stampa connessioni senza scalo e con 1 scalo

                //senza scalo (diretti)
                printf("\nVoli diretti da %s a %s:\n", city1ToFind, city2ToFind);
                for(index=0;index<count;index++)
                    if((!strcmp(flights[index].departure,city1ToFind)&&!strcmp(flights[index].destination,city2ToFind))){
                        printf("\tVolo numero: %s\n", flights[index].code);
                        printf("\tDisponibile nei giorni:");
                        for(daysIndex=0;daysIndex<SeatMax;daysIndex++)
                            if(flights[index].freeSeats[daysIndex]>0)
                                printf("%3d", daysIndex);
                        direct=1;
                        printf("\n\n");
                    }
                if(!direct)
                    printf("\tNessun volo diretto da %s a %s.\n\n", city1ToFind, city2ToFind);

                //con 1 scalo
                printf("Voli che collegano %s a %s con uno scalo:\n", city1ToFind, city2ToFind);
                for(index=0;index<count;index++)
                    if(!strcmp(city1ToFind,flights[index].departure))
                        for(index2=0;index2<count;index2++)
                            if(!strcmp(flights[index].destination,flights[index2].departure)&&!strcmp(city2ToFind,flights[index2].destination)){
                                printf("\tVolo numero %s + volo numero %s, con scalo a %s\n", flights[index].code, flights[index2].code, flights[index].destination);
                                printf("\tDisponibile nei giorni:");
                                for(daysIndex=0;daysIndex<SeatMax;daysIndex++)
                                    if(flights[index].freeSeats[daysIndex]>0&&flights[index2].freeSeats[daysIndex]>0)
                                    printf("%3d", daysIndex);
                                indirect=1;
                                printf("\n\n");
                            }
                
                //se non ho trovato nessun volo indiretto
                if(!indirect)
                    printf("\tNessun volo indiretto da %s a %s.\n", city1ToFind, city2ToFind);
            }
        }
    }
}

void initialize(typeFlight flights[FlightsMax], int *count){
    int dayIndex;
    srand(time(NULL));
    char parigi[7]={'P','a','r','i','g','i','\0'};
    char roma[5]={'R','o','m','a','\0'};
    char londra[7]={'L','o','n','d','r','a','\0'};
    char verona[7]={'V','e','r','o','n','a','\0'};
    char code0[6]={'8','9','h','j','i','\0'};
    char code1[6]={'8','7','h','j','i','\0'};
    char code2[6]={'8','6','h','j','i','\0'};
    char code3[6]={'8','5','h','j','i','\0'};
    char code4[6]={'8','3','h','j','i','\0'};

    //genero volo 1
    strcpy(flights->code,code0);
    strcpy(flights->departure,parigi);
    strcpy(flights->destination,londra);
    flights->price=35.50;
    flights->paxmax=50;
    for(dayIndex=0;dayIndex<SeatMax;dayIndex++)
        flights->freeSeats[dayIndex]=rand()%(flights->paxmax);
    (*count)++;
    
    //genero volo 2
    strcpy((flights+1)->code,code1);
    strcpy((flights+1)->departure,parigi);
    strcpy((flights+1)->destination,roma);
    (flights+1)->price=32.10;
    (flights+1)->paxmax=75;
    for(dayIndex=0;dayIndex<SeatMax;dayIndex++)
        (flights+1)->freeSeats[dayIndex]=rand()%((flights+1)->paxmax);
    (*count)++;

    //genero volo 3
    strcpy((flights+2)->code,code2);
    strcpy((flights+2)->departure,verona);
    strcpy((flights+2)->destination,roma);
    (flights+2)->price=15.20;
    (flights+2)->paxmax=50;
    for(dayIndex=0;dayIndex<SeatMax;dayIndex++)
        (flights+2)->freeSeats[dayIndex]=rand()%((flights+2)->paxmax);
    (*count)++;

    //genero volo 4
    strcpy((flights+3)->code,code3);
    strcpy((flights+3)->departure,verona);
    strcpy((flights+3)->destination,roma);
    (flights+3)->price=22.30;
    (flights+3)->paxmax=50;
    for(dayIndex=0;dayIndex<SeatMax;dayIndex++)
        (flights+3)->freeSeats[dayIndex]=rand()%((flights+3)->paxmax);
    (*count)++;

    //genero volo 5
    strcpy((flights+4)->code,code4);
    strcpy((flights+4)->departure,verona);
    strcpy((flights+4)->destination,parigi);
    (flights+4)->price=21;
    (flights+4)->paxmax=50;
    for(dayIndex=0;dayIndex<SeatMax;dayIndex++)
        (flights+4)->freeSeats[dayIndex]=rand()%((flights+4)->paxmax);
    (*count)++;

    printf("\n>>> %d voli precaricati. <<<\n", *count);

}
