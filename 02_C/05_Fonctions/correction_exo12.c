#include <stdio.h>

void count();

int main() {
    long i = 0;
    for (i = 0; i < 100; i++) {
        count();
    }
    return 0;
}

void count() {
    static long calls = 1;
    printf("%d\n", calls++);
}
