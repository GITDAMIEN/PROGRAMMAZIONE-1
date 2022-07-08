#include<stdio.h>

int main(){
  char a, b, trash;
  
  printf("Inserisci 2 caratteri alfabetici:\n");
  scanf("%c%c", &a, &trash);
  while(!((a>='a'&&a<='z')||(a>='A'&&a<='Z'))){
    printf("Il primo valore inserito non è un carattere alfabetico\n");
    scanf("%c%c", &a, &trash);
  }
  scanf("%c%c", &b, &trash);
  while(!(b>='a'&&b<='z')&&!(b>='A'&&b<='Z')){
    printf("Il secondo valore inserito non è un carattere alfabetico\n");
    scanf("%c%c", &b, &trash);
  }
  
  if(b==(a+1))
    printf("%c è successivo a %c\n", b, a);
  else
    printf("%c non è successivo a %c\n", b, a);
  
  return 0;
}