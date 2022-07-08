/*Si vuole realizzare un programma per la gestione di un dizionario italiano-inglese.
Definire un tipo di dato traduzione_t per rappresentare una parola in italiano e la sua corrispondente traduzione in inglese
(rappresentate con due stringhe da al massimo 30 caratteri). 
Definire in seguito un tipo dizionario_t che permette di rappresentare un dizionario contenente al massimo 100 coppie parola-traduzione.
Scrivere un programma che presenta all'utente un menù contenenti le seguenti voci:
1- inserire una nuova parola
2- visualizzazione del dizionario
3- cancellazione di una parola
4- ricerca di una parola italiana per visualizzare la corrispondente traduzione in inglese
5- caricare il dizionario da file di testo il cui nome è chiesto all'utente (stringa di la massimo 30 caratteri)
6- salvare il dizionario in un file di testo il cui nome è chiesto all'utente (stringa di la massimo 30 caratteri)
7- uscita
Una volta che l'utente inserisce la sua scelta il programma esegue la funzionalità corrispondente e ripresenta il menu finché non viene chiesto di uscire.

Note:
* implementare ciascuna funzionalità con un sottoprogramma che riceve il dizionario come parametro ed esegue il compito (richiesto chiedendo i dati all'utente,
    modificando se necessario i dati del dizionario e presentando a video gli eventuali risultati);
* assumere per semplicità che le parole (sia italiane che inglesi) non contengono spazi;
* nell'inserimento di una nuova parola tener conto del fatto che il dizionario è in grado di contenere al massimo 100 elementi quindi nel caso non ci sia più
    spazio il programma deve visualizzare un apposito messaggio di errore;
* eseguire l'inserimento senza considerare un ordine alfabetico ma appendendo la nuova coppia in fondo alla lista;
* per cancellare una parola è necessario specificare l'indice della linea che si vuole cancellare (partendo da 0);
* nella ricerca della parola, tener conto del fatto che ciascuna parola potrebbe avere più traduzioni possibili quindi potrebbero esserci più posizioni del
    dizionario che contengono la stessa parola italiana. Nel caso visualizzarle tutte;
* nel caricamento del dizionario da file, il precedente contenuto del dizionario viene  cancellato.
    Inoltre controllare durante il caricamento che non finisca lo spazio disponibile in memoria; in tale caso, le parole in eccedenza vengono scartate.
*/

