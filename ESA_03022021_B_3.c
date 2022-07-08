/*Si completi il file ESA 03022021 B 3.c in modo che il programma:
-) dichiari una matrice di nome M, di dimensione NxN (dove N `e definito a inizio programma come N=3), di numeri decimali;
-) chieda all’utente l’inserimento di un valore (Key) decimale;
-) inizializzi la matrice tale che le righe pari (incluso riga 0) abbiano numeri random compresi tra 0.00 e 20.00 mentre le righe dispari abbiano numeri random compresi tra 0.00 e 10.00;
-) stampi M e Key. Un esempio con N=3 e 4.00 inserito dall’utente come Key `e il seguente:
M:
14.00 14.00 3.00
1.00 4.00 6.00
18.00 15.00 15.00
Key:
4.00
-) implementi la ricerca di Key in M. Se esiste (almeno una volta), si stampi la riga e la colonna corrispondenti. Altrimenti si stampi -not found-.
*/
//ESA_03022021_B_3.c


#include <stdio.h>
#include <stdlib.h>
#define N 3
/*
 ulteriori direttive di pre-processing
*/

int main(void) {
  float M[N][N], key;
  int i, j, flag=0;
    /*
    dichiarazioni
    */
    
    srand(2);
    /*
     inizializzazioni:
     */
    for(i=0;i<N;i++)
      for(j=0;j<N;j++)
        if(i%2==0)
          M[i][j]=rand()%21;
        else
          M[i][j]=rand()%11;
    
    /*
     Inserimento Key
     */
     printf("\nInserisci key: ");
     scanf("%f", &key);
    
    /*
     stampa matrice M
     */
    printf("\nMatrice: \n");
    for(i=0;i<N;i++){
      for(j=0;j<N;j++)
        printf("%.2f  ", M[i][j]);
      printf("\n");
    }
    printf("\n");
    
    
    /*
     stampa matrice Key
     */
    printf("Key:\n %.2f\n", key);
    
    /*
     ricerca di Key in M
     */
    for(i=0;i<N&&!flag;i++)
      for(j=0;j<N&&!flag;j++)
        if(M[i][j]==key)
          flag=1;
        
        
    //stampo risultato:
    if(flag)
      printf("\nTrovato in posizione M[%d][%d].\n", i-1, j-1);  //qui dovrebbe solo essere i, j, ma per qualche strano motivo che non capisco mi incrementa
    else                                                        //entrambi gli indici di 1
      printf("\n-not found-\n");
      
  
  return 0;
}

