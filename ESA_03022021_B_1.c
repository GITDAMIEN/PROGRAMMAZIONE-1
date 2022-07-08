/*Completare tutte le funzioni dichiarate ma non definite nel programma ESA 03022021 B 1.c per un vettore di interi che utilizza il valore intero ”speciale” END come terminatore. In particolare, la funzione main() fornita produce il seguente output:
Numero di valori: 7
Numero di valori pari: 5
Media: 9.67
*/
#include <stdio.h>

#define END -1
#define EVEN 0
#define ODD 1
#define ALL 2

int lenv(int v[], int type);
double averagev(int v[], int indexes[]);

/**
 * Program entry point
 * Numero di valori: 7
 * Numero di valori pari: 5
 * Media: 9.67
 */
int main() {
    int values[] = {1, 10, 6, 22, 0, 2, 7, END};
    printf("Numero di valori: %i\n", lenv(values, ALL));
    printf("Numero di valori pari: %i\n", lenv(values, EVEN));
    int indexes[] = {3, 2, 12, 0, END};
    printf("Media: %.2lf\n", averagev(values, indexes));
    return 0;
}

/**
 * Restituisce il numero di elementi di un vettore di interi terminato da END
 * in base alla tipologia (pari, dispari oppure sia pari che dispari, cioÃ¨ tutti),
 */
int lenv(int v[], int type) {
  int i, cont=0;
  
  if(type==ALL)
    for(i=0;v[i]!=END;i++)
      cont++;
  
  if(type==EVEN)
    for(i=0;v[i]!=END;i++)
      if(v[i]%2==0)
        cont++;
    
  if(type==ODD)
    for(i=0;v[i]!=END;i++)
      if(v[i]%2!=0)
        cont++;
  
  return cont;
}

/**
 * Restituisce la media degli elementi di un vettore di interi terminato da END
 * limitatamente agli indici elencati nel vettore indexes,
 * anche quest'ultimo Ã¨ terminato da END.
 */
double averagev(int v[], int indexes[]) {
  int i, j, somma=0, cont=0;
  double media;
  
  for(i=0;v[i]!=END;i++)
    for(j=0;indexes[j]!=END;j++)
      if(i==indexes[j]){
        somma+=v[i];
        cont++;
      }
      
  media=(double)somma/cont;
  
  return media;
}







