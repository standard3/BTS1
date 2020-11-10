#include <stdio.h>

int main() {
    int a = 0;

    while(a < 1 || a > 10) {
        printf("Entrer un nombre entre 1 et 10 : ");
        scanf("%d", &a);
    } 

    return 0;
}