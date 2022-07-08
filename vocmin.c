#include<stdio.h>

int main (){
  int cont=0;
  char car, trash;
  
  printf("Inserisci carattere (# per terminare sequenza):\n");
  scanf("%c%c", &car, &trash);
  while(car!='#'){
    printf("Inserisci carattere (# per terminare sequenza):\n");
    scanf("%c%c", &car, &trash);
    if(car=='a'||car=='e'||car=='i'||car=='o'||car=='u')
      cont++;
  }
  
  printf("Sono state inserite %d vocali minuscole\n", cont);
  
  return 0;
}