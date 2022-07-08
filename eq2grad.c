#include<stdio.h>

int main(){
  float a, b, c;
  
  printf("Inserisci i coefficienti a, b e c del polinomio di secondo grado ax2+bx+c=0\n");
  printf("Coefficiente di a:\n");
  scanf("%f", &a);
  
  if(a==0)
    printf("Il polinomio è di grado inferiore al secondo\n");
  else{
    printf("Coefficiente di b:\n");
    scanf("%f", &b);
    printf("Coefficiente di c:\n");
    scanf("%f", &c);
    if((b*b-4*a*c)==0)
      printf("Il polinomio ammette 2 soluzioni reali e coincidenti\n");
    else
      if((b*b-4*a*c)>0)
          printf("Il polinomio ammette 2 soluzioni reali e distinte\n");
         else
           printf("Il polinomio ammette 2 soluzioni complesse e coniugate\n");
    
  }
  return 0;
  
}