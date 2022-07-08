/*
Si scrivano le versioni ricorsiva ed iterativa (utilizzo di while) di una funzione double f (double a, int n) che calcola il seguente valore: 
sommatoria per i da 1 ad n per (a - i/a)
*/

#include<stdio.h>
double fi(double a, int n);
double fr(double a, int n);

int main(){
    int n;
    double a;

    printf("Inserisci valore n (int): ");
    scanf("%d", &n);
    printf("Inserisci valore a (double): ");
    scanf("%lf", &a);

    printf("Versione iterativa: %.2lf\n)", fi(a,n));
    printf("Versione ricorsvia: %.2lf\n)", fr(a,n));

}

double fi(double a, int n){
    int i;
    double tot=0;

    for(i=1;i<=n;i++)
        tot+=a-(i/a);

    return tot;
}
double fr(double a, int n){
    if(n==1)
        return a-(n/a);
    else 
        return a-(n/a)+fr(a,n-1);
}
