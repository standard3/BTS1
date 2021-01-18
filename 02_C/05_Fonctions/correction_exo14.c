#include <stdio.h>

void count(int, int);

int main() {
    count(1, 10);
    return 0;
}

void count(int i, int max) {
    printf("%d\n", i++);
    if (i <= max) {
        count(i, max);
    }
}
