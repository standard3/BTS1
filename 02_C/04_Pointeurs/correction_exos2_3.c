#include <stdio.h>
#include <stdlib.h>

int main() {
    char * tab[] = {"AB1C", "D23", "E4F56", "7G", "HI8", "JKL90MN"}, current, numbers[10];
    int integers[5], i, j, k;

    for (i = 0; i < 6; i++) {
        k = 0;
        for (j = 0; *(*(tab + i) + j) != '\0'; j++) {
            current = *(*(tab + i) + j);
            if (current >= '0' && current <= '9') {
                *(numbers + k) = current;
                k++;
            }
        }
        *(numbers + k) = '\0';
        *(integers + i) = atoi(numbers);
    }

    for (i = 0; i < 6; i++) {
        printf("%s%d", i == 0 ? "" : ", ", *(integers + i));
    }

    return 0;
}