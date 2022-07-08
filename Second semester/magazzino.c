/*Esercizio 08: Magazzino ricambi auto
Scrivere un programma C (matricola_lab08.c, sostituendo "matricola" col proprio numero di matricola universitaria) che faciliti il compito di sistemare dei pezzi di ricambio auto nel magazzino a seconda del loro peso al gestore di un magazzino di ricambio auto.

I ricambi auto sono di 3 tipi: gomme, paraurti e specchietti.
Dovrete implementare una bilancia con memoria e con queste funzionalità:

L'utente ad ogni interazione può scegliere:
quale tipo di pezzo pesare;
vedere lo storico delle pesate, per cui massimo N pesate definite staticamente devono rimanere salvate;
uscire dal programma;
La bilancia deve rispondere ad ogni pesata dell'utente con:
un numero progressivo che indica quante pesate sono avvenute finora;
il peso del pezzo pesato;
La bilancia deve salvare i dati della pesata appena avvenuta.


Alcuni requisiti tecnici:
Il programma deve contenere almeno il main() e una funzione pesa() per la bilancia;
Utilizzare una variabile statica all'interno di questa funzione pesa() per salvare il numero di pesate avvenute;
Usare una lista e almeno una variabile globale per salvare lo storico delle pesate;
Gestire la liberazione della memoria quando il limite massimo N di pesate mantenute in memoria viene raggiunto, ovvero gestire al momento di una nuova pesata la liberazione in memoria di un nodo, nello specifico il nodo più vecchio, e aggiungere il nodo nuovo;


Il peso dei vari pezzi varia in un range:
gomme: tra 9 e 11 kili;
paraurti = tra 18 e 22 kili;
specchietti = tra 0.1 e 1.5 kili
La pesata dei vari pezzi deve essere simulata con valori random float nel rispettivo range.
Esempio:

    
        Menu
        1. Pesa
        2. Vedi storico pesate
        0. Esci
        > 1
        Pesa cosa? (1 = gomma, 2 = paraurti, 3 = specchietto)
        > 2
        Pesata #1 => Questo paraurti pesa 20.25 kili

        Menu
        1. Pesa
        2. Vedi storico pesate
        0. Esci
        >1
        Pesa cosa? (1 = gomma, 2 = paraurti, 3 = specchietto)
        > 3
        Pesata #2 => Questo specchietto pesa 1.23 kili

        Menu
        1. Pesa
        2. Vedi storico pesate
        0. Esci
        > 2
        Pesate finora:
        1 => Paraurti, 20 kili
        2 => Specchietto, 1.2 kili
    
Si ricorda che verranno considerati nel punteggio anche la presenza di commenti e la corretta indentazione.

*/