#include<stdio.h>

int main (){
  int a, b, cq, cont=0;
  
  printf("Inserisci i primi 2 numeri della sequenza:\n");
  
  scanf("%d", &a);
  if(a==99)
    printf("Sequenza non valida\n");
  else{
    scanf("%d", &b);
    if(b==99)
      printf("Sequenza non valida\n");
    else{
      while(b!=99){
        if(b==a*a)
          cont++;
        a=b;
        printf("Inserisci il prossimo valore della sequenza (termina con 99): ");
        scanf("%d", &b);
      }
      printf("Nella sequenza inserita sono presenti %d coppie di quadrati\n", cont);
    }
  }
  
  
  return 0;
}