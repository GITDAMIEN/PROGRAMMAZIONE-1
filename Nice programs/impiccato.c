/*Scrivere un programma che implementi il gioco dell’impiccato. Il programma chiede al primo giocatore di inserire una parola di lunghezza massima 10 caratteri.
Il secondo giocatore ha a disposizione 10 tentativi per indovinare la parola. Ad ogni tentativo, il programma chiede all’utente di inserire una lettera e
visualizza i tentativi ancora disponibili. Inoltre, viene visualizzata la parola in modalità «nascosta» (es. «ciao» diventa «****»); se vengono indovinate delle
lettere, il programma le visualizza nella posizione corretta (es. se inserisco «a» la parola nascosta diventa «**a*»).
Il programma termina quando il giocatore indovina la parola oppure quando terminano i tentativi a disposizione. */

#include<stdio.h>
#include<string.h>
#define N 10

int verifica(char [], char[]);
void stampaomino(int);

int main(){
    char str[N+1], str2[N+1], lettera, bin;
    int tentativirimasti;
    int index, ricominciare, errori, trovato;

    do{
        //inizio ciclo di gioco
        printf("\033c");
        printf("Inizia il gioco!\n\nGiocatore 1, inserisci parola (massimo 10 caratteri): ");
        scanf("%s", str);
        scanf("%c", &bin);
        tentativirimasti=10, errori=0;

        //creo un secondo array con tanti * quanti la lunghezza della parola
        for(index=0;index<strlen(str);index++)
            str2[index]='*';
        printf("\033c");
        printf("Giocatore 2, tocca a te!\n");
        do{
            //richiesta di inserimento lettera al giocatore 2
            printf("\nInserisci lettera: ");
            scanf("%c%c", &lettera, &bin);
            printf("\033c");
            trovato=0;

            printf("Esito: ");
            for(index=0;str[index]!='\0';index++){
                if(str[index]==lettera){
                    trovato=1;
                    str2[index]=str[index];    //se la lettera fa parte della parola da cercare, aggiorna l'esito ottenuto da giocatore 2 (nel secondo array)
                }
            }
            str2[index]='\0';
            if(!trovato)            //se la lettera inserita non è nella parola da cercare, conta un errore in più
                errori++;

            //stampa della parola finora ottenuta dal giocatore 2
            for(index=0;str2[index]!='\0'; index++)
                printf("%c", str2[index]);
            printf("\n\n");
            //printf("Errori: %d\n", errori);         //test errori

            stampaomino(errori);        //richiamo funzione di stampa dell'omino

            tentativirimasti--;
            printf("Tentativi rimasti: %d\n", tentativirimasti);
        }while(tentativirimasti&&!verifica(str,str2));            //loop per i tentativi del giocatore 2

        //uscito dal loop per tentativi terminati oppure per parola trovata
        //stampa messaggio in base al caso
        if(verifica(str,str2))
            printf("\nComplimenti, hai vinto!\n");
        else{
            printf("\nMi spiace, hai perso!\n");
            printf("\nLa parola era: %s\n", str);
        }
        
        printf("\nPremi 0 per ricominciare, 1 per terminare: ");
        scanf("%d", &ricominciare);
    }while(!ricominciare);               //loop di restart del gioco

}

//FUNZIONE CHE CONTROLLA SE LA PAROLA E' STATA INDOVINATA
int verifica(char p1[N+1], char p2[N+1]){
    int ind, corretto=1;

    //confrontando la stringa inserita dal giocatore 1 con quella finora ottenuta dal giocatore 2
    for(ind=0;p1[ind]!='\0';ind++)
        if(p2[ind]!=p1[ind])
            corretto=0;

    return corretto;
}

//FUNZIONE CHE STAMPA L'OMINO IMPICCATO
void stampaomino(int err){

    //prima riga
    if(err>=3)
        printf("       ___\n");
    else
        printf("           \n");
    
    //seconda riga
    if(err>=4)
        printf("      |   |\n");
    else if(err>=2)
        printf("          |\n");
    else
        printf("           \n");
    
    //terza riga
    if(err>=5)
        printf("      @   |\n");
    else if(err>=2)
        printf("          |\n");
    else
        printf("           \n");

    //quarta riga
    if(err>=8)
        printf("     /|\\  |\n");       
    else if(err>=7)
        printf("     / \\  |\n");    
    else if(err>=6)
        printf("     /    |\n");
    else if(err>=2)
        printf("          |\n");
    else
        printf("           \n");

    //quinta riga
    if(err>=8)
        printf("      |   |\n");       
    else if(err>=2)
        printf("          |\n");
    else
        printf("           \n");

    //sesta riga
    if(err>=10)
        printf("     / \\  |\n");
    else if(err>=9)
        printf("     /    |\n");       
    else if(err>=2)
        printf("          |\n");
    else
        printf("           \n");

    //settima riga
    if(err>=2)
        printf("    ______|\n");     
    else if(err>=1)
        printf("    ______ \n");
    else
        printf("           \n");

      /* disegnino dell'omino completo 
                ___
               |   |
               @   |
              /|\  |
               |   |
              / \  |
             ______|
        */
    printf("\n");

}