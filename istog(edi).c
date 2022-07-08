#include <stdio.h>
#define N 5

int main() {
    // inizializzo l'array di dimensione 5
    int A[N];
    // inizializzo i e j, che li utilizzo come indice e max per salvarmi il numero più grande inserito
    int i, j, max;

    // do all'utente le indicazioni sul programma
    printf("Inserisci 5 numeri positivi:\n");
    for (i = 0; i < N; i++) {
        // scanerizzo i numeri inseriti dall'utente
        scanf("%d", &A[i]);
        
        // se l'utente inserisce un numero negativo, visualizza un messaggio d'errore e il programma termina 
        if (A[i] < 0) {
            printf("Errore: hai inserito un numero negativo.");
            return 0;
        }
    }

    // imposto il primo valore come massimo provvisorio 
    max = A[0];
    // confronto tutto l'array con il max e se è maggiore, max cambia
    for (i = 1; i < N; i++)
        if (A[i] > max)
            max = A[i];
    
    // faccio un ciclo for partendo con i dal valore di max fino a 0 e un altro ciclo for con j
    // per scorrere l'array, se il valore di i è diverso da 0 e il numero è maggiore uguale di i  
    // stampo l'asterisco, se inve è minore stampo lo spazio, quando invece i è uguale a 0 stampo 
    // i valori inseriti nell'array
    for (i = max; i >= 0; i--) {
        for (j = 0; j < N; j++)
            if (i != 0) 
                if (A[j] >= i) 
                    printf("  * ");
                else 
                    printf("    ");                
            else 
                printf("%3d ", A[j]);
        printf("\n");
    }

    return 0;
}