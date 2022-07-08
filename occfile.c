/*MIO CODICE, RESO UGUALE ALLA SOLUZIONE DEL PROF, NON FUNZIONA!! NON CAPISCO...
#include<stdio.h>
#define D 4

int main(){
  int mat[D][D]={{1,2,5,5},{1,2,4,7},{13,1,65,3},{14,14,2,3}};
  int arr[D*D];
  int i, j, k=0, h, flag=0, cont1=0, cont2=0;
  
  //trascrivo tutti i valori della matrice in un array
  for(i=0;i<D;i++)
    for(j=0;j<D;j++){
      arr[k]=mat[i][j];
      k++;
    }
  
  for(k=0; k<D*D;k++){ //per ogni posizione dell'array
    for(h=0, flag=0; h<k;h++) //verifico se è già stato trovato in posizione precedente
      if(arr[h]==arr[k]) //se è un numero già verificato prima, metto il flag ad 1
        flag=1;
    if(!flag) //se non è un numero che ègià stato verificato
      for(h=k, cont1=0; h<D*D;h++) //controllo le occorrenze da k in poi
        if(arr[h]==arr[k])
          cont1++;
    if(cont1>=2)
      cont2++;
  }
  
  printf("%d elementi ricorrono almeno 2 volte.\n", cont2);
  
  return 0;
}
*/

/*CODICE DEL PROF: */
#include <stdio.h>
#define D1 4
#define D2 6

int main( ){
    int M[D1][D2]={{1,2,3,4,5,6},{2,3,9,3,3,12},{13,14,15,16,17,18},{19,20,21,22,23,24}};
    int V[D1*D2];
    int i,j;
    int k=0;
    int flag=0;
    int c1=0;
    int ctot=0;

    for(i=0;i<D1;i++)
        for(j=0;j<D2;j++){
            V[k]=M[i][j];
            k++;
        }
    
    for(k=0;k<D1*D2;k++){ //per ogni elemento dell'array
        for(i=0,flag=0;i<k;i++)  // cerco se Ã¨ gia' stato trovato in posizioni precedenti
    		if(V[i]==V[k])
       			flag=1;    //se lo trovo alzo il flag
  		if(!flag) //se il flag Ã¨ rimasto falso
     		for(i=k,c1=0;i<D1*D2;i++) //conto le occorrenze dalla pos k in poi
    			if(V[i]==V[k])
       				c1++;
  		if(c1>=2)
    		ctot++;
	}
     printf("Ci sono %d valori ripetuti almeno 2 volte",ctot);
  return(0);
}
