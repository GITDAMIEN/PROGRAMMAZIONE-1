#include<stdio.h>
#define D 10
int main (){
  int i, arr[D], somma=0, pos=0, neg=0, zeri=0;
  
  //leggo i valori da dare all'array
  printf("Inserisci %d valori:\n", D);
  for(i=0;i<D;i++)
    scanf("%d", &arr[i]);
  
  //stampo i valori nell'ordine inserito
  printf("I valori inseriti sono:");
  for(i=0;i<D;i++)
    printf("%3d", arr[i]);
  printf("\n");
  
  //stampo i valori in ordine inverso
  printf("I valori inseriti in ordine inverso sono:");
  for(i=D-1;i>=0;i--)
    printf("%3d", arr[i]);
  printf("\n");
  
  //calcolo la somma dei valori, quanti positivi, quanti negativi e quanti zeri
  for(i=0;i<D;i++){
    somma=somma+arr[i];
    if(arr[i]==0)
      zeri=zeri+1;
      else
        if(arr[i]>0)
          pos=pos+1;
        else
          neg=neg+1;
  }
  
  
  //stampo la somma dei valori, quanti positivi, quanti negativi e quanti zeri
  printf("La somma dei valori inseriti è: %d\n", somma);
  printf("Sono stati inseriti %d valori positivi\n", pos);
  printf("Sono stati inseriti %d valori negativi\n", neg);
  printf("Lo zero è stato inserito %d volte\n", zeri);
 
  return 0;
}