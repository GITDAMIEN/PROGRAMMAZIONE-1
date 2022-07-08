#include<stdio.h>

int main(){
  int a,b,mcd,mcm;

  printf("Inserisci due numeri positivi:\n");
  do{
    scanf("%d",&a);
  }while(a<=0);

  do{
    scanf("%d",&b);
  }while(b<=0);

  // divisore comune, parto dal più piccolo dei due
  // multiplo dal più grande

  if(a<b){
    mcd=a;
    mcm=b;
  }
  else{
    mcd=b;
    mcm=a;
  }

  //finche' il divisore non divide entrambi lo diminuisco
  while(a%mcd!=0 || b%mcd!=0)
    mcd--;

  //finche' il multiplo non Ã¨ diviso da entrambi lo aumento
  while(mcm%a!=0 || mcm%b!=0)
    mcm++;

  printf("\nMcd tra %d e %d e' %d",a,b,mcd);
  printf("\nMcm tra %d e %d e' %d\n",a,b,mcm);
  
  return 0;

}