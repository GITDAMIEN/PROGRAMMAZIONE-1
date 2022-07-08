/*Si scriva una funzione in C, denominata cerca, che ricerchi la presenza di un elemento in un vettore di interi.

La funzione riceve in ingresso tre parametri:
1. un vettore di interi v[] nel quale ricercare il valore;
2. un un valore intero N che indica quanti elementi contiene il vettore;
3. il valore intero x che deve essere ricercato.

La funzione deve restituire un valore intero, ed in particolare:
• se il valore x è presente nel vettore, allora la funzione restituisce l’indice della posizione alla quale si trova tale valore;
• se il valore x è presente più volte, si restituisca l’indice della prima occorrenza;
• se il valore x non è presente nel vettore, si restituisca -1.*/

#include<stdio.h>
#define N 8

int cerca(int a[], int n, int x);

int main(){
  int a[N]={1,2,4,6,6,8,2,5}, x;
  
  
  printf("Inserisci valore da cercare nell'array: ");
  scanf("%d", &x);
  
  
  printf("\nEsito: %d.\n", cerca(a, N, x));
  
  return 0;
}

int cerca(int a[], int n, int x){
  int i, s=-1, flag=0;
  
  for(i=0;i<n&&!flag;i++)
    if(a[i]==x){
      s=i;
      flag=1;
    }
  
  return s;
}






