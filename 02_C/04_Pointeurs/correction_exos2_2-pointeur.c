#include <stdio.h>

#define SIZE 10

int main() {
    int values[SIZE], odd[SIZE], nbOdd = 0, even[SIZE], nbEven = 0, i;
    
    for (i = 0; i < SIZE; i++) {
        printf("%d : ", i + 1);
        scanf("%d", values + i);
    }

    for (i = 0; i < SIZE; i++) {
        if (*(values + i) % 2 == 0) {
            *(even + nbEven++) = *(values + i);
        }
        else {
            *(odd + nbOdd++) = *(values + i);
        }
    }

    printf("Pairs : ");
    for (i = 0; i < nbEven; i++) {
        printf("%d%s", *(even + i), i == nbEven - 1 ? "" : ", ");
    }
    printf("\nImpairs : ");
    for (i = 0; i < nbOdd; i++) {
        printf("%d%s", *(odd + i), i == nbOdd - 1 ? "" : ", ");
    }
    
    return 0;
}