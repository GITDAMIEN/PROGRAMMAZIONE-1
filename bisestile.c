#include<stdio.h>
int main(){
  int a;
  printf("Inserisci l'anno\n");
  scanf("%d", &a);
    if((a%4)==0&&(a%100)!=0)
      printf("%d è bisestile\n", a);
    else if((a%400)==0)
            printf("%d è bisestile\n", a);
         else
            printf("%d NON è bisestile\n", a);
  /*
  Si può anche scrivere:
  if(( year % 4 == 0  && year % 100 != 0 ) || year % 400 == 0 )
    printf("Anno %d: bisestile.\n", year );
  else 
    printf("Anno %d: non bisestile.\n", year );
  */
}