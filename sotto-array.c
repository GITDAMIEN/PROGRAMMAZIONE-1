/*Si scriva un programma in linguaggio C che riceva in ingresso da tastiera due array di char. Si consideri che ciascun array può contenere al massimo 30 caratteri. Il programma deve verificare se il secondo array inserito è contenuto almeno una volta all'interno del primo (ossia se il secondo array è un sotto-array del primo)
*/

#include<stdio.h>
#define N 10       //modificato a 10 per semplificazione nei test

int main(){
  char a[N], b[N], bin;
  int i, j, flag=0, cont=0;
  
  printf("Inserisci i caratteri del primo array:\n");
  for(i=0;i<N;i++)
    scanf("%c%c", &a[i], &bin);  
  
  printf("\nInserisci i caratteri del secondo array:\n");
  for(i=0;i<N;i++)
    scanf("%c%c", &b[i], &bin);
  
  printf("\nPrimo array: ");
  for(i=0;i<N;i++)
    printf("%c ", a[i]);
  
  printf("\nSecondo array: ");
  for(i=0;i<N;i++)
    printf("%c ", b[i]);
  
  for(i=0;i<N;i++){
    for(j=0;j<N&&!flag;j++)
      if(b[i]==a[j])
        flag=1;
    if(flag)
      cont++;
    flag=0;
  }
  
  if(cont==N)
    printf("\nIl secondo array è un sotto-array del primo.\n");
  else
    printf("\nIl secondo array NON è un sotto-array del primo.\n");

  return 0;
}