#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define SIZE 25

int main()
{
    char * string = "super!";
    char * stringg;

    /*
    stringg = (char*) malloc((strlen(string) + 1) * sizeof(char));
    if (stringg != NULL)
        strcpy(stringg, string);

    printf("%s", stringg);
    free(stringg);
    */

    //string = (char*) calloc(SIZE + 1, sizeof(char));

    //string = (char*) realloc(string, SIZE * sizeof(char));
    //free(string);

    return 0;
}