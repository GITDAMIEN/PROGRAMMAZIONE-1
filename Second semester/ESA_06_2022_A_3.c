#include <stdio.h>

#define N1 10
#define N2 10

void merge(int [], int, int [], int, int [], int*);
// definire altri prototipi se ritenuto necessario

int main(int argc, char * argv[])
{
	int v1[N1], v2[N2], vris[N1+N2];
	int dim1, dim2, dris;
	int i;
	printf("Dimmi le due dimensioni array: ");
	scanf("%d%d", &dim1, &dim2);
	printf("\n Primo array: ");
	for(i = 0; i < dim1; i++)
		scanf("%d", &v1[i]);
	printf("\n Secondo array: ");
	for(i = 0; i < dim2; i++)
		scanf("%d", &v2[i]);
	
	merge(v1, dim1, v2, dim2, vris, &dris);
	for(i = 0; i < dris; i++)
		printf("%d ", vris[i]);
	printf("\n");
	return 0;
	
}

void merge(int A[], int na, int B[], int nb, int C[], int *val){
	// definire qui la funzione
	
	
}



