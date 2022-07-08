/*Dato un array contentente al più 100 numeri interi. Inizializzare l’array da tastiera (il numero 99 indica la fine dell’input).
Stampare a video le terne consecutive il cui prodotto sia minore della media di tutti gli elementi del vettore. Si noti che le terne possono sovrapporsi.
Ad esempio, dato il seguente array inserito dall’utente: 4 1 1 1 1 0
Il valor medio degli elementi è 1,33. Le terne il cui prodotto sia minore a 1,33 sono: 1,1,1 (terna che inizia all’indice i=1) e 1,1,1 (terna che inzia all’indice i=2) e 1,1,0 (terna che inizia all’indice i=3).
*/

#include<stdio.h>
#define N 10

double media(int [], int);
double prodotto(int , int, int);
void stampaterne(int [], double, int);
  
int main(){
  int a[N];
  int index, cont=0, exit=0;
  double avg;
  
  printf("Inserisci i valori dell'array (digita 99 per terminare): ");
  for(index=0;index<N&&!exit;index++){
    scanf("%d", &a[index]);
    if(a[index]==99)
      exit=1;
    else
      cont++;
  }

  avg=media(a,cont);

  //stampe di test
  printf("Cont: %d\n", cont);
  printf("Media: %.2f\n", avg);

  stampaterne(a,avg,cont);

  return 0;
}

double media(int arr[N], int tot){
  int in, somma;
  
  for(in=0, somma=0;in<tot;in++)
    somma+=arr[in];
  
  return (double)somma/tot;
}

void stampaterne(int arr[], double avg, int tot){
  int in, found=0;
  
  printf("Terne consecutive con prodotto inferiore alla media dell'array:\n");
  for(in=2;in<tot;in++)
    if(prodotto(arr[in-2],arr[in-1],arr[in])<avg){
      printf("Terna trovata:%3d,%3d,%3d.\t", arr[in-2], arr[in-1], arr[in]);
      printf("Indici:%3d,%3d,%3d.\tProdotto: %.2f.\n", in-2, in-1, in, prodotto(arr[in-2],arr[in-1],arr[in]));
      found=1;
    }
  
  if(!found)
    printf("Nessuna terna trovata.\n");
}

double prodotto(int a, int b, int c){
  
  return a*b*c;
  
}

