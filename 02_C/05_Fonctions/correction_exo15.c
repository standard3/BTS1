#include <stdio.h>

int count(int, int);

int main() {
    count(0, 10);
    return 0;
}

int count(int i, int max) {
    if (i != max) {
        printf("%d\n", count(i + 1, max));
    }
    return i;
}
