/*Programma che concatena 2 stringhe ma in ordine albabetico*/

#include <stdio.h>
#define N 30

int main(){
	char s1[N+1];
	char s2[N+1];
	char s3[2*N+1];
	int i,j;
	
	scanf("%s",s1);
	scanf("%s",s2);
	
	i=0;
	while(s1[i]==s2[i] && s1[i]!='\0'&& s2[i]!='\0') //trovare la prima non corrispondenza
		i++;										 // oppure le stringhe sono una prefisso dell'altra
	printf("\n Esco posizione %d",i);
		if(s1[i]<s2[i] || s1[i]=='\0'){				// nella prima non corrispondenza è inferiore s1
			//oppure la prima e' prefisso di s2
			for(j=0,i=0;s1[i]!='\0';i++){
				s3[j]=s1[i];				// inizio a copiare in s3 s1
				j++;
			}
			for(i=0;s2[i]!='\0';i++){
				s3[j]=s2[i];				// copio in s3 s2
				j++;
			}
		}
		else {									// caso in cui s2 è minore o prefisso di s1
			for(j=0,i=0;s2[i]!='\0';i++){
				s3[j]=s2[i];					//copio prima s2
				j++;
			}
			for(i=0;s1[i]!='\0';i++){
				s3[j]=s1[i];					//copio s1
				j++;
			}
		}
		
		s3[j]='\0';								//s3 deve essere stringa!
		printf("\n La stringa e' %s",s3);




}