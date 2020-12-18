#include <stdio.h>

void inputInteger(int *, int *);

int main() {
    int input, isGreaterThan100;
    inputInteger(&input, &isGreaterThan100);
    if (isGreaterThan100 == 1) {
        printf("%d > 100", input);
    }
    else {
        printf("%d <= 100", input);
    }
    return 0;
}

/**
 * Permet de saisir un entier et de savoir s'il est plus grand que 100
 * @param input l'entier à saisir (passé par adresse)
 * @param isGreaterThan100 1 si l'entier saisi est plus grand que 100, 0 sinon (passé par adresse)
 * @return void
 * */
void inputInteger(int * input, int * isGreaterThan100) {
    printf("Saisir un entier : ");
    scanf("%d", input);
    *isGreaterThan100 = *input > 100;
}
