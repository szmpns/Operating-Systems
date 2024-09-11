#include <stdio.h>
#include <stdlib.h>

void statyczna() {
    double tablica[1000000];
    printf("Tablica statyczna utworzona. Wciśnij Enter, aby kontynuować...");
    getchar();
}

void dynamiczna() {
    double *tablica = (double*)malloc(1000000 * sizeof(double));
    printf("Tablica dynamiczna utworzona. Wcisnij Enter, aby kontynuowc.");
    getchar();
    free(tablica);
}

int main() {
    printf("Wywolaanie funkcji statyczna()\n");
    statyczna();

    printf("Wywolanie funkcji dynamiczna()\n");
    dynamiczna();

    return 0;
}