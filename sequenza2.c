/* scrivere un programma C che legge da tastiera una sequenza di numeri di lunghezza a priori indefinita e che termina con uno 0 (che non fa parte della sequenza) e stampare quanti di essi sono primi */

#include<stdio.h>

int main (){
  int num, n, flag, cont=0;
  
  printf("Inserisci sequenza di numeri: ");
  scanf("%d", &num);
  while(num!=0){
    n=num-1;
    flag=1;
    while(n>1){
      if(num%n==0)
        flag=0;
      n--;
    }
    if(flag)
      cont++;
    scanf("%d", &num);
  }
  
  
  printf("Numeri primi inseriti: %d\n", cont);
  
  return 0;
}