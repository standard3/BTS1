#include <stdio.h>

// Déclaration
float sommeCarres(float, float);

// Programme principal
int main() {
    float a, b;

    printf("Saisir a : ");
    scanf("%f", &a);
    
    printf("Saisir b : ");
    scanf("%f", &b);
    
    printf("%5.2f", sommeCarres(a, b));
    
    return 0;
}

// Définition
float sommeCarres(float x, float y) {
    return x * x + y * y;
}
