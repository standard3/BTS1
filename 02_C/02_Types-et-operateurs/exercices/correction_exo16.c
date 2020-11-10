#include <stdio.h>

int main() {
    float a, b;

    printf("Veuillez saisir 2 entiers :\n");
    scanf("%f %f", &a, &b);

    printf("%.0f / %.0f = %f\n", a, b, a / b);

    return 0;
}