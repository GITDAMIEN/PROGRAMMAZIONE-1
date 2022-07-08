/*Completare il programma che riceve come parametri due matrici quadrate di dimenzioni 5x5 di interi, m1 ed m2.
Scrivere il codice per la funzione calcola che valuta per ciascuna riga di entrambe le matrici quanti elementi di m1 sono maggiori dei corrispondenti elementi in m2 e restituisce l'indice di riga che ne massimizza il valore.
Nel caso in cui ci siano più righe con pari valore massimo, restituire per semplicità soltanto il primo indice.
Ad esempio, date in ingresso le matrici:
 1 2 4 3 5      1 2 4 3 2
 1 6 7 2 4      9 4 9 9 9
 5 4 3 2 1      1 6 3 5 3
 2 2 3 3 1      2 2 4 1 0
 2 4 5 8 7      1 3 5 1 6
Il sottoprogramma restituirà l'indice 4(riga di m1 con il numero massimo di valori maggiori ai corrispondenti)
*/

#include<stdio.h>
#define N 5

int calcola (int[][N], int[][N], int);
void stampa(int [][N], int);

int main(){
  int m1[N][N]={{1,2,4,3,5},
                {1,6,7,2,4},
                {5,4,3,2,1},
                {2,2,3,3,1},
                {2,4,5,8,7}};
  int m2[N][N]={{1,2,4,3,2},
                {9,4,9,9,9},
                {1,6,3,5,3},
                {2,2,4,1,0},
                {1,3,5,1,6}};
  
  printf("Matrice 1:\n");
  stampa(m1,N);
  printf("Matrice 2:\n");
  stampa(m2,N);
  printf("Indice valori massimi: %d\n", calcola(m1,m2,N));

  return 0;
}
  
int calcola (int m1[][N], int m2[][N], int dim){
  int i, j, contparz=0, contgen=0;
  int rigamax=0;
  
  for(i=0;i<dim;i++){
    for(j=0;j<dim;j++)
      if(m1[i][j]>m2[i][j])
        contparz++;
    if(contparz>contgen){
      contgen=contparz;
      rigamax=i;
    }
    contparz=0;
  }
  
  return rigamax;
}

void stampa(int m[][N], int dim){
  int i, j;
  
  for(i=0;i<dim;i++){
    for(j=0;j<dim;j++)
      printf("%3d", m[i][j]);
    printf("\n");
  }
  printf("\n");

}

