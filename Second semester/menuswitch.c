/*PROGRAMMA CHE PROPONE UN MENU DI SCELTA ED ESEGUE DIVERSE ISTRUZIONI IN BASE ALL'OPZIONE SCELTA*/

#include <stdio.h>
#define N 10

int main(){
	int vet[N];
	int i;
	int multipli=0;
	int num;
	int scelta;
	int ins=0; //flag per avvenuto inserimento;
	
do{
	printf("\n 1 - Inserire array \n");
	printf("2 - Stampare array \n");
	printf("3 - Trovare i multipli di un numero \n");
	printf("4 - Uscire\n");
	
	scanf("%d",&scelta);
	switch(scelta){
		case 1:
			for(i=0;i<N;i++)
				scanf("%d",&vet[i]);
			ins=1;
			break;
		
		case 2:
			if(ins)
				for(i=0;i<N;i++)
					printf("%3d",vet[i]);
	
			break;
			
		case 3:
		if(ins)
		{
			printf("Inserisci un numero \n");
			scanf("%d",&num);
			for(multipli=0,i=0;i<N;i++)
				if(vet[i]%num==0)
					multipli++;
			printf("\n Ci sono %d multipli",multipli);
		}	
		
		case 4: break;	
		
		default: printf("Opzione non valida \n");
		
		
		
	}




}while(scelta!=4);



}
