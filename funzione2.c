#include<stdio.h>
/*Si realizzi un programma nel linguaggio C che, dati due interi n e m da standard input, facendo uso di una funzione di nome multipli, calcoli il numero degli interi appartenenti all’intervallo [1, n] che sono multipli di m. Il programma 
principale, al termine della chiamata alla funzione multipli, dovrà stampare il numero degli elementi appartenenti all’insieme e poi terminare.*/

int multipli();

int main (){
int n, m, tot;

//chiedo i numeri
printf("Dammi 2 numeri interi:\n");
scanf("%d%d", &n, &m);

tot=multipli(n,m);

//stampo il risultato richiesto
printf("I multipli di %d appartenenti all'intervallo [1,%d] sono: %d\n", m, n, tot);

return 0;
}
int multipli(int n, int m){
int i, cont=0;

for(i=1;i<=n;i++)
if(i%m==0)
cont++;

return cont;

}
