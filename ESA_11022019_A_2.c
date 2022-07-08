#include <stdio.h>

int prime(int n){
	int i;
	// dato n >=0 restituisce 1 se e' primo, 0 altrimenti
	if(n==0 || n==1)
		return 0;
	
	for(i=2; i<n; i++)
		if(!(n%i))
			return 0;
	
	return 1;
	
}

int rightprime(int val){

// valuto il numero e procedo per divisioni successive per 10, appena trovo un numero non primo restituisco 0 (falso)	
	while(val>0){
		if (prime(val))
				val=val/10;
		
		else return(0);
	}

	// all'uscita del ciclo while il numero soddisfa la proprieta' 
	return(1);

}


int main(){
	int n, r;
	
	printf("\n Inserisci un intero positivo\n");
	do{
		scanf("%d",&n);
	}while(n<=0);
	r=rightprime(n);
	
	printf("\n Esito su %d: %d",n,r);
	
	return 0;
}
