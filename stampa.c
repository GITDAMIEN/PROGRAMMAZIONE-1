/*Scrivere un sottoprogramma stampa che ricevuto in intero positivo dal main (rifiutare nel main eventuali valori non validi) stampa a video ogni cifra del numero (partendo DA DESTRA), ripetuta un numero di volte pari al valore della cifra. Ad esempio, se a stampa viene passato come parametro il numero 134 la funzione stamperà a video:
1
3 3 3
4 4 4 4            >>>>>>>> L'ESEMPIO STAMPA DA SINISTRA...COME SI FA?? <<<<<<<<
*/

#include <stdio.h>

void stampa(int);

int main() {
  int num;

  printf("Inserisci un numero intero positivo: ");
  do {
    scanf("%d", &num);
    if (num <= 0)
      printf("Valore non valido. Inserisci un numero intero positivo: ");
  } while (num <= 0);

  stampa(num);

  return 0;
}

void stampa(int num) {
  int resto, cont;

  while (num > 0) {
    resto = num % 10;
    cont = resto;
    num = num / 10;
    while (cont > 0) {
      printf("%3d", resto);
      cont--;
    }
    printf("\n");
  }
}
