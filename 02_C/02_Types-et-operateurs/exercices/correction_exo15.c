#include <stdio.h>
#include <stdlib.h>

int main() {
    const float PI = 3.14;
    const int r = 20;
    int d = 2 * r;
    float p = PI * d, s = PI * r * r;

    system("chcp 65001"); // Passe l'encodage de la console en UTF8

    printf("Un cercle de rayon %dcm\npour diamètre %dcm,\npour circonférence %.2fcm,\npour surface %.2f cm².",  r, d, p, s);

    return 0;
}