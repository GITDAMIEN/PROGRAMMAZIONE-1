/*Si scriva un programma C che definisce una funzione int next_prime(int last); che restituisce il numero primo immediatamente successivo a last.
Si utilizzi inoltre la seguente funzione main() per testarne il funzionamento:
    int main( ) {
      int number;
      int c;
      int p = 2;
      printf("Quanti numeri primi vuoi stampare? ");
      scanf("%d”, &number);
      for (c = 0; c < number; c++){
        printf("%d\n", p );
        p = next_prime( p );
      }
    }
*/

/*                         MIA SOLUZIONE CHE NON FUNZIONA !!!!!
#include<stdio.h>

//prototipo
int next_prime(int last);

int main( ){
  int number;
  int c;
  int p = 2;
  printf("Quanti numeri primi vuoi stampare? ");
  scanf("%d", &number);
  for (c = 0; c < number; c++){
    printf("%d\n", p );
    p = next_prime( p );
  }
  
  return 0;
}

int next_prime(int last){
  int flag=0;
  int i=last+1;
  int pos;
  
    for(i=last+1, pos=i/2;flag<=0;i++){
      while((pos>1)&&(i%pos!=0)){
          pos--;
      }
    if(pos>1)
      flag=1;
    }
    
  return i;
}

*/

// SOLUZIONE DEL PROF //


#include <stdio.h>

int is_prime(int n) {
  int d;
  for (d = 2; d < n; d++){
    if (n % d == 0){
      return 0;
    }
  }
  return n >= 2;
}

int next_prime( int last ) {  
  int result = last+1;
  while( !is_prime( result ) ){
    result++;
  }  
  return result;
}


int main(void) {
  int number;
  int c;
  int p = 2;

  printf("quanti numeri primi vuoi stampare? ");
  scanf("%d", &number);

  for (c = 0; c < number; c++){
    printf("%d\n", p);
    p = next_prime( p );
  }

  return 0;
}





