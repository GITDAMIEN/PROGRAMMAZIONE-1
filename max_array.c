/*Si scriva una funzione max_array che riceve due array di interi original e result e la loro lunghezza length (uguale per entrambi).
La funzione deve modificare result in modo che ogni suo elemento di indice i diventi il massimo degli elementi di original con indice compreso fra 0 e i inclusi.
La funzione non deve modificare gli elementi di original. Se length è minore o uguale a 0, la funzione non deve fare nulla.
Per esempio, se original è l'array {-2,6,7,5,8,-3,0,-4,0,-1} e quindi length è 10, alla fine della funzione result deve contenere {-2,6,7,7,8,8,8,8,8,8}.
*/

#include<stdio.h>
#define N 10

void max_array(int [], int [], int);
void stampa(int [], int);

int main(){
  int original[N]={-2,6,7,5,8,-3,0,-4,0,-1};
  int result[N];
  
  printf("Array original: ");
  stampa(original, N);
  
  max_array(original,result,N);
  
  printf("Array result: ");
  stampa(result, N);
  
  return 0;
}

void max_array(int m1[], int m2[], int dim){
  int i, max=m1[0];
  
  for(i=0;i<dim;i++){
    if(m1[i]>max)
      max=m1[i];
    m2[i]=max;
  }
  
}



void stampa(int arr[], int dim){
  int i;
  
  for(i=0;i<dim;i++)
    printf("%3d", arr[i]);
  printf("\n");
  
}
