#include <stdio.h>
int main( void ){
  char c;
  printf( "Inserire un carattere: ");
  scanf( "%c", &c );
  if( ( c >= 'a' && c <= 'z' ) ||
      ( c >= 'A' && c <= 'Z' ) ){
    printf( "Il carattere %c e\' una lettera.\n", c );
  } else if( c >= '0' && c <= '9' ) {
    printf( "Il carattere %c e\' un numero.\n", c );
  } else {
    printf( "Il carattere %c e\' speciale.\n", c );
  }
}