/*Scrivere un programma che acquisisce due stringhe s1 ed s2 di al massimo 100 caratteri ciascuna.
Il programma verifica se s2 è presente in s1 e tutte le volte che compare sostituisce il primo carattere di s2
in s1 con il carattere X (è ammesso l’uso solo di strlen).*/


#include<stdio.h>
#include<string.h>
#define N 100

			// PER QUALCHE MOTIVO, PER CERTE LUNGHEZZE NON MI SOSTITUISCE LA PRIMA LETTERA (LUNGHEZZA 4 E 6 PER ESEMPIO)
			
void acquisisci(char [], int);

int main(){
    char s1[N+1], s2[N+1];
    int index, index2, index3, count;

    acquisisci(s1,N);
    acquisisci(s2,N);

    for(index=0;s1[index]!='\0';index++){
        count=0;
        index3=index;
        for(index2=0;s2[index2]!='\0';index2++, index3++)
            if(s2[index2]==s1[index3])
                count++;
    	/*printf("Count: %d\n", count);
    	printf("Strlen %d\n", strlen(s2));
    	printf("index1: %d\n", index);
    	printf("index2: %d\n", index2);
    	printf("index3: %d\n", index3);*/
        if(count==strlen(s2))
			s1[index3-count]='X';
    }

printf("S1 esito: %s", s1);

}



void acquisisci(char a[], int dim){
    int index, flag=1;
    char var;

    printf("Inserisci stringa:");
    for(index=0;index<dim&&flag;index++){
        var=getchar();
        if(var=='\n')
            flag=0;
        else
            a[index]=var;
    }

    a[index]='\0';

}
