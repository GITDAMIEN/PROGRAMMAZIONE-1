//scrivi funzione ricorsiva che dice se un carattere c è nella stringa

#include<stdio.h>
#include<string.h>
#define MAX 10

int funz(char[], char);

int main(){
    char str[MAX+1];
    int index, slength;
    char c, bin;


    printf("Inserisci stringa: ");
    fgets(str,MAX+1,stdin);
    slength=strlen(str)-1;
    if(str[slength]=='\n')
        str[slength]='\0';

    printf("Inserisci carattere da cercare: ");
    scanf("%c%c", &c, &bin);

    if(funz(str,c))
        printf("%c e' presente in %s.\n", c, str);
    else
        printf("%c NON e' presente in %s.\n", c, str);

}

int funz(char str[MAX+1], char c){
    if(*str=='\0')
        return 0;
    else if(*str==c)
        return 1+funz(str+1, c);
    else
        return funz(str+1,c);
}
