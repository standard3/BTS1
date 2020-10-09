#include <stdio.h>
#include <math.h>
#include <stdlib.h>

#define PI 3.14

int main()
{
    float r = 20, d, p, s;
    
    d = 2 * r; // Diamètre
    p = d * PI; // Périmètre
    s = PI * pow(r, 2); // Surface (aire)

    system("chcp 65001");
    printf("Un cercle de rayon %.0fcm\n", r);
    printf("pour diamètre %.0fcm,\n", d);
    printf("pour circonférence %.2fcm,\n", p);
    printf("pour surface %.2fcm².", s);

    return 0;
}