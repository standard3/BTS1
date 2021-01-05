#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main(int argc, char ** argv)
{
    return printf("Hypotenuse = %f\n", hypot(atoi(*(argv + 1)), atoi(*(argv + 2)))) == EOF;
}
