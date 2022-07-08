#include<stdio.h>
//tuttevoc-punt//
//data una stringa,sostituire tutte le vocali della stringa con tutte le 5 vocali,una alla volta,stampare ad ogni sostituzione la stringa ottenuta// 

int main()
{ char frase[]="questa frase diventa buffa";
  char vocali[]="aeiou";
  char *p;
  char *q;
  p=frase;
 
  for(q=vocali;*q!='\0';q++)
     {
       for(p=frase;*p!='\0';p++)
          if((*p=='a')||(*p=='e')||(*p=='i')||(*p=='o')||(*p=='u'))
             *p=*q;
      printf("%s\n",frase);
     }

}
