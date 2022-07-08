#include <stdio.h>

int main( void ){
    int M[6][6]={
        {1,2,3,4,4,5},
        {5,5,6,8,5,1},
        {1,2,3,5,4,4},
        {1,2,5,4,4,4},
        {1,5,3,4,7,4},
        {5,2,3,4,4,2}
    };
    int V[36];
    int i = 1;
    int j = 1;
    printf("sequenza degli indici matrice");
    for (int k = 0; k < 36; k++)
    {
        printf("[%d][%d]--",i-1,j-1);
        V[k]=M[i-1][j-1];
        if ((i + j) % 2 == 0)
        {
            // pari
            if (j < 6)
                j++;
            else
                i+= 2;
            if (i > 1)
                i--;
        }
        else
        {
            // dispari
            if (i < 6)
                i++;
            else
                j+= 2;
            if (j > 1)
                j--;
        }
    }
    
    printf("\nstampa di V\n");
    
    for(int k=0;k<36;k++){
        printf("%3d",V[k]);
    }
    printf("");
}
