//PROGRAMMA CHE STAMPA E DIMOSTRA TUTTE LE FUNZIONI DELLA LIBRERIA CTYPE.H 

#include<stdio.h>
#include<ctype.h>

int main(){
    char arr[]={'a','b','D','d','e','f'};
    char arr2[]={'G','H','I','l','M','N'};
    int c;
    int i;
    
    printf("\nHere are all ctype.h library functions:\n");

    //toupper
    printf("\ntoupper function:\n");
    for(i=0;i<6;i++){
        printf("%c -> %c\n", arr[i], toupper(arr[i]));
    }

    //tolower
    printf("\ntolower function:\n");
    for(i=0;i<6;i++){
        printf("%c -> %c\n", arr2[i], tolower(arr2[i]));
    }

    //isupper
    printf("\nisupper function:\n");
    printf("The upper characters are: \n");
    for(c = 1; c <= 127; ++c)
        if (isupper(c))
            printf("%c ", c);
    printf("\n");

    //islower
    printf("\nislower function:\n");
    printf("The lower characters are: \n");
    for(c = 1; c <= 127; ++c)
        if (islower(c))
            printf("%c ", c);
    printf("\n");

    //isalpha
    printf("\nisalpha function:\n");
    printf("The alpha characters are: \n");
    for(c = 1; c <= 127; ++c)
        if (isalpha(c))
            printf("%c ", c);
    printf("\n");

    //ispunct
    printf("\nispunct function:\n");
    printf("The punctation characters are: \n");
    for(c = 1; c <= 127; ++c)
        if (ispunct(c))
            printf("%c ", c);
    printf("\n");

    //isdigit
    printf("\nisdigit function:\n");
    printf("The digits are: \n");
    for(c = 1; c <= 127; ++c)
        if (isdigit(c))
            printf("%c ", c);
    printf("\n");

    //isxdigit    
    printf("\nisxdigit function:\n");
    printf("The xdigits (hexa) are: \n");
    for(c = 1; c <= 127; ++c)
        if (isxdigit(c))
            printf("%c ", c);
    printf("\n");

    //isalnum
    printf("\nisalnum function:\n");
    printf("The alnum characters are: \n");
    for(c = 1; c <= 127; ++c)
        if (isalnum(c))
            printf("%c ", c);
    printf("\n");

    //isgraph
    printf("\nisgraph function:\n");
    printf("The graph characters are: \n");
    for(c = 1; c <= 127; ++c)
        if (isgraph(c))
            printf("%c ", c);
    printf("\n");

    //isprint
    printf("\nisprint function:\n");
    printf("The printable characters are: \n");
    for(c = 1; c <= 127; ++c)
        if (isprint(c))
            printf("%c ", c);
    printf("\n");

    //isspace
    printf("\nisspace function:\n");
    printf("The space characters are: \n");
    printf("%c(tab)\n", 9);
    printf("%c(new line)\n", 10);
    printf("%c(space)\n", 32);
    printf("\n");

    //iscontrol
    printf("\niscontrol function:\n");
    printf("The control characters are: \n");
    for(c = 1; c <= 127; ++c)
        if (iscntrl(c))
            printf("%c ", c);
    printf("\n");

    return 0;

}