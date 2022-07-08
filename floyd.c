/*Scrivere un programma in linguaggio C per la rappresentazione del triangolo di Floyd. Il triangolo di Floyd è un triangolo rettangolo che contiene numeri naturali, definito riempiendo le righe del triangolo con numeri consecutivi e partendo da 1 nell’angolo in alto a sinistra. Si consideri ad esempio il caso N=5. Il triangolo di Floyd e’ il seguente:
1
2 3
4 5 6
7 8 9 10
11 12 13 14 15
Il programma riceve da tastiera un numero intero N. Il programma visualizza le prime N righe del triangolo di Floyd. Suggerimento. Si osserva che il numero di valori in ogni riga corrisponde all’indice della riga: 1 valore sulla prima riga, 2 sulla seconda, 3 sulla terza.*/

#include<stdio.h>

int main (){
  int N, i, cont, r;
  
  printf("Inserisci un numero intero: ");
  scanf("%d", &N);
  
  for(i=1, cont=1;i<=N;i++){
    for(r=i;r>0;r--){
      printf("%3d", cont);
      cont++;
    }
    printf("\n");
  }
  printf("\n");
    
  
  
  return 0;
}