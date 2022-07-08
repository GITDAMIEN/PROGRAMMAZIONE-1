/*Una polilinea pu`o essere definita da una serie di punti che rappresentano gli estremi dei segmenti che la compongono. I punti del piano cartesiano possono essere definiti utilizzando due vettori monodimensionali di uguale dimensione, il primo per memorizzare i valori delle ascisse e il secondo per i corrispondenti valori delle
ordinate. Si completi il file ESA 11022019 C 3.c in modo tale che il seguente programma (gi`a presente nello file stub):
int main(){
double xs[] = {0, -1, 2, 1}; // Ascisse
double ys[] = {1, 0, 1, 0}; // Ordinate
int size = 4;
printf("Lunghezza della polilinea: %lf\n", length(xs, ys, size));
printf("Numero di punti nel primo quadrante: %i\n", count_in_quadrant(xs, ys, size, 1));
return 0;
}
produca il seguente risultato:
Lunghezza della polilinea: 5.990705
Numero di punti nel primo quadrante: 1
Il programma calcola la lunghezza della polilinea, utilizzando una funzione che ritorna la distanza tra due punti.
I punti della polilinea nel codice della funzione main() sono dati dalle coppie: (0, 1), (-1, 0), (2, 1) e (1, 0).
Il programma, inoltre, definisce una funzione per calcolare quanti punti appartengono ad un quadrante del piano cartesiano (valori da 1 a 4). Nel caso di esempio c’`e il solo punto (2, 1) che appartiene al primo quadranti. I punti appartenenti agli assi non vengono considerati.
*/

#include<stdio.h>
#include<math.h>

int count_in_quadrant(double xs[], double ys[], int size, int quad);
double length(double xs[], double ys[], int size);
double distance(double xs[], double ys[], int i, int j);

int main(){
  double xs[] = {0, -1, 2, 1}; // Ascisse
  double ys[] = {1, 0, 1, 0}; // Ordinate
  int size = 4;
  
  printf("Lunghezza della polilinea: %lf\n", length(xs, ys, size));
  printf("Numero di punti nel primo quadrante: %i\n", count_in_quadrant(xs, ys, size, 1));
  
  return 0;
  
}

int count_in_quadrant(double xs[], double ys[], int size, int quad){
  int tot=0, i;
  
  if(quad==1)
    for(i=0;i<size;i++)
      if(xs[i]>0&&ys[i]>0)
        tot++;
  
  if(quad==2)
    for(i=0;i<size;i++)
      if(xs[i]<0&&ys[i]>0)
        tot++;
  
  if(quad==3)
    for(i=0;i<size;i++)
      if(xs[i]<0&&ys[i]<0)
        tot++;
  
  if(quad==4)
    for(i=0;i<size;i++)
      if(xs[i]>0&&ys[i]<0)
        tot++;
  
  return tot;
}


double length(double xs[], double ys[], int size){
  int i, j;
  double len=0;
  
  for(i=0, j=1;i<size-1;i++, j++)
    len+= distance(xs, ys, i, j);
    
  return len;
}


double distance(double xs[], double ys[], int i, int j){
  double lun=0, dx, dy;
  
  dx=xs[i]-xs[j];
  dy=ys[i]-ys[j];
  lun=sqrt(dx*dx+dy*dy);
  
  return lun;
}






