/*sia dato un numero intero positivo N inserito da tastiera. Si scriva un programma in linguaggio C che calcoli i numeri interi che sono divisori di N.
Dire inoltre se N è un numero primo.*/

#include<stdio.h>

int primo(int);
void divisori(int);

int main(){
  int N;
  
  printf("Inserisci numero intero positivo: ");
  do{
    scanf("%d", &N);
    if(N<=0)
      printf("Numero non valido. Inserisci numero intero positivo: ");
  }while(N<=0);
  
  if(primo(N))
    printf("%d è un numero primo\n", N);
  else{
    printf("%d NON è un numero primo\n", N);
    divisori(N);
  }
  
    
  return 0;
}


int primo(int num){
  int m, flag=1;
  
  m=num-1;
  while(m>1){
    if(num%m==0)
      flag=0;
    m--;
  }
  
  return flag;
}


void divisori(int num){
  int i;
  
  printf("I divisori di %d sono: ", num);
  for(i=2;i<num;i++)
    if(num%i==0)
      printf("%3d", i);
      printf("\n");
  
}

