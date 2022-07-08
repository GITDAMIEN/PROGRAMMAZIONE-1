#include<stdio.h>
#define D 4

int main (){
  char arr[D], p2[D];
  int i, cont=9;
  
  //chiedere input al giocatore 1
  printf("Giocatore 1: inserisci 4 valori:\n");
  
  for(i=0;i<D;i++)
    scanf(" %c", &arr[i]);
  
  //chiedere input al giocatore 2
  printf("Giocatore 2: indovina i 4 valori del giocatore 1:\n");
  
  do{
    for(i=0;i<D;i++)
      scanf(" %c", &p2[i]);
    if(p2[0]!=arr[0]||p2[1]!=arr[1]||p2[2]!=arr[2]||p2[3]!=arr[3]){
      if(cont!=0)
        printf("Tenta di nuovo! Tentativi rimasti: %d\n", cont);
      cont--;
    }
    else{
      printf("Indovinato!! La sequenza era %c%c%c%c\n", arr[0], arr[1], arr[2], arr[3]);
      cont=-1;
    }
    
  }while(cont>=0);
  
  if(p2[0]!=arr[0]||p2[1]!=arr[1]||p2[2]!=arr[2]||p2[3]!=arr[3])
    printf("Hai perso! La sequenza corretta era %c%c%c%c\n", arr[0], arr[1], arr[2], arr[3]);
  
  return 0;
  
}