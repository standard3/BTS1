#include <stdio.h>

int main() {
    int choice, a, b;
    do {
        printf("Choisir une opération :\n1) Addition\n2) Multiplication\n> ");
        scanf("%d", &choice);
    }
    while (choice != 1 && choice != 2);
    printf("Saisir 2 nombres séparés par un espace :\n> ");
    scanf("%d %d", &a, &b);
    switch (choice) {
        case 1:
            printf("%d + %d = %d", a, b, a + b);
            break;
        case 2:
            printf("%d x %d = %d", a, b, a * b);
            break;
    }
    return 0;
}