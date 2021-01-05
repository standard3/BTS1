#include <stdio.h>
#include <stdlib.h>

void getMin(int *, int, int *, int *);

int main() {
    system("chcp 65001");
    system("cls");

    int tab[10] = {1, 14, 5, 6, 7, 3, 5, 0, 212, 342}, min, i;

    getMin(tab, 10, &min, &i);
    printf("La valeur minimal du tableau est : %d\nElle est stockée à l'index : %d\n", min, i);

    return 0;
}

void getMin(int * array, int length, int * value, int * index) {
    int i = 0;
    *value = array[0];
    *index = 0;
    for (i = 1; i < length; i++) {
        if (array[i] < *value) {
            *value = array[i];
            *index = i;
        }
    }
}