#include <stdio.h>
#include <math.h>
#include <stdlib.h>

float somme(int a, int b) { return a + b; }
float carre(int a) { return pow(a, 2); }
float racineCarree(int a) { return sqrt(a); }

int main(int argc, char ** argv)
{
    double a = atoi(*(argv + 1));
    double b = atoi(*(argv + 2));
    double hypotenuse = racineCarree(somme(carre(a), carre(b)));

    printf("Hypotenuse = %f\n", hypotenuse);

    return 0;
}

