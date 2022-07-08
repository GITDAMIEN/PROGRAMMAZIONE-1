#include<stdio.h>
#define PI 3.14
int main (){
  int gradi;
  float rad=0;
  printf("Inserisci angolo in gradi da convertire in radianti\n");
  scanf("%d", &gradi);
  rad=(gradi*PI)/180;
  printf("L'equivalente in radianti è: %f\n", rad);
}