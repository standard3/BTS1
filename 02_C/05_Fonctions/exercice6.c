#include <stdio.h>

float sommeCarre(float, float);

int main()
{
    float a, b;
    
    printf("a = ");
    scanf("%f", &a);

    printf("b = ");
    scanf("%f", &b);

    printf("Somme : %5.2f", sommeCarre(a, b));

    return 0;
}

float sommeCarre(float a, float b)
{
    return a * a + b * b;
}