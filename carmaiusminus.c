#include <stdio.h>
int main( ){

  char car,carmaiuscolo,carminuscolo;
  scanf("%c",&car);
  carmaiuscolo=car-'a'+'A';
  carminuscolo=carmaiuscolo-'A'+'a';
  printf("\nHai inserito %c e ho trosformato in %c\n", car,carmaiuscolo);
  printf("\n Ritrasformo %c in minuscolo %c",carmaiuscolo,carminuscolo);
  return(0);
}