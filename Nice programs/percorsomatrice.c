#include <stdlib.h>
#include <stdio.h>

#define RIGHE 7
#define COL 6

//prototipi
int conta(int mat[][COL]);
int percorso(int mat[][COL], int, int);



int main(void) {
  int i, M[RIGHE][COL]={{0,1,0,0,0,0},{0,0,1,0,0,0},{0,1,1,0,0,0},{0,1,1,0,0,0},{1,1,1,0,0,0},{1,1,0,0,0,0},{1,0,0,0,0,0}};
  int N[RIGHE][COL]={{0,1,0,0,0,0},{0,0,0,1,0,0},{0,1,1,0,0,0},{0,1,1,0,0,0},{1,1,1,0,0,0},{1,1,1,0,0,0},{1,0,1,0,0,0}};
  int c;
  c=conta(M);
  printf("\n Indice di colonna con maggior numero di 1 consecutivi: %d\n", c);
  i=0;
  while (i<COL && !percorso(M, 0, i))
    i++;
  if (i==COL)
    printf("Il percorso NON esiste.\n");
  else
    printf("Il percorso esiste.\n");
  
  c=conta(N);
  printf("\n Indice di colonna con maggior numero di 1 consecutivi: %d\n ", c);
  i=0;
  while (i<COL && !percorso(N, 0, i))
    i++;
  if (i==COL)
    printf("Il percorso NON esiste.\n");
  else
    printf("Il percorso esiste.\n");
  return(0); 
  
  
  return(0);
  
}

/* la funzione restituisce l'indice della prima colonna con il maggior numero di 1 consecutivi, -1 se non esiste */

int conta(int mat[RIGHE][COL]){
	int i, j, maxval, max_c, val;
    maxval=0;
    max_c=-1;

    for(i=0;i<COL;i++){
        j=0;
        val=0;

        while(j<RIGHE){
            while(mat[j][i]==1&&j<RIGHE){
                val++;
                j++;
            }
            if(val>maxval){
                maxval=val;
                max_c=i;
            }
            val=0;
            j++;
        }
    }

	return max_c;
	
}


/* la funzione restituisce 1 se un percorso di 1 adiacenti esiste a partire dalla riga i colonna j */
int percorso(int mat[RIGHE][COL], int i, int j) {
    
    if(i==RIGHE-2)
        if(mat[i][j]==1&&(mat[i+1][j]==1||mat[i+1][j-1]==1||mat[i+1][j+1]==1))
            return 1;
        else
            return 0;

    if(mat[i][j]==1){
        if(mat[i+1][j]==1)
            return percorso(mat,i+1,j);
        if(mat[i+1][j-1]==1)
            return percorso(mat,i+1,j-1);
        if(mat[i+1][j+1]==1)
            return percorso(mat,i+1,j+1);
    }
    else return 0;
	/*
    M[RIGHE][COL]= {{0,1,0,0,0,0},
                    {0,0,1,0,0,0},
                    {0,1,1,0,0,0},
                    {0,1,1,0,0,0},
                    {1,1,1,0,0,0},
                    {1,1,0,0,0,0},
                    {1,0,0,0,0,0}};

    N[RIGHE][COL]= {{0,1,0,0,0,0},
                    {0,0,0,1,0,0},
                    {0,1,1,0,0,0},
                    {0,1,1,0,0,0},
                    {1,1,1,0,0,0},
                    {1,1,1,0,0,0},
                    {1,0,1,0,0,0}};
*/
	
}