#include <stdio.h>

int main()
{
    double n = 31.41592;

    printf("%f     \n", n);
    printf("%2.3f  \n", n);
    printf("%10.4f \n", n);
    printf("%f85   \n", n);
    printf("%12.6f \n", n);
    printf("%-12.6f\n", n);

    return 0;
}