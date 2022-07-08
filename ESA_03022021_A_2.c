/*Si completi il file ESA 03022021 A 2.c definendo il sottoprogramma void codifica(char [], int, int) che ricevuti in ingresso un array di char, la sua dimensione e un intero k sicuramente non negativo, sostituisce nell’array ogni lettera dell’alfabeto minuscola con la lettera successiva (la lettera ‘z’ verr`a sostituita con ‘a’), se la
lunghezza del numero k `e un valore pari, con la lettera precedente (la lettera ‘a’ verr`a sostituita con ‘z’), se la lunghezza di k `e un valore dispari. Ad esempio richiamando il sottoprogramma e passando come parametri l’array
a[]={‘1’,‘a’,‘Z’,‘d’,‘9’,‘*’,‘z’,‘z’,‘c’,‘a’}
di lunghezza 10 e il valore k = 34 (di lunghezza 2), il sottoprogramma cambier`a l’array nel seguente modo
{‘1’,‘b’,‘Z’,‘e’,‘9’,‘*’,‘a’,‘a’,‘d’,‘b’}
Se k = 135 (di lunghezza 3), il sottoprogramma cambier`a l’array nel seguente modo
{‘1’,‘z’,‘Z’,‘c’,‘9’,‘*’,‘y’,‘y’,‘b’,‘z’}
Si possono definire sottoprogrammi ulteriori, se ritenuto opportuno.
*/

#include<stdio.h>
#define N 10

void codifica(char [], int, int);
// altri prototipi se necessario
int lung(int);


int main(){
  char a[]={'1','a','Z','d','9','*','z','z','c','a'};
  int i;
  int num;
  printf("\nInserisci un intero non negativo: ");
  do{
    scanf("%d",&num);
  }while(num<0);
  codifica(a,N,num);
  printf("\n");
  for(i=0;i<N;i++)
    printf("%c ",a[i]);
  printf("\n");
  
  return 0;
    
}


void codifica(char a[], int n, int k){
  int r;
  lung(k);
  if(lung(k)%2==0){
    for(r=0;r<n;r++)
      if(a[r]>='a'&&a[r]<'z')
        a[r]=a[r]+1;
      else
        if(a[r]=='z')
          a[r]='a';
  }
  else
    for(r=0;r<n;r++)
      if(a[r]>'a'&&a[r]<='z')
        a[r]=a[r]-1;
      else
        if(a[r]=='a')
          a[r]='z';      
  
}

int lung(int k){
  int cont=0;
  
  while(k>0){
    cont++;
    k/=10;
  }
  
  return cont;
}
