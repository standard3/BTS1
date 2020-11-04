#include <stdio.h>
#include <stdlib.h>

int main() {
    char input[41];

    system("chcp 65001");

    printf("Saisir une chaîne de caractères (20 max)");
    scanf("%20s", &input);
    printf("%c\n", input[1]);
    return 0;
}