#include<stdio.h>
#define DIM 5

int main (){
  int seq1[DIM], seq2[DIM];
  int x, y, flag=1, nIns1, nIns2;
  
  printf("Inserisci valori del primo array:\n");
  for(x=0;x<DIM;x++)
    scanf("%d", &seq1[x]);
  
  printf("Inserisci valori del secondo array:\n");
  for(x=0;x<DIM;x++)
    scanf("%d", &seq2[x]);
  
  // controllo sequenze - COPIATO DA SOLUZIONE PROF
  for(x = 0; x<DIM && flag; x++) 
  { 
    nIns1 = 0;
    nIns2 = 0;
    for(y = 0; y<DIM; y++) {
      if (seq1[x] == seq1[y]) // conto quante volte l'elemento che sto guardando di seq1 si presenta in seq1
        nIns1++;
    }
    for(y = 0; y<DIM; y++) {
      if (seq1[x] == seq2[y]) // conto quante volte l'elemento che sto guardando di seq1 si presenta in seq2
        nIns2++;
    }
  // se anche solo una volta non sono uguali , no permutazione
    if (nIns2!=nIns1) flag = 0;
  }

  if(flag)
    printf("La seconda sequenza è una permutazione della prima\n");
  else
    printf("La seconda sequenza NON è una permutazione della prima\n");

  return 0;
}