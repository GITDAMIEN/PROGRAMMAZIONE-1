//Programma che concatena 2 stringhe ma in ordine albabetico

#include<stdio.h>
#define M 20

int main(){
    char s1[M+1], s2[M+1], s3[2*M+1];
    int index, index2, quale=1;

    printf("Inserisci stringa 1: ");
    scanf("%s", s1);
    printf("Inserisci stringa 2: ");
    scanf("%s", s2); 

    for(index=0;s1[index]!='\0';index++) // questa parte forse non è corretta
        if(s2[index]>s1[index])
            quale=2;
    
    if(quale==2){
        for(index=0;s1[index]!='\0';index++)
            s3[index]=s1[index];
        for(index2=0;s2[index2]!='\0';index2++,index++)
            s3[index]=s2[index2];
    }

    if(quale==1){
        for(index=0;s2[index]!='\0';index++)
            s3[index]=s2[index];
        for(index2=0;s1[index2]!='\0';index2++,index++)
            s3[index]=s1[index2];
    }

    s3[index]='\0';


    printf("Stringa 1: %s\n", s1);
    printf("Stringa 2: %s\n", s2);
    printf("Stringa 3: %s\n", s3);

}
