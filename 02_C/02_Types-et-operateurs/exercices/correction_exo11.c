#include <stdio.h>

int main() {
    float n = 31.41592;
    printf("%f\n", n);
    printf("%.3f\n", n);
    printf("%10.4f\n", n);
    printf("%.8f\n", n);
    printf("%12.6f\n", n);
    printf("%-12.6f\n", n);
    return 0;
}