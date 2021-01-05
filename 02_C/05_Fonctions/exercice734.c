#include "stdio.h"

void fonction1(int *);
void fonction2(int *);
void fonction3(int *);
void fonction4(int *);
void fonction5(int *);

// * & ( )

int main() {
    int a = 4;
    fonction1(&a);
    printf("%d", a);
}

void fonction1(int *a) {
    (*a)++;
    fonction3(a);
}
void fonction2(int *a) {
    (*a) += 44;
    fonction5(a);
}
void fonction3(int *a) {
    (*a) = (*a) * 2;
    fonction4(a);
}
void fonction4(int *a) {
    (*a) = (*a) * 10;
    fonction2(a);
}
void fonction5(int *a) {
    (*a) = (*a) / 12;
}