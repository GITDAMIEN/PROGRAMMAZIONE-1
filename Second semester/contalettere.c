/*Scrivere un programma in linguaggio C che legga una frase introdotta da tastiera. La frase è terminata dall’introduzione del carattere di invio.
La frase contiene sia caratteri maiuscoli che caratteri minuscoli, e complessivamente al più 100 caratteri.
Il programma dovrà stampare su schermo le seguenti informazioni:
● per ognuna delle lettere dell’alfabeto (considerare 26 lettere), il numero di volte che la lettera compare nella stringa
● il numero di consonanti presenti nella stringa
● il numero di vocali presenti nella stringa.*/

#include<stdio.h>
#include<ctype.h>
#define N 100

int conta(char [], char [], int [], char [], int [], int*);
void stampa(char [], int [], char [], int [], int, int);

int main(){
    char arr[N+1];
    char lettere[26];
    int quante[26]={0};
    char LETTERE[26];
    int QUANTE[26]={0};
    int i, consonanti=0, vocali=0;

    printf("Inserisci stringa: ");
    fgets(arr, N,stdin);

    for(i=0;i<26;i++)
        lettere[i]=97+i;
    for(i=0;i<26;i++)
        LETTERE[i]=65+i;
    
    consonanti=conta(arr,lettere,quante,LETTERE, QUANTE, &vocali);
    
    stampa(lettere,quante,LETTERE, QUANTE, consonanti,vocali);
}

int conta(char arr[N+1], char lettere[26], int quante[26], char LETTERE[26], int QUANTE[26], int *vocali){
    int index, ind, consonanti=0;

    for(index=0;arr[index]!='\0';index++){
        for(ind=0;ind<26;ind++){
            if(arr[index]==lettere[ind])
                quante[ind]++;              //incrementa contatore relativo alla lettera trovata
            if(arr[index]==LETTERE[ind])
                QUANTE[ind]++;              //incrementa contatore relativo alla lettera trovata
        }
        if(arr[index]=='a'||arr[index]=='e'||arr[index]=='i'||arr[index]=='o'||arr[index]=='u'||arr[index]=='A'||arr[index]=='E'||arr[index]=='I'||arr[index]=='O'||arr[index]=='U')
            (*vocali)++;   //se vocale incrementa contatore vocali
        else if(isalpha(arr[index]))
            consonanti++;  //altrimenti consonanti
    }

    return consonanti;
}

void stampa(char lettere[26], int quante[26], char LETTERE[26], int QUANTE[26], int consonanti, int vocali){
    int ind;

    printf("Nella stringa inserita ci sono %d consonanti e %d vocali.\nNello specifico:\n\n", consonanti, vocali);
    for(ind=0;ind<26;ind++)
        printf("%c -> %d volte.\n", lettere[ind], quante[ind]);    
    for(ind=0;ind<26;ind++)
        printf("%c -> %d volte.\n", LETTERE[ind], QUANTE[ind]);
    printf("\n");

}
