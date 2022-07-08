/*Completare tutte le funzioni dichiarate ma non definite nel programma ESA 03022021 C 1.c per un particolare tipo di vettore di interi, nel quale il primo valore del vettore serve solo per indicare la lunghezza del vettore stesso e non deve essere considerato tra i suoi elementi ”validi”.
In particolare, la funzione main() fornita produce il seguente output:
15 9 22 32 12
I multipli di 3 sono: 3
0 9 0 32 12
I multipli di 3 sono: 2
*/

/**
 * Considerare per un particolare tipo di vettore di interi,
 * nel quale il primo valore del vettore serve solo per indicare la lunghezza del vettore stesso
 * e non deve essere considerato tra i suoi elementi "validi".
 */
#include <stdbool.h>  // bool, true, false
#include <stdio.h>    // printf()

void printv(int v[]);
int countv(int v[], int div);
void resetv_in_range(int v[], int start, int end);

/**
 * Program entry point
 * Output:
 * 15 9 22 32 12
 * I multipli di 3 sono: 3
 * 0 9 0 32 12
 * I multipli di 3 sono: 2
 */
int main() {
    // Il primo valore serve per sapere di quanti elementi Ã¨ composto effettivamente il vettore.
    int values[] = {5, 15, 9, 22, 32, 12};

    printv(values);
    printf("\nI multipli di %i sono: %i\n", 3, countv(values, 3));

    resetv_in_range(values, 15, 30);

    printv(values);
    printf("\nI multipli di %i sono: %i\n", 3, countv(values, 3));
    return 0;
}

/**
 * Stampa gli elementi di un vettore di interi.
 */
void printv(int v[]) {
  int i;
  
  for(i=1;i<=v[0];i++)
    printf("%3d", v[i]);
    
}

/**
 * Conta quanti sono i multipli di vi tra gli elementi di un vettore di interi.
 */
int countv(int v[], int div) {
  int i, cont=0;
  
  for(i=1;i<=v[0];i++)
    if(v[i]%div==0&&v[i]!=0)
      cont++;
  
  return cont;
}

/**
 * Resetta gli elementi di un vettore di interi il cui valore appartiene all'intervallo [start, end], estremi compresi,
 */
void resetv_in_range(int v[], int start, int end) {
  int i;
  
  for(i=1;i<v[0];i++)
    if(v[i]>=start&&v[i]<=end)
      v[i]=0;
  
}