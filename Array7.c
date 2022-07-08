/*Chiedere all’utente una sequenza di numeri interi che termina con l’inserimento dello 0 (e in ogni caso lunga al massimo 100 elementi). Creare un array che contenga tutti e soli valori distinti della sequenza (ovvero omettendo i duplicati).
Visualizzare l’array e il numero di elementi unici inseriti.
Variante: creare un array che contenga tutti e soli i valori che nella prima sequenza non ammettono duplicati.*/

#include<stdio.h>
#define D 100

int main(){
  int arr[D];
  int i, j, somma=0, flag=1;
  
  printf("Inserisci valori della sequenza (termina con 0, max 100 valori):\n");
  for(i=0;i<D&&flag;i++){
    scanf("%d", &arr[i]);
    if(arr[i]==0)
        flag=0;
    else
      somma++;
    j=i-1;
    while(j>0&&flag){
      if(arr[i]==arr[j]){
        i--;
        somma--;
      }
      j--;
    }
  }
  
                                         // NON HO CAPITO LA CONSEGNA DELLA VARIANTE
    
  //stampa l'array
  printf("L'array inserito è:\n");
  for(i=0;i<somma;i++)
    printf("%5d", arr[i]);
  printf("\n");
  
  printf("Gli elementi unici inseriti sono: %d\n", somma);
  
  
  return 0;
}