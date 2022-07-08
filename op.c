#include<stdio.h>

int main (){
  int n1, n2, tot;
  char op, trash;
  
    printf("Inserisci 2 numeri interi:\n");
    scanf("%d%d%c", &n1, &n2, &trash);
 
  do{
    printf("Inserisci operazione da effettuare\n");
    scanf("%c%c", &op, &trash);
   
  }while(op!='+'&&op!='-'&&op!='*'&&op!='/');
  
  if(op=='*'){
    tot=n1*n2;
    printf("Il prodotto dei due numeri è: %d\n", tot);
  }
  else
    if(op=='/'){
      tot=n1/n2;
      printf("Il quoziente dei due numeri è: %d\n", tot);
    }
    else
      if(op=='+'){
        tot=n1+n2;
        printf("La somma dei due numeri è: %d\n", tot);
      }
      else
        if(op=='-'){
          tot=n1-n2;
          printf("La differenza tra i due numeri è: %d\n", tot);
        }
  
  return 0;
}