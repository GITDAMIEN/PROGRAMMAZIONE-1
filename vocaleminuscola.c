/*Scrivere un programma che acquisisce una sequenza di caratteri s1 terminata dal carattere # (che non va considerato). Si ipotizzi inoltre che la sequenza sia al massimo
lunga 20 caratteri e venga memorizzata in un array; nel caso in cui l'utente inserisce più caratteri, gli elementi in eccesso non vengono considerati.
Il programma costruisce una nuova sequenza di caratteri s2 in un nuovo array copiando il contenuto di s1 e duplicando ciascuna VOCALE MINUSCOLA incontrata.
Infine il programma visualizza s2.
Esempio: se s1 contiene abced
s2 stampata sarà aabceed
*/

#include<stdio.h>
#define N 20

int main(){
  char s1[N], s2[N*2], bin;
  int index, in2=0, cont=0, exit=0;
    
  printf("Inserisci caratteri (massimo 20, termina con #): ");
  for(index=0;index<N&&!exit;index++){
    scanf("%c%c", &s1[index], &bin);
    if(s1[index]=='#')
      exit=1;
    else
      cont++;
  }
  
  
  
  for(index=0;index<cont;index++, in2++){
    s2[in2]=s1[index];
    if(s1[index]=='a'||s1[index]=='e'||s1[index]=='i'||s1[index]=='o'||s1[index]=='u'){
      in2++;
      s2[in2]=s1[index];
    }
  }
  
  printf("s1: ");
  for(index=0;index<cont;index++)
    printf("%c", s1[index]);
  printf("\n");
  
  printf("s2: ");
  for(index=0;index<in2;index++)
    printf("%c", s2[index]);
  printf("\n");
  
  return 0;
}