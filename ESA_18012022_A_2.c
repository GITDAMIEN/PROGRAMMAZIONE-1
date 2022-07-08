/*Viene dato un main in cui è già inizializzato un array di interi m. Si completi la separa che sposta nella parte iniziale dell'array tutti i suoi elementi pari e nella parte finale tutti i suoi elementi dispari. L'ordine tra gli elementi della stessa categoria deve essere mantenuto uguale a quello originale.
Esempio: 1, 2, 7, 6, 5 viene ordinato in 2, 6, 1, 7, 5
*/

                                  //NON DEL TUTTO FUNZIONANTE//
#include<stdio.h>
#define N 5

void separa(int [], int);
void stampa(int [], int);

int main(){
  int m[N]={1,2,7,6,5};
  
  printf("Array:");
  stampa(m,N);
  separa(m,N);
  printf("Array riordinato:");
  stampa(m,N);
    
  return 0;
}

void separa(int m[], int dim){
  int i, j=0, r=0, arr[dim];
  
  for(i=0;i<dim;i++)
    if(m[i]%2!=0){
      arr[j]=m[i];
      j++;
    }
    else{
      m[r]=m[i];
      r++;
    }
  
  for(i=0;i<dim-r;i++)
    if(arr[i]!=0){
      m[r]=arr[i];
      r++;
    }
  
}

void stampa(int m[], int dim){
  int i;
  
  for(i=0;i<dim;i++)
    printf("%3d", m[i]);
  printf("\n");

}

