/*Esercizio 1 [11 punti] File ESA 03022021 A 1.c
Completare tutte le funzioni dichiarate ma non definite nel programma ESA 03022021 A 1.c per un vettore di interi che utilizza il valore intero ”speciale” END come terminatore.
In particolare, la funzione main() fornita produce il seguente output:
Somma: 47
Somma: 30
*/

#include <stdio.h>

#define END -1

int lenv(int v[]);
void resetv(int v[], int indexes[]);
int sumv(int v[]);

/**
 * Program entry point
 * Output:
 * Somma: 47
 * Somma: 30
 */
int main() {
    int values[] = {1, 9, 10, 6, 5, 1, 3, 0, 8, 4, END};
    int indexes[] = {3, 2, 12, 0, END};
    printf("Somma: %i\n", sumv(values));
    resetv(values, indexes);
    printf("Somma: %i\n", sumv(values));
    return 0;
}

/**
 * Restituisce il numero di elementi di un vettore di interi terminato da END.
 */
int lenv(int v[]) {
  int i, cont=0;
  
  for(i=0;v[i]!=END;i++)
    cont++;
  
  return cont;
}

/**
 * Modifica un vettore terminato da END, impostando a zero gli elementi
 * il cui indice Ã¨ elencato nel vettore indexes.
 * Anche quest'ultimo Ã¨ terminato da END
 */
void resetv(int v[], int indexes[]) {
  int i, j;
  
  for(i=0;v[i]!=END;i++)
    for(j=0;indexes[j]!=END;j++)
      if(i==indexes[j])
        v[i]=0;
  
}

/**
 * Restituisce la somma degli elementi di un vettore di interi terminato da END.
 */
int sumv(int v[]) {
  int i, sum=0;
  
  for(i=0;v[i]!=END;i++)
    sum+=v[i];
  
  return sum;
}