#include<stdio.h>
int main(){
  char car1;
  char car2;
  printf("Inserisci il primo carattere\n");
  scanf("%c", &car1);
  printf("Inserisci il secondo carattere\n");
  scanf("%c", &car2);
  if((car1+1)==car2)
    printf("%c è il carattere successivo di %c\n", car1, car2);
  else if((car2+1)==car1)
    printf("%c è il carattere successivo di %c\n", car2, car1);
    else
      printf("Nessuno dei due caratteri è successivo all'altro\n");
  
}
