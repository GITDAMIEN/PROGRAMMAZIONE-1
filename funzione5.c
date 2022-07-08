#include<stdio.h>
/*Scrivete una funzione avente due parametri interi b ed e che calcoli la potenza b^e.*/

int fun(int b, int e);

int main(){
int base, esponente, ris;

printf("Inserisci il numero:\n");
scanf("%d", &base);
printf("Inserisci la potenza:\n");
scanf("%d", &esponente);

ris=fun(base,esponente);

printf("La potenza di %d alla %d è: %d\n", base, esponente, ris);

return 0;

}
int fun(int b, int e){
int i, tot=1;

for(i=0;i<e;i++){
	tot=tot*b;

}


return tot;
}
