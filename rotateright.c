/*Si scriva una funzione rotateright che riceve un array di interi e la sua lunghezza e modifica l’array spostando i suoi elementi di una posizione a destra (cioè verso la fine dell’array); l’elemento che esce da destra deve rientrare da sinistra. Scrivere anche il main se si vuole testare il programma.
*/

#include<stdio.h>
#define N 10

void rotateright(int [], int);
void stampa(int [], int);

int main(){
  int arr[N]={1,2,3,4,5,6,7,8,9,0};
  
  printf("Array originale: ");
  stampa(arr,N);
  
  rotateright(arr,N);
  
  printf("Array risultato: ");
  stampa(arr, N);
  
  return 0;
}

void rotateright(int a[], int dim){
  int i, tmp;
  
  tmp=a[dim-1];
  for(i=dim-1;i>0;i--)
    a[i]=a[i-1];
  a[0]=tmp;
  
}


void stampa(int a[], int dim){
  int i;
  
  for(i=0;i<dim;i++)
    printf("%3d", a[i]);
  printf("\n");
  
}