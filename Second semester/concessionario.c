/*Scrivere un programma C  usando le seguenti strutture dati che rappresentano un concessionario con il relativo gestore e le auto vendute.

Si realizzi una funzione che prende in input un array di tipo concessionario_t ed il numero di concessionari inseriti (non è detto corrisponda alla dimensione
massima del array), e che per ogni concessionario stampi a video codice, gestore e per ogni auto immatricolata nel 2015, modello, targa e mese (in numero) dell'auto.
Il report mostrato dovrà avere il seguente formato:
    
        Conc. 0, codice 12345: gestore Paolo Rossi
        Immatricolazioni 2015:
        * mese 9: Punto, MI80980
        * mese 6: Marea, TO12567

        Conc. 1, codice 23456: gestore Luca Bianchi
        Immatricolazioni 2015:
        * mese 2: Panda, VE85980
    
Si scriva poi la funzione main per testare le funzionalità del programma sviluppato inizializzando con opportuni valori l'array di concessionario_t.*/

#define MAX_STR 30
#define MAX_TRG 7
#define MAX_AUTO_CONCE 50

typedef struct automobile {
    char modello[MAX_STR + 1];
    char targa[MAX_TRG + 1];
    int  mese_immatricolazione;
    int  anno_immatricolazione;
} auto_t;

typedef struct persona {
    char piva[MAX_STR + 1];
    char nome[MAX_STR + 1];
    char cognome[MAX_STR + 1];
} persona_t;

typedef struct concessionario{
    int       codice_concessionario;
    persona_t gestore;
    auto_t    automobili[MAX_AUTO_CONCE];    
    int       num_auto; // Numero auto inizializzate nel array automobili. 
} concessionario_t;