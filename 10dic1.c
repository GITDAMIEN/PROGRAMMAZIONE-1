//Scrivi un programma che copi tutti i valori di una matrice in un array eliminando nel processo di copia tutti i valori duplicati negativi

#include<stdio.h>
#define D1 3
#define D2 5

int main (){
  int M[D1][D2];
  int A[D1*D2];
  int i, j, k=0, h, pos=-1, flag=1;
  
  printf("Inserisci i valori dell'array:\n");
  for(i=0;i<D1;i++)
    for(j=0;j<D2;j++){
      scanf("%d", &M[i][j]);
      if(M[i][j]>=0){  //se il valore inserito è positivo o nullo
        A[k]=M[i][j]; //registralo nell'array
        pos++; //incrementa la posizione massima di k registrata
        k++; //incrementa k
      }
      else /*if(M[i][j]<0)*/ { //altrimenti se il valore inserito è negativo
              if(!(i==0&&j==0)||k>0){ //se non siamo in posizione M 0 0 e nell'array c'è almeno un elemento salvato
                  for(h=k-1;h>=0&&flag;h--) //controlla nell'array se tale valore era già stato inserito
                    if(M[i][j]==A[h]) //se è un duplicato
                      flag=0; //poni il flag a 0 ed esci dal ciclo
                  if(flag){ //altrimenti
                      A[k]=M[i][j]; //registralo nell'array
                      pos++;
                      k++;
                  }                         //COMPILA MA NON SI COMPORTA COME VORREI E NON CAPISCO PERCHE'
              }
              else{ //se siamo in posizione M 0 0 o non c'è alcun elemento salvato nell'array, registralo e basta
                A[k]=M[i][j];
                pos++;
                k++;
              }
           }
    }
  
  printf("\nEcco l'array ottenuto: ");
  for(k=0;k<=pos;k++)
    printf("%3d", A[k]);
  printf("\n");
    
  
  return 0;
}