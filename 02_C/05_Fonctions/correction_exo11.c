#include "stdio.h"
#include "stdlib.h"
#include "math.h"

int main(int argc, char ** argv) {
    return printf("%f", sqrt(pow(atoi(*(argv + 1)), 2) + pow(atoi(*(argv + 2)), 2))) != EOF;
}