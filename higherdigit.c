/*scrivere il sottoprogramma int higherdigit che ricevuti 2 interi n e m non negativi restituisce la cifra più alta tra quelle presenti nei due numeri
se i 2 numeri hanno lo stesso numero di cifre, altrimenti restituisce 0

es: 31 e 421 = -1
es: 31 e 42 = 4
*/


#include<stdio.h>

int higherdigit (int, int);

int main (){
	int a, b, r;
	
	printf("Dammi due numeri: ");
	do{
		scanf("%d", &a);
		if(a<0)
			printf("Il numero deve essere positivo: ");
	}while(a<0);
	
	do{
		scanf("%d", &b);
		if(b<0)
			printf("Il numero deve essere positivo: ");
	}while(b<0);
	
	r=higherdigit(a, b);
	
	printf("Esito: %d", r);
	return 0;
}

int higherdigit (int n, int m){
	int contn=0, contm=0, resto, max=-1;
	
	if(n==0){
		contn++;
		max=n;
	}
	
	while(n>0){
		resto=n%10;
		if(resto>max)
			max=resto;
		n/=10;
		contn++;
	}
	
	if(m==0)
		contm++;
		
	while(m>0){
		resto=m%10;
		if(resto>max)
			max=resto;
		m/=10;
		contm++;
	}
	
	if(contn==contm)
		return max;
	else
		return -1;
	
}




