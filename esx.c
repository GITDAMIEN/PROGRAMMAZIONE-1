#include<stdio.h>
#define P 4
#define Q 5

char array(char [][Q], char []);

int main (){
  char M[P][Q];
  char a[P*Q];
  char bin;
  int i, j;
  
  printf("Inserisci valori matrice: ");
  for(i=0;i<P;i++)
    for(j=0;j<Q;j++)
      scanf("%c%c", &M[i][j], &bin);

  printf("\nMatrice inserita:\n");
  for(i=0;i<P;i++){
    for(j=0;j<Q;j++)
      printf("%3c", M[i][j]);
    printf("\n");
  }
  printf("\n");
  
  array(M, a);
  
  return 0;
}


char array(char M[][Q], char a[P*Q]){
  int i, j, k;
  
  i=0;
  j=0;
  k=0;
  while(i<P||j<Q){
    if(i==0){
      while(i<=P-1){
        a[k]=M[i][j];
        if(i!=P-1)
          i++;
      }
      j++;
    }
    if(i==P-1){
      while(i>0){
        a[k]=M[i][j];
        i--;
      }
      if(i==0)
        a[k]=M[i][j];
      j++;
    }
  }
  
  printf("\nArray ottenuto:");
  for(i=0;i<P*Q;i++)
    printf("%3c", a[i]);
  printf("\n");
  
  
  return 0;
}