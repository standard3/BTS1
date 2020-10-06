#include <stdio.h>

int main() {
    int n = 123;
    
    printf("%d\n", n);
    printf("%5d\n", n);
    printf("%06d\n", n);
    printf("%-5dHello !\n", n);

    printf("\navec un seul printf :\n\n");

    printf("%d\n%5d\n%06d\n%-5dHello !\n", n, n, n, n);
    
    return 0;
}