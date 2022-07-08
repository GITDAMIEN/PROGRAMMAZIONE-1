#include<stdio.h>

int main (){
  
  int ore, minuti;
  int oret, minutit, oresf, minutisf, flagsf=1, flagt=1;
  
  //leggo orario
  printf("Inserisci ore (2 cifre):\n");
  scanf("%d", &ore);
  printf("Inserisci minuti (2 cifre):\n");
  scanf("%d", &minuti);
  
  //calcolo ore a san francisco
  oresf=ore-9;
    if(oresf<0){
      oresf=24+oresf;
      flagsf=0;
    }
  minutisf=minuti;
    
  //calcolo ore a teheran
  oret=ore+3;
  minutit=minuti+30;
  if(minutit>=60){
    minutit=minutit-60;
    oret=oret+1;
  }
  if(oret>=24){
    oret=oret-24;
    flagt=0;
  }

  
  //stampo ore
  printf("L'orario inserito è: %d:%d", ore, minuti);
  printf("\nA San Francisco sono le %d:%d", oresf, minutisf);
  if(flagsf==0)
    printf(" del giorno prima");
  printf("\nA Teheran sono le %d:%d", oret, minutit);
  if(flagt==0)
    printf(" del giorno dopo");
  printf("\n");
  
  return 0;
}