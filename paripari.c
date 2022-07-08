/*dato un numero n pari maggiore di 2, devo dare tutte le coppie di numeri primi la cui somma è n*/

#include<stdio.h>

int primo(int);

int main(){
  int n, num1, num2;
  
  printf("Inserisci numero pari maggiore di 2: ");
  do{
    scanf("%d", &n);
    if(n%2!=0||n<=2)
      printf("Numero non valido. Inserisci numero pari maggiore di 2: ");
  }while(n%2!=0||n<=2);
  
  printf("Coppie di numeri primi la cui somma è %d:\n", n);
  for(num1=n-1;num1>0;num1--)
    for(num2=n-1;num2>n/2;num2--)
      if(primo(num1)&&primo(num2)&&num1+num2==n)
        printf("%d e %d;\n", num1, num2);
  
  printf("Fine.\n");
  
  return 0;
}

int primo(int p){
  int v, flag=1;
  
  v=p-1;
  while(v>1&&flag){
    if(p%v==0)
      flag=0;
    v--;
  }
  
  return flag;
}








