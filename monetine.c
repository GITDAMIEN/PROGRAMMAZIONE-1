#include<stdio.h>
int main(){
  //dichiarazioni
  int euro;
  int cent;
  int totale_cent;
  int num_lat;
  int resto_cent;
  int resto_20cent;
  int resto2;
  int resto_10cent;
  int resto3;
  int resto_5cent;
  int resto_1cent;
  
  //esecutivo
  printf("Indica gli euro a disposizione\n");
  scanf("%d", &euro);
  printf("Indica i centesimi a disposizione\n");
  scanf("%d", &cent);
  
  //calcolo i centesimi totali
  totale_cent=euro*100+cent;
  
  //calcolo il numero di lattine acquistabili
  num_lat=totale_cent/40;
  
  //calcolo il resto
  resto_cent=totale_cent%40;
  
  //calcolo i 20 cent da restituire e il resto residuo
  resto_20cent=resto_cent/20;
  resto2=resto_cent%20;
  
  //calcolo i 10 cent da restituire e il resto residuo
  resto_10cent=resto2/10;
  resto3=resto2%10;
  
  //calcolo i 5 cent da restituire e il resto residuo
  resto_5cent=resto3/5;
  resto_1cent=resto3%5;
  
  //espongo risultati
  printf("Puoi comprare %d lattine\n", num_lat);
  printf("Il tuo resto è di %d monetine da 20 cent, %d monetine da 10 cent, %d monetine da 5 cent e %d monetine da 1 cent\n", resto_20cent, resto_10cent, resto_5cent, resto_1cent);
}