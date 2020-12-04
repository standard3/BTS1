#include <stdio.h>

#define SIZE 10

int main() {
    int values[SIZE], i, max, min;
    
    for (i = 0; i < SIZE; i++) {
        printf("%d : ", i + 1);
        scanf("%d", values + i);
    }
    
    min = max = *(values);
    for (i = 1; i < SIZE; i++) {
        if (*(values + i) < min) {
            min = *(values + i);
        }
        if (*(values + i) > max) {
            max = *(values + i);
        }
    }
    
    for (i = 0; i < SIZE; i++) {
        printf("%d%s", *(values + i), i == SIZE - 1 ? "" : ", ");
    }
    printf("\nmin : %d, max : %d", min, max);

    return 0;
}