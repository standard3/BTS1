#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *asciiTobinary(char *, char *);
char* compress(char*);

int main(int argc, char ** argv)
{
    /* processData.exe "clé1" "valeur1[,valeur1.2] "clé2" "valeur2" */
    
    /* TODO:
    OK * Traiter les arguments d'entrée et les ajouter à une chaine arguments[]
    OK * Traduire arguments[] en binaire
    OK * Convertir arguments[] en RLE
    * Créer QR code avec arguments[]
    * => voir https://github.com/fukuchi/libqrencode
    */

    char *arguments = (char*) malloc(argc * sizeof(char*)); // pas -1 car \0
    char *buffer    = (char*) malloc(argc * sizeof(char*) * 8);

    for (int i = 1; i < argc; i++)
    {
        if (i % 2 != 0) // key
        {
            strcat(arguments, *(argv + i));
            strcat(arguments, ":");
        }
        else // value
        {
            strcat(arguments, *(argv + i));
            if (i < argc - 1) // tant que ce n'est pas le dernier élément
                strcat(arguments, ";");
        }
    }
    printf("Arguments : \"%s\"\nTaille    : %lu\n", arguments, sizeof(arguments));

    asciiTobinary(arguments, buffer);
    printf("Binaire   : \"%s\"\nTaille    : %lu\n", buffer, sizeof(buffer));

    buffer = (compress(buffer));
    printf("RLE       : \"%s\"\nTaille    : %lu\n", buffer, sizeof(buffer));


    free(arguments);
    return 0;
}

char *asciiTobinary(char *input, char *destination)
{       
    unsigned char bit;
    char *start = destination;

    for (int i = 0; i < strlen(input); i++) 
    {
        for (bit = 1 << (8 - 1); bit; bit >>= 1)
        {    
            *destination++ = input[i] & bit ? '1' : '0';
        }    
    }
    *destination = '\0';

    return start;
}

char* compress(char *str) 
{
    char *start = str;
    char *c_first = str;
    char *c_last = str;
    char *c_write = str;
    int run_len = 0;

    while (*str) {
        ++c_last;
        ++run_len;

        if (!(*c_last) || *c_last != *c_first || run_len == 9) 
        { 
            // end of run
            *(c_write++) = *c_first;
            if (run_len > 1)
                *(c_write++) = '0' + run_len;
            // start next run
            run_len = 0; 
            c_first = c_last;
        }
        ++str;
    }

    *c_write = 0;

    return start;
}