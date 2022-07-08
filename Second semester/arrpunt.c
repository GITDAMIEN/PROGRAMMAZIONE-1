#include<stdio.h>
#define N 20

void converti (char *);

int main (){
    char s[N+1];
    scanf("%s", s);
    converti(s);
    printf("%s", s);
}

void converti(char *s){
    char *p;
    p=s;

    while(*p!='\0'){
        if(*p>='a'&&*p<='z')
            *p=*p-'a'+'A';
        p++; //qui modifico ciò a cui punta p (non il suo contenuto, ma la direzione della freccia)
    }

}