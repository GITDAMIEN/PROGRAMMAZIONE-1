#include<stdio.h>
#define N 20

int main(){
  //dichiarazioni
  char arr[N], trash;
  char ris[N];
  int i, somma;
  
  //chiedo i valori dell'array
  printf("Inserisci i valori:\n");
  for(i=0;i<N;i++)
    scanf("%c%c", &arr[i], &trash);
  
  //creo valori del secondo array
  for(i=0;i<N;i++)
    if(arr[i]=='A')
      ris[i]='1';
    else  
      if(arr[i]=='E')
        ris[i]='2';
      else  
        if(arr[i]=='I')
          ris[i]='3';
        else  
          if(arr[i]=='O')
            ris[i]='4';
          else
            if(arr[i]=='U')
              ris[i]='5';
            else  
              if(arr[i]=='a')
                ris[i]='6';
              else  
                if(arr[i]=='e')
                  ris[i]='7';
                else  
                  if(arr[i]=='i')
                    ris[i]='8';
                  else
                    if(arr[i]=='o')
                      ris[i]='9';
                    else
                      if(arr[i]=='u')
                        ris[i]='0';
                      else
                        ris[i]=arr[i];
  
  //sommo i valori numerici
  somma=0;
  for(i=0;i<N;i++)
    if(ris[i]>=0||ris[i]<=9)
      somma=somma+ris[i];
  
  //stampo i valori dell'array ottenuto
  printf("Ecco i valori richiesti:");
  for(i=0;i<N;i++)
    printf("%3c", ris[i]);
  printf("\n");
  
  //stampo la somma dei valori numerici
  printf("Somma: %d\n", somma);                 //NON RIESCO A FARMI DARE LA SOMMA DEI VALORI NUMERICI//
  
  return 0;
  
}