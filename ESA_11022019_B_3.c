/*I punti del piano cartesiano possono essere definiti utilizzando due vettori monodimensionali di uguale dimensione, il primo per memorizzare i valori delle ascisse e il secondo per i corrispondenti valori delle ordinate. Si completi il file ESA 11022019 B 3.c in modo tale che il seguente programma (gi`a presente nello file stub):
int main(){
double xs[] = {0, -1.1, 2, 0.9}; // Ascisse
double ys[] = {0.5, 0, 1, 0}; // Ordinate
int size = 4;
double radius = 1;
print(xs, ys, size);
printf("Numero di punti fuori dal cerchio di raggio %.2lf centrato nell’origine: %i\n", radius, count_out(xs, ys, size, radius));
return 0;
}
produca il seguente risultato:
(0.00, 0.50)
(-1.10, 0.00)
(2.00, 1.00)
(0.90, 0.00)
Numero di punti fuori dal cerchio di raggio 1.00 centrato nell’origine: 2
*/

#include<stdio.h>

void print(double xs[], double ys[], int size);
int count_out(double xs[], double ys[], int size, double radius);

int main(){
  double xs[] = {0, -1.1, 2, 0.9}; // Ascisse
  double ys[] = {0.5, 0, 1, 0}; // Ordinate
  int size = 4;
  double radius = 1;
  
  print(xs, ys, size);
  printf("Numero di punti fuori dal cerchio di raggio %.2lf centrato nell’origine: %i\n", radius, count_out(xs, ys, size, radius));
  
  return 0;
  
}

void print(double xs[], double ys[], int size){
  int i;
  
  for(i=0;i<size;i++)
    printf("\n(%.2lf, %.2lf)", xs[i], ys[i]);
  printf("\n");
  
}

int count_out(double xs[], double ys[], int size, double radius){
  int i, cont=0;
  
  for(i=0;i<size;i++)
    if(xs[i]>=(-radius)&&xs[i]<=radius&&ys[i]>=(-radius)&&ys[i]<=radius)
      cont++;
  
  return cont;
}










