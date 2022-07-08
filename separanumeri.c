#include<stdio.h>
int main(){
  //dichiarazione
  float a;
  int b;
  float c;
  
  //chiedo numero
  printf("Inserisci numero\n");
  scanf("%f", &a);
  
  /*ricavo la parte intera del numero dato (b è int)
  */
  b=a/1;
  
  /*ricavo la parte decimale del numero dato (c è float)
  */
  c=a-b;
  
  //stampo
  printf("La parte intera è: %d\n", b);
  printf("La parte decimale è: %.2f\n", c); //digitando .2f indico che voglio solo 2 cifre decimali dopo la virgola
}