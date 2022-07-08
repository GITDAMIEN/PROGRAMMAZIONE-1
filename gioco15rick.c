
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#define N 4


void pulisciSchermo(){
	printf("\033c");
}

int shuffle(int matrice[][N]){

}


void stampaCampo(int matrice[N][N]){
	for(int riga = 0; riga < N; riga++){
		for(int colonna = 0; colonna < N; colonna ++){
			printf("%d\t", matrice[riga][colonna]);
		}
		printf("\n");
	}
}



int getColonnaPedina(int matrice[N][N], int valore){
	for(int riga = 0; riga < N; riga++){
			for(int colonna = 0; colonna < N; colonna++){
				if(matrice[riga][colonna] == valore){
					return colonna;
				}
			}
		}
}

int getRigaPedina(int matrice[N][N], int valore){
	pulisciSchermo();
	for(int a = 0; a < N; a++){
		for(int b = 0; b < N; b++){
			if(matrice[a][b] == valore){
				return a;
			}
		}
	}
}

int valoreAssoluto(int n){
	if(n < 0){
		return n * -1; 
	}
	else{
		return n; 
	}

}


int mossaIsValid(int matrice[N][N], int pedina){
	int colonnaZero, rigaZero, validita, colonnaPedina, rigaPedina;
	colonnaZero = getColonnaPedina(matrice, 0); 
	rigaZero = getRigaPedina(matrice, 0); 
	colonnaPedina = getColonnaPedina(matrice, pedina);
	rigaPedina = getRigaPedina(matrice, pedina);

	printf("\n riga zero: %d, colonna zero: %d", rigaZero, colonnaZero);
	printf("\n riga pedina: %d, colonna pedina: %d \n", rigaPedina, colonnaPedina);
	int a = rigaZero - rigaPedina;
	int b = colonnaZero - colonnaPedina;
	int differenzaRiga = valoreAssoluto((a));
	int differenzaColonna = valoreAssoluto((b));
	if(differenzaColonna == 1 && differenzaRiga == 0 || differenzaColonna == 0 && differenzaRiga == 1){
		return 1; 
	}
	else{
		return 0; 
	}

}

void move(int matrice[][N], int valorePedina){
	int rigaZero, colonnaZero, rigaPedina, colonnaPedina;

	if(mossaIsValid(matrice, valorePedina)){
		rigaZero = getRigaPedina(matrice, 0);
		colonnaZero = getColonnaPedina(matrice, 0);
		rigaPedina = getRigaPedina(matrice, valorePedina);
		colonnaPedina = getColonnaPedina(matrice, valorePedina);

		matrice[rigaZero][colonnaZero] = matrice[rigaPedina][colonnaPedina];
		matrice[rigaPedina][colonnaPedina] = 0; 
	}
	else{
		pulisciSchermo(); 
		printf("\n      ---- MOSSA NON VALIDA ----  \n");
		sleep(1);
		pulisciSchermo();  
	}
}


bool hasWinner(int matrice[N][N]){
	int elementoControllato = 1;
	for(int riga = 0; riga < N; riga ++){
		for(int colonna = 0; colonna < N && (riga*colonna) < 9; colonna ++){
			if(matrice[riga][colonna] != elementoControllato){
				return false; 
			}
			elementoControllato++;
		}
	}
	return true; 
}





int main(){
	int campo[N][N] = {{1,2,3,4}, {5,6,7,8}, {9,10,11,12}, {13,14,15,0}};
	int pedinaDaMuovere; 

	while(1){
		stampaCampo(campo);
		printf("inserisci pedina da muovere: ");
		scanf("%d", &pedinaDaMuovere);
		move(campo, pedinaDaMuovere); 
		printf("Vincitore: %d\n", hasWinner(campo));
	}

}