/*Si completi il file ESA 03022021 B 2.c definendo il sottoprogramma void cifra(char [], int, int) che ricevuti in ingresso un array di char, la sua dimensione e un intero k sicuramente non negativo, sostituisce nell’array ogni carattere che corrisponde ad una cifra (tra 0 e 9) con la cifra successiva (la cifra ‘9’ verr`a sostituita con ‘0’), se la cifra pi`u significativa del numero k `e un valore pari, con la cifra precedente (la cifra ‘0’ verr`a sostituita con ‘9’), se la cifra pi`u significativa di k `e un valore dispari. Ad esempio richiamando il sottoprogramma e passando come parametri l’array
a[]={‘1’,‘a’,‘Z’,‘d’,‘9’,‘*’,‘4’,‘0’,‘2’,‘a’}
di lunghezza 10 e il valore k = 43 (con cifra pi`u significativa 4), il sottoprogramma cambier`a l’array nel seguente modo
{’2’,’a’,’Z’,’d’,’0’,’*’,’5’,’1’,’3’,’a’}
Se k = 324 (con cifra pi`u significativa 3), il sottoprogramma cambier`a l’array nel seguente modo
{‘0’,‘a’,‘Z’,‘d’,‘8’,‘*’,‘3’,‘9’,‘1’,‘a’}
Si possono definire sottoprogrammi ulteriori, se ritenuto opportuno.
*/


#include<stdio.h>
#define N 10
void cifra(char [], int, int);
// altri prototipi se necessario
int lung(int k);

int main(){
  char a[]={'1','a','Z','d','9','*','4','0','2','a'};
  int i;
  int num;
  printf("\nInserisci un intero non negativo: ");
  do{
    scanf("%d",&num);
  }while(num<0);
  cifra(a,N,num);
  printf("\n");
  for(i=0;i<N;i++)
    printf("%c ",a[i]);
  printf("\n");
  
  return 0;

}

void cifra(char a[], int dim, int k){
  int q;  
  if(lung(k)%2==0)
    for(q=0;q<dim;q++)
      if(a[q]>='0'&&a[q]<'9')
        a[q]++;
      else
        if(a[q]=='9')
          a[q]='0';
  else
    for(q=0;q<dim;q++)
      if(a[q]>'0'&&a[q]<='9')
        a[q]--;
      else
        if(a[q]=='0')
          a[q]='9';

}                                         /*  NON MI FUNZIONA.....PERCHE'????? */

int lung(int k){
  int f, resto;
  
  for(f=k;f>0;f/=10)
    resto=f%10;
    
  printf("\n%d\n", resto);
  
  return resto;
}
