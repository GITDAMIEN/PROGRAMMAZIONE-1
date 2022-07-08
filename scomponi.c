/*Scrivere un sottoprogramma scomponi che ricevuto in ingresso un numero intero senz’altro strettamente positivo n lo scompone e restituisce al chiamante i fattori.
Memorizzare i valori in un array di dim max 10. Ad esempio, per n = 60 il programma trasmette i valori 2 2 3 5.*/

#include<stdio.h>
#define MAX 10

//prototipo
int scomponi(int, int []);
void stampa(int, int []);

int main (){
  int n, fino, arr[MAX];
  
  printf("Inserisci numero intero positivo da scomporre: ");
  do{
    scanf("%d", &n);
    if(n<=0)
      printf("\nValore non valido. Inserisci numero intero positivo da scomporre: ");
  }while(n<=0);
  
  fino=scomponi(n, arr);
  
  printf("I fattori che compongono %d sono:\n", n);
  stampa(fino, arr);
  
  return 0;
}

int scomponi(int num, int a[MAX]){
  int i=0, cont=2;
  
  while(num>0)
    if(num%cont==0){
      a[i]=cont;
      i++;
      num=num/cont;
    }
    else
      cont++;
  
  return i-1;
}

void stampa(int fino, int a[MAX]){
  int c;

  for(c=0;c<=fino;c++)
    printf("%3d", a[c]);
  printf("\n");

}




