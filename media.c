#include<stdio.h>

int main (){
  int cont=0, somma=0, num;
  float media;
  
  printf("Inserisci sequenza di numeri (termina con 0)\n");
  scanf("%d", &num);
  if(num!=0){
    do{
      scanf("%d", &num);
      somma=somma+num;
      cont++;
    }while(num!=0);
    
    media=(float)somma/cont;
    printf("La media dei numeri inseriti è: %.2f\n", media);
  }
  else
    printf("Sequenza indefinita\n");
  
  return 0;
}