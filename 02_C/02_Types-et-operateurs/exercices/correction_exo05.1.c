#include <stdio.h>

int main() {
    int a;
    
    do {
        printf("Entrer un nombre entre 1 et 10 : ");
        scanf("%d", &a);
    } while(a < 1 || a > 10);

    return 0;
}