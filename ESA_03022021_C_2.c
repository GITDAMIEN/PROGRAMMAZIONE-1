/*Si completi il file ESA 03022021 C 2.c definendo il sottoprogramma void codifica(char [], int, int) che ricevuti in ingresso un array di char, la sua dimensione e un intero k sicuramente positivo, calcola la somma di tutte le cifre di k, ottenendo cos`ı un valore intero tot e sostituisce i primi tot caratteri dell’array con il carattere successivo secondo la codifica ASCII (non serve conoscere il valore intero associato ad ogni carattere per risolvere l’esercizio) se si tratta di una lettera dell’alfabeto maiuscola o minuscola, con il carattere precedente secondo la codifica ASCII in tutti gli altri casi. Ad esempio richiamando il sottoprogramma e passando come parametri l’array
a[]={‘1’,‘a’,‘Z’,‘d’,‘8’,‘1’,‘y’,‘e’,‘c’,‘a’}
di lunghezza 10 e il valore k = 34 (la somma delle cifre vale 3 + 4 = 7), il sottoprogramma cambier`a l’array solo nelle prime 7 posizioni nel seguente modo
{‘0’,‘b’,‘[’,‘e’,‘7’,‘0’,‘z’,‘e’,‘c’,‘a’}
*/

#include<stdio.h>
#define N 10
void codifica(char [], int, int);
// altri prototipi se necessario
int somma(int);

int main(){
  char a[]={'1','a','Z','d','8','1','y','e','c','a'};
  int i;
  int num;
  printf("\n Inserisci un intero non negativo: ");
  do{
    scanf("%d",&num);
  }while(num<0);
  codifica(a,N,num);
  printf("\n");
  for(i=0;i<N;i++)
    printf("%c ",a[i]);
  
  return 0;
    
}



void codifica(char a[], int dim, int k){
  int i, tot;
  
  for(i=0;i<somma(k);i++)
    if(a[i]>='a'&&a[i]<='z'||a[i]>='A'&&a[i]<='Z')
      a[i]++;
    else
      a[i]--;

}

int somma(int k){
  int tot=0, resto;
  
  while(k>0){
    resto=k%10;
    tot+=resto;
    k/=10;
  }
  
  return tot;
}