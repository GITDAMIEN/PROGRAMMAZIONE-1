#include<stdio.h>
#define D 10
int main (){
  //dichiarazioni
  int voti[D];
  int i=0, max, min, somma;
  float media;
  
  //operazioni
  printf("Inserisci voti:\n");
  min=31;
  max=17;
  somma=0;
  for(i=0;i<D;i++){
    do{
      scanf("%d", &voti[i]);   //scanf dei voti
      if(voti[i]<18||voti[i]>30)
        printf("Il voto dev'essere maggiore o uguale a 18 e minore o uguale a 30\n");
      }while(voti[i]<18||voti[i]>30);    //verifica del campo di esistenza
    somma=somma+voti[i];    //ad ogni nuovo numero, lo aggiungo alla somma
    if(voti[i]<min)
      min=voti[i];   //se voti[i] è inferiore a min, aggiorno min con il nuovo min
    else
      if(voti[i]>max)
        max=voti[i];   //se voti[i] è maggiore di max, aggiorno max con il nuovo max
  }

  //stampe
  printf("I voti inseriti sono:");
  for(i=0;i<D;i++)
    printf("%3d", voti[i]);
  printf("\n");
  printf("Il voto massimo inserito è: %d\n", max);
  printf("Il voto minimo inserito è: %d\n", min);
  media=(float)somma/D;
  printf("La media dei voti inseriti è: %.2f\n", media);
  
  return 0;
}