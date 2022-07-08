/*Data una matrice NXN (con N=9) utilizzata per una semplificazione del gioco Sudoku. Si scriva un programma C in grado di:
• Riempire la matrice da tastiera. In ogni cella della matrice dovrà comparire soltanto un numero appartenente all’intervallo [1,9] (si devono rifiutare i valori non appartenenti all’intervallo). Nessun altro vincolo deve essere rispettato in fase di inizializzazione.
• Stampare la matrice a video.
• Chiedere all’utente l’inserimento da tastiera di un indice di riga r e un indice di colonna c (rifiutando per entrambi eventuali valori non appartenenti all’insieme {0,3,6}). Verificare se nel quadrato di dimensione 3X3 e origine nel punto (r,c), ogni valore dell’intervallo [1,9] compare esattamente 1 volta. Stampare un opportuno messaggio a video.
Ad esempio, se l’utente ha inizializzato la matrice sottostante e inserisce le coordinate (0,3) (r=0, c=3), nella sottomatrice di dimensione 3X3 evidenziata in grigio, ogni valore dell’intervallo [1,9] compare esattamente 1 volta. Il programma dovrà stampare a video un messaggio del tipo “Proprietà verificata”.
 1 2 3 8 7 5 4 5 9
 1 1 4 1 2 3 5 4 1
 3 4 7 4 6 9 6 3 2
 9 2 3 1 4 5 7 2 3
 8 1 2 1 7 6 3 1 4
 7 2 4 7 8 5 2 6 5
 6 5 4 3 2 1 1 7 6
 5 6 7 5 2 1 5 8 7
 4 1 3 5 5 7 6 9 8
*/

#include<stdio.h>
#define N 9

void stampamatrice(int [][N]);
int squarecheck(int [][N], int, int);

int main(){
  int mat[N][N];
  int riga, colonna, r, c;
  
  printf("Inserisci valori della griglia: ");
  for(riga=0;riga<N;riga++)
    for(colonna=0;colonna<N;colonna++)
      do{
        scanf("%d", &mat[riga][colonna]);
        if(mat[riga][colonna]<1||mat[riga][colonna]>9)
          printf("Valore non valido. Deve essere compreso nell'intervallo [1,9].\n");
      }while(mat[riga][colonna]<1||mat[riga][colonna]>9);
  
  stampamatrice(mat);
  printf("Inserisci indice di riga (0, 3 o 6): ");
  do{
    scanf("%d", &r);
    if(r!=0&&r!=3&&r!=6)
      printf("Inserisci indice di riga (0, 3 o 6): ");
  }while(r!=0&&r!=3&&r!=6);
  
  printf("Inserisci indice di colonna (0, 3 o 6): ");
  do{
    scanf("%d", &c);
    if(c!=0&&c!=3&&c!=6)
      printf("Inserisci indice di colonna (0, 3 o 6): ");
  }while(c!=0&&c!=3&&c!=6);
  
  if(squarecheck(mat,r,c))
    printf("Proprietà verificata.\n");
  else
    printf("Proprietà NON verificata.\n");
  
  return 0;
}

void stampamatrice(int m[][N]){
  int riga, colonna;
  
  printf("Matrice inserita:\n");
  for(riga=0;riga<N;riga++){
    for(colonna=0;colonna<N;colonna++)
      printf("%3d", m[riga][colonna]);
    printf("\n");
  }
  printf("\n");

}

int squarecheck(int m[][N], int r, int c){
  int riga, colonna, unoanove, trovato, cont=0;
  
  for(unoanove=1;unoanove<10;unoanove++){
    trovato=0;
    for(riga=r;riga<r+3;riga++)
      for(colonna=c;colonna<c+3;colonna++){
        if(m[riga][colonna]==unoanove)
          trovato=1;
      }
    if(trovato)
      cont++;
  }
  
  if(cont==9)
    return 1;
  else
    return 0;
  
}





