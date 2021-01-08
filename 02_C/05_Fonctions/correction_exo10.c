#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int somme(int, int);
int carre(int);
float racineCarree(int);

int main(int argc, char ** argv) {
    printf("%f", racineCarree(somme(carre(atoi(*(argv + 1))), carre(atoi(*(argv + 2))))));  
    return 0;
}

int somme(int a, int b) {
    return a + b;
}
int carre(int a) {
    return a * a;
}
float racineCarree(int a) {
    return sqrt(a);
}