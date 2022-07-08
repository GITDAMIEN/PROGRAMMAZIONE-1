//si suppone che n e m siano diversi da 1
//nel caso che n=1 e m=1 non ci sono minimi direzionali
//nei due casi n=1 o m =1 si procede come per un array
//questi due casi sono lasciati ad una soluzione più generale, quando
//vedremo gli array a dimensione dinamica
#include <stdio.h>

int main( void ){
    int M[4][5]={
        {1,4,5,4,3},
        {2,2,4,2,2},
        {6,4,2,3,1},
        {1,5,1,2,8}
    };
    int count=0;
    for(int j=1;j<4;j++){
        if(M[0][j-1]<M[0][j]&&M[0][j]> M[0][j+1]){
            count++;
            printf("M[%d][%d] e\' massimo direzionale orizzontale up\n", 0,j);
        }
    }
    for(int j=1;j<4;j++){
        if(M[3][j-1]<M[3][j]&& M[3][j]>M[3][j+1]){
            count++;
            printf("M[%d][%d] e\' massimo direzionale orizzontale down\n", 3,j);
        }
    }
    for(int i=1;i<3;i++){
        if(M[i-1][0]<M[i][0]&&M[i][0]> M[i+1][0]){
            count++;
            printf("M[%d][%d] e\' massimo direzionale verticale left\n", i,0);
        }
    }
    for(int i=1;i<3;i++){
        if(M[i-1][4]<M[i][4]&& M[i][4]>M[i+1][4]){
            count++;
            printf("M[%d][%d] e\' massimo direzionale verticale right\n", i,4);
        }
    }
    for(int i=1;i<3;i++)
        for(int j=1;j<4;j++){
            if(M[i][j-1]<M[i][j]&& M[i][j]>M[i][j+1]){
                count++;
                printf("M[%d][%d] e\' massimo direzionale orizzontale\n", i,j);
            }
            if(M[i-1][j]<M[i][j]&&M[i][j]> M[i+1][j]){
                count++;
                printf("M[%d][%d] e\' massimo direzionale verticale\n", i,j);
            }
        }
    printf("\nNella matrice ci sono %d massimi direzionali \n",count);
}
 