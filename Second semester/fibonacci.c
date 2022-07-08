//VERSIONE RICORSIVA DI FIBONACCI
#include <stdio.h>

int F(int n){
	else if(n == 0 || n == 1){
		return 1;
	}
	else{
		return F(n - 1) + F(n - 2);
	}
}

int main(){
	int a = 3;
	int risultato = F(a);
	printf("F(%d) = %d\n", a, risultato);
	return 0;
}