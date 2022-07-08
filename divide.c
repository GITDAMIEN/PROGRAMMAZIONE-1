/*Si scriva una funzione divide che riceve tre parametri: un array original di int, un array destination di double e la lunghezza dei due array (che si assume essere la stessa per entrambi). La funzione deve modificare destination in modo che ogni suo elemento in posizione i diventi l’elemento di original in posizione i diviso per i+1 (risultato con la virgola).
Per esempio, l’esecuzione del seguente programma:
#include <stdio.h>
// la funzione divide viene aggiunta qui
int main(void) {
  int i, original[]= { 5, 4, 3, 2, 1, 0 };
  double destination[6];
  divide(original, destination, 6);
  for (i = 0; i < 6; i++)
    printf("%.2f ", destination[i]);
  return 0;
}
dovrà stampare 5.00 2.00 1.00 0.50 0.20 0.00.*/

#include <stdio.h>
// la funzione divide viene aggiunta qui
void divide(int [], double [], int);

int main(void) {
  int i, original[]={5,4,3,2,1,0};
  double destination[6];
  divide(original,destination,6);

  printf("Esito:\n");
  for(i=0;i<6;i++)
    printf("%.2f ", destination[i]);
  printf("\n");

  return 0;
}


void divide(int m1[], double m2[], int dim){
  int i;
  
  for(i=0;i<dim;i++)
    m2[i]=(double)m1[i]/(i+1);
  
}


