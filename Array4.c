#include<stdio.h>
#define N 20

int main(){
  //dichiarazioni
  int arr[N];
  int ris[N];
  int i, sommap, sommad;
  
  //chiedo i numeri dell'array
  printf("Inserisci i valori:\n");
  for(i=0;i<N;i++)
    scanf("%d", &arr[i]);
  
  //creo valori del secondo array
  sommap=0;
  sommad=0;
  for(i=0;i<N;i++)
    if(i%2==0){
      ris[i]=sommap+arr[i];
      sommap=sommap+arr[i];
    }
    else{
      ris[i]=sommad+arr[i];
      sommad=sommad+arr[i];
    }
  
  //stampo i valori dell'array ottenuto
  printf("Ecco i valori richiesti:");
  for(i=0;i<N;i++)
    printf("%3d", ris[i]);
  printf("\n");
  
  return 0;
  
}