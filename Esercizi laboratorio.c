#include <stdio.h>
#define pi 3.14

int main (){
	//dichiarazioni
	int gradi;
	float radianti = 0;

	//input
	printf ("inserire angolo: ");
	scanf ("%d", &gradi);

	/*
	calcoli
	*/
	radianti = (gradi * pi) / 180;

	//output
	printf("\n");
	printf("valore in radianti: %f", radianti);
	printf("\n");
	
	return 0;


}
