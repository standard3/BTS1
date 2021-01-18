#include <stdio.h>
#include <math.h>
#include <limits.h>

void count();

int main() {
    long i = 0;
    for (i = 0; i < LONG_MAX; i++) {
        count();
    }
    return 0;
}

void count() {
    static long calls;
    static int level;
    static long next = 1;
    calls++;
    if (calls == next) {
        printf("*** appel #%ld ***\n", calls);
        level++;
        next = pow(10, level);
    }
}
