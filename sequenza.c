/* scrivere un programma C che legge da tastiera una sequenza di numeri di lunghezza a priori indefinita e che termina con uno 0 (che non fa parte della sequenza) e stabilisce se si tratta di una sequenza crescente di numeri */

#include<stdio.h>

int main (){
  int num, n, flag=1;
  
  printf("Inserisci sequenza di numeri: ");
  scanf("%d", &n);
  scanf("%d", &num);
  while(num!=0){
    if(num<n)
      flag=0;
    else
      n=num;
    scanf("%d", &num);
  }
  
  
  if(flag)
    printf("Sequenza crescente.\n");
  else
    printf("Seguenza NON crescente.\n");
  
  return 0;
}