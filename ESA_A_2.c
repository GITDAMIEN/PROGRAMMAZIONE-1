/*Completare il file ESA A 2.c scrivendo il programma calcola. In una matrice di valori interi, si definisce
dominante ogni elemento della matrice che `e strettamente maggiore di tutti gli elementi della matrice che si
trovano in basso a destra rispetto all’elemento stesso (si veda l’esempio sotto - in rosso sono riportati i valori
dominanti), non considerando per`o tra i possibili valori dominanti tutti gli elementi presenti nell’ultima colonna
e nell’ultima riga. Si realizzi un sottoprogramma calcola che ricevuta in ingresso una matrice 4X8 calcoli e
restituisca al main il numero di elementi dominanti presenti. Ad esempio, data la seguente matrice 4X8, ci
sono 5 valori dominanti; nella prima figura `e stato evidenziato in rosso il primo valore dominante (9) e l’area
in basso a destra considerata per determinare la dominanza, nella seconda figura sono stati evidenziati in rosso
tutti i valori dominanti presenti nella matrice.
*/

#include<stdio.h>
#define R 4
#define C 8

/* prototipi */
int calcola(int m[R][C]);


int main() {
  int m[R][C]={{5,9,2,4,1,7,2,4},{3,5,6,2,5,6,1,2},{1,3,4,7,8,8,3,0},{1,3,5,6,7,8,2,1}};
  int n;
  n=calcola(m);
  printf("\n Nella matrice ci sono %d valori dominanti", n);
  return (0);
}


int calcola(int m[R][C]){
  int righe1, righe2; //indici righe
  int colonne1, colonne2; //indici colonne
  int flag=1; //imposto flag che secondo me il numero in analisi è dominante
  int cont=0; //contatore di valori dominanti
  
  for(righe1=0;righe1<R-1;righe1++)  //per tutte le righe fino alla penultima
    for(colonne1=0;colonne1<C-1;colonne1++){ //per tutte le colonne fino alla penultima e riportando il flag ad 1 ad ogni ciclo
      flag=1; //ristabilisco flag ad 1 ad ogni ciclo
      for(righe2=righe1+1;righe2<R&&flag;righe2++) //confronta con tutte le righe da quella successiva a righe1 e fino all'ultima riga; esco se il flag scende a 0
        for(colonne2=colonne1+1;colonne2<C&&flag;colonne2++) //confronta con tutte le colonne da quella successiva a colonne1 e fino all'ultima colonna, finchè flag==1
          if(m[righe1][colonne1]<=m[righe2][colonne2]) //se il numero in analisi dal primo ciclo della matrice non è superiore a quello del secondo ciclo
            flag=0; //metto il flag a 0, ossia dico che non è dominante
      if(flag)  //se il flag è rimasto ad 1, il numero in analisi è dominante
        cont++; //quindi aumento il conteggio dei dominanti
    }
  
  return cont; //restituisco al main il numero di valori dominanti conteggiati
}

