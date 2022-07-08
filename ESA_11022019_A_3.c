/**
 * Compilare il programma con gcc aggiungendo alla fine -lm
 */
#include <stdio.h>
#include <math.h>

/*
 * Ritorna la distanza tra due punti
 */
double distance(double xs[], double ys[], int i, int j) {
    double dx = xs[i] - xs[j];
    double dy = ys[i] - ys[j];
    return sqrt(dx*dx + dy*dy);
}

/**
 * Restituisce il numero dei punti la cui distanza dall'origine
 * degli assi è minore o uguale al valore indicato,
 * utilizzando la funzione distance().
 */
int count_in(double xs[], double ys[], int size, double radius) {
    int count = 0;
    double _xs[2];
    double _ys[2];

    _xs[0] = 0;
    _ys[0] = 0;

    for(int i = 0; i < size; i++) {
        _xs[1] = xs[i];
        _ys[1] = ys[i];

        if(distance(_xs, _ys, 0, 1) <= radius) {
            count++;
        }
    }

    return count;
}

/**
 * Stampa la sequenza dei punti 
 */
void print(double xs[], double ys[], int size) {
    for(int i = 0; i < size; i++) {
        printf("(%.2lf, %.2lf)\n", xs[i], ys[i]);
    }
}

/*
 * Program entry point
 */
int main(){
	double xs[] = {0, -1.1, 2, 0.9};  // Ascisse
	double ys[] = {0.5, 0, 1, 0};  // Ordinate
    int size = 4;
    double radius = 1;

    print(xs, ys, size);
    printf("Numero di punti dentro il cerchio di raggio %.2lf centrato nell'origine: %i\n", radius, count_in(xs, ys, size, radius));
	return 0;
}
