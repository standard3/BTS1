#include <stdio.h>
#include <stdlib.h>

void swap(int *, int *);
void swapMinMax(int *, int);
void displayArray(int *, int);

int main() {
    system("chcp 65001");
    system("cls");

    int tab[10] = {1, 14, 0, 6, 7, 3, 5, 84, 342, 212};

    displayArray(tab, 10);
    swapMinMax(tab, 10);
    displayArray(tab, 10);
    
    return 0;
}

void swap(int * a, int * b) {
    int x = *a;
    *a = *b;
    *b = x;
}

void swapMinMax(int * array, int length) {
    int i = 0, * min, * max; 
    min = max = array;
    for (i = 1; i < length; i++) {
        if (*(array + i) < *min) {
            min = array + i;
        }
        if (*(array + i) > *max) {
            max = array + i;
        }
    }
    swap(min, max);
}

void displayArray(int * array, int length) {
    int i = 0;
    for (i = 0; i < length; i++) {
        printf("%5d ", *(array + i));
    }
    printf("\n");
}