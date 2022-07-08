#include<stdio.h>
#define D 10

int main (){
  //parte dichiarativa
  char arr[D], trash;
  int i;
  
  //leggo da tastiera i valori dell'array
  printf("Inserisci i valori:\n");
  for(i=0;i<D;i++)
      scanf("%c%c", &arr[i], &trash);
  
  //stampo normale
  printf("I valori inseriti sono:");
  for(i=0;i<D;i++)
    printf("%3c", arr[i]);
  printf("\n");
  
  //stampo invertio sostituendo le vocali minuscole con *
  printf("Stampa richiesta:");
  for(i=D-1;i>=0;i--)
    if(arr[i]=='a'||arr[i]=='e'||arr[i]=='i'||arr[i]=='o'||arr[i]=='u')
      printf("  *");
    else
      printf("%3c", arr[i]);
  printf("\n");
  
  return 0;
      
}