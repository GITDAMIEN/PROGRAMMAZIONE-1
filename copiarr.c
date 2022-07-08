#include<stdio.h>
#define D 10

int main (){
  char s1[D];
  char s2[D*2];
  char trash;
  int i, j;
  
  printf("Inserisci i caratteri dell'array:\n");
  for(i=0;i<D;i++)
    scanf("%c%c", &s1[i], &trash);
  
  for(i=0,j=0;i<D;i++,j++)
    if(s1[i]=='a'||s1[i]=='e'||s1[i]=='i'||s1[i]=='o'||s1[i]=='u'||s1[i]=='A'||s1[i]=='E'||s1[i]=='I'||s1[i]=='O'||s1[i]=='U'){
      s2[j]=s1[i];
      s2[j+1]=s1[i];
      j++;
    }
    else
      s2[j]=s1[i];
  
  printf("L'array iniziale era: ");
  for(i=0;i<D;i++)
    printf("%c", s1[i]);
  printf("\nL'array creato è: ");
  for(i=0;i<D*2;i++)
      printf("%c", s2[i]);
  printf("\n");
      
  //COME STAMPARE SOLO I VALORI PIENI E NON I VUOTI??//
  //COME STAMPARE SOLO I VALORI PIENI E NON I VUOTI??//
  //COME STAMPARE SOLO I VALORI PIENI E NON I VUOTI??//
  //COME STAMPARE SOLO I VALORI PIENI E NON I VUOTI??//
  
  return 0;
}