/*Si vuole realizzare un programma che permetta di giocare al gioco del 15. In tale gioco, una scacchiera 4x4 contiene 15 pezzi (numerati da 1 a 15) ed una casella vuota (rappresentata da uno 0). Il giocatore ad ogni mossa può spostare uno dei pezzi adiacenti alla casella vuota nella casella vuota stessa. Le mosse sono specificate indicando il numero del pezzo da spostare e il gioco continua fino a quando tutti i numeri non compaiono nell’ordine numerico corretto (crescente, con la casella vuota nell’angolo in basso a destra). Nel seguente esempio:
  8  5  2  4
 11  1     7
 12 10  3 15
  9 13 14  6
le mosse possibili sono: 2, 1, 7, 3. Se il giocatore sceglie la mossa 3, le mosse possibili diventano: 3, 10, 15, 14. Nella risoluzione dell’esercizio l’inserimento può essere forzato in fase di inizializzazione della matrice (ad esempio,
int gioco[N][N]={{8,5,2,4},{11,1,0,7},{12,10,3,15},{9,13,14,6}};)
Si implementino le seguenti funzioni:
a) int valida (int gioco[N][N], int mossa); che riceve la scacchiera e una mossa e restituisce 1 se la mossa è valida, 0 altrimenti.
b) void muovi (int gioco[N][N], int mossa); che riceve la scacchiera e una mossa e aggiorna la scacchiera in base alla mossa effettuata.
c) int risolto (int gioco[N][N]); che riceve la scacchiera e restituisce 1 se il gioco èstato risolto, 0 altrimenti.
d) void stampa (int gioco[N][N]); che riceve la scacchiera e la stampa a video.
*/


#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define N 4

int risolto(int gioco[N][N], int soluzione[N][N]);
void stampa(int gioco[N][N]);
int valida(int gioco[N][N], int mossa);
void muovi(int gioco[N][N], int mossa);
int getriga(int [N][N], int);
int getcolonna(int [N][N], int);
void clearscreen();
void shuffle(int gioco[N][N]);

int main(){
  //int gioco[N][N]={0};   PER SOLUZIONE DI EDI
  //int gioco[N][N]={{8,5,2,4},{11,1,0,7},{12,10,3,15},{9,13,14,6}};    PER TEST
  int gioco[N][N]={{16,16,16,16},{16,16,16,16},{16,16,16,16},{16,16,16,16}};
  int soluzione[N][N]={{1,2,3,4},{5,6,7,8},{9,10,11,12},{13,14,15,0}};
  int mossa;
  srand(time(NULL));
  
  shuffle(gioco);
  stampa(gioco);
  do{
    printf("Inserisci pedina da spostare: ");
    do{
      scanf("%d", &mossa);
      if(mossa<1||mossa>15){
        clearscreen();
        stampa(gioco);
        printf("Mossa non valida. Inserisci un valore da 1 a 15: ");
      }
    }while(mossa<1||mossa>15);
    if(valida(gioco,mossa)){
      muovi(gioco,mossa);
      clearscreen();
      stampa(gioco);
    }
    else{
      clearscreen();
      stampa(gioco);
      printf("Mossa non valida. Riprova: \n");
    }
  }while(!risolto(gioco,soluzione));

  printf("COMPLIMENTI, HAI VINTO!!\n");

  return 0;
}

int risolto(int gioco[N][N], int soluzione[N][N]){
  int riga, colonna;

   // controllo che la matrice ottenuta sia uguale a quella della soluzione
  for(riga=0;riga<N;riga++)
    for(colonna=0;colonna<N;colonna++)
      if(gioco[riga][colonna]!=soluzione[riga][colonna])
        return 0;

  return 1;

}

void shuffle(int gioco[N][N]){
  int riga, colonna, riga1, colonna1, doppio;
  
  for(riga=0;riga<N;riga++)
    for(colonna=0;colonna<N;colonna++){
      do{
        doppio=0;
        gioco[riga][colonna]=rand()%16;
        for(riga1=0;riga1<N&&!doppio;riga1++)
          for(colonna1=0;colonna1<N&&!doppio;colonna1++)
            if((riga!=riga1||colonna!=colonna1)&&gioco[riga][colonna]==gioco[riga1][colonna1])
              doppio=1;
      }while(doppio);
    }
  
  /*       SOLUZIONE DI EDI (più efficiente?)
  
  int i;
  
  for(i = 1; i < N * N; i++){
    do{
      riga = rand() % 5;
      colonna = rand() % 5;
    }while(gioco[riga][colonna] != 0);
    gioco[riga][colonna] = i;  
  }*/
}

void stampa(int gioco[N][N]){
  int riga, colonna;

  for(riga=0;riga<N;riga++){
    for(colonna=0;colonna<N;colonna++)
      if(gioco[riga][colonna]!=0)
        printf("%3d", gioco[riga][colonna]);
      else
        printf("   ");
    printf("\n");
  }
  printf("\n");

}

int valida(int gioco[N][N], int mossa){
  int riga, colonna, rigazero, colonnazero, rigapedina, colonnapedina, diffriga, diffcol;

  rigazero=getriga(gioco,0);
  colonnazero=getcolonna(gioco,0);

  rigapedina=getriga(gioco,mossa);
  colonnapedina=getcolonna(gioco,mossa);

  //misuro la distanza tra righe e colonne della mossa e dello 0, le salvo in diffriga e diffcol
  diffriga=rigazero-rigapedina;
  diffcol=colonnazero-colonnapedina;

  //riporto la distanza in valore assoluto
  if(diffriga<0)
    diffriga=-diffriga;
  if(diffcol<0)
    diffcol=-diffcol;

  //se la distanza di una delle dimensioni è 1 e l'altra è 0, return 1(=mossa valida), altrimenti 0
  if((diffriga==0&&diffcol==1)||(diffriga==1&&diffcol==0))
    return 1;
  else
    return 0;

}

void muovi(int gioco[N][N], int mossa){
  int riga, colonna, rigazero, colonnazero, rigapedina, colonnapedina;

  rigazero=getriga(gioco,0);
  colonnazero=getcolonna(gioco,0);
  
  rigapedina=getriga(gioco,mossa);
  colonnapedina=getcolonna(gioco,mossa);

  if(valida(gioco, mossa)){
    gioco[rigazero][colonnazero]=gioco[rigapedina][colonnapedina];
    gioco[rigapedina][colonnapedina]=0;
  }

}

int getriga(int mat[N][N], int valoredacercare){
  int riga, colonna;
  
  for(riga=0;riga<N;riga++)
    for(colonna=0;colonna<N;colonna++)
      if(mat[riga][colonna]==valoredacercare)
        return riga;
}

int getcolonna(int mat[N][N], int valoredacercare){
  int riga, colonna;
  
  for(riga=0;riga<N;riga++)
    for(colonna=0;colonna<N;colonna++)
      if(mat[riga][colonna]==valoredacercare)
        return colonna;
}

void clearscreen(){
  printf("\033c");
}
