#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

void lirefichier(char *, char *);
void lirearg(char *);
char *itoa(int, char *, int);

int main(int argc, char **argv)
{
    char word[20];
    lirearg(argv[1]);
    return 0;
}

void lirearg(char *temp)
{
    char valeur[100];
    char numerocle[4] = {"\0"};
    char numerovaleur[10] = {"\0"};
    char copy[50];
    int countLgth;
    countLgth = 0;
    int ComaCount = 0;
    int intCle;
    strcpy(copy, temp);
    for (int i = 0; i < strlen(temp); i++)
    {
        if (temp[i] == ';')
        {
            ComaCount++;
        }
    }
    printf("\"");
    for (int i = 0; i < ComaCount; i++)
    {
        sscanf(copy + countLgth, "%[0-9]:%[0-9];", numerocle, numerovaleur);
        intCle = atoi(numerocle);   
        
        switch (intCle)
        {
        case 1:

            lirefichier(numerocle, valeur);
            valeur[0] = toupper(valeur[0]);

            printf("%s", valeur);
            printf(":");

            printf("%sm2", numerovaleur);
            printf("\\n");

            break;
        case 2:
            lirefichier(numerocle, valeur);
            valeur[0] = toupper(valeur[0]);

            printf("%s", valeur);
            printf(":");

            printf("%s", numerovaleur);
            printf("\\n");

            break;
        case 3:
            lirefichier(numerocle, valeur);
            valeur[0] = toupper(valeur[0]);

            printf("%s", valeur);
            printf(":");

            printf("%s", numerovaleur);
            printf("\\n");

            break;
        case 4:
            lirefichier(numerocle, valeur);
            valeur[0] = toupper(valeur[0]);

            printf("%s", valeur);
            printf(":");

            printf("%s", numerovaleur);
            printf("\\n");

            break;
        case 5:
            lirefichier(numerocle, valeur);
            valeur[0] = toupper(valeur[0]);

            printf("%s", valeur);
            printf(":");

            printf("%s", numerovaleur);
            printf("\\n");

            break;
        case 9:
            lirefichier(numerocle, valeur);
            valeur[0] = toupper(valeur[0]);

            printf("%s", valeur);
            printf(":");

            printf("%sm", numerovaleur);
            printf("\\n");

            break;
        case 10:
            lirefichier(numerocle, valeur);
            valeur[0] = toupper(valeur[0]);

            printf("%s", valeur);
            printf(":");

            printf("%sm", numerovaleur);
            printf("\\n");

            break;
        case 11:
            lirefichier(numerocle, valeur);
            valeur[0] = toupper(valeur[0]);

            printf("%s", valeur);
            printf(":");

            printf("%sm", numerovaleur);
            printf("\\n");

            break;
        case 12:
            lirefichier(numerocle, valeur);
            valeur[0] = toupper(valeur[0]);

            printf("%s", valeur);
            printf(":");

            printf("%sm", numerovaleur);
            printf("\\n");

            break;

        default:
            if (numerocle[0] == 0)
            {

                printf(":");
                sscanf(copy + countLgth, ":%[0-9 -];", numerovaleur);
            }
            else if (numerocle[0] == '0')
            {
                printf("Erreur arguement = 0");
            }
            else
            {
                lirefichier(numerocle, valeur);
                valeur[0] = toupper(valeur[0]);

                printf("%s", valeur);
                printf(":");
            }
            if (numerovaleur[0] == 0)
            {
                printf("\\n");
            }
            else if (numerovaleur[0] == '0')
            {
                printf("Erreur arguement = 0");
            }
            else
            {
                lirefichier(numerovaleur, valeur);
                valeur[0] = toupper(valeur[0]);

                printf("%s", valeur);
                printf("\\n");
            }

            
            break;
        }

        countLgth += strlen(numerocle) + strlen(numerovaleur) + 2;
        numerocle[0] = 0;
        numerovaleur[0] = 0;
    }
    printf("\"");
}

void lirefichier(char *numerocle, char *valeur)
{
    char *clevaleur;
    char *path;
    int count = atoi(numerocle);
    int clenumero = atoi(numerocle);
    path = "C:\\Projects\\BTS1\\BTS1-20-21\\99_Devoirs\\bts1_projet_01\\programme\\gramar.csv";
    FILE *fichier;

    fichier = fopen(path, "r");
    fseek(fichier, 0, SEEK_SET);

    for (int i = 0; i < count; i++) // clenumero inutile en retour car nous cherchons
                                    //la valeur a laquel elle correspond
    {
        fscanf(fichier, "%d:%[a-z -]\n", &clenumero, valeur);
    }
}
/**
 * Replace extended chararacters non replaced by classic toupper()
 * @param destination The string in which the characters must be replaced
 * @return Nothing
 * */ 
void toUpperExtended(char * destination) {
    char extended[] = "áàâäãåæçéèêëíìîïñóòôöõøœúùûü",
         upper[]    = "ÁÀÂÄÃÅÆÇÉÈÊËÍÌÎÏÑÓÒÔÖÕØŒÚÙÛÜ",
         c;
    for (int i = 0; i < strlen(destination); i++) {
        c = toupper(destination[i]);
        if (c == destination[i] && c != '-' && c != '\'') {
            for (int j = 0; j < strlen(extended); j++) {
                if (c == extended[j]) {
                    c = upper[j];
                    break;
                }
            }
        }
        destination[i] = c;
    }
}
char *itoa(int num, char *buffer, int base)
{
    int curr = 0;

    if (num == 0)
    {
        // Base case
        buffer[curr++] = '0';
        buffer[curr] = '\0';
        return buffer;
    }

    int num_digits = 0;

    if (num < 0)
    {
        if (base == 10)
        {
            num_digits++;
            buffer[curr] = '-';
            curr++;
            // Make it positive and finally add the minus sign
            num *= -1;
        }
        else
            // Unsupported base. Return NULL
            return NULL;
    }

    num_digits += (int)floor(log(num) / log(base)) + 1;

    // Go through the digits one by one
    // from left to right
    while (curr < num_digits)
    {
        // Get the base value. For example, 10^2 = 1000, for the third digit
        int base_val = (int)pow(base, num_digits - 1 - curr);

        // Get the numerical value
        int num_val = num / base_val;

        char value = num_val + '0';
        buffer[curr] = value;

        curr++;
        num -= base_val * num_val;
    }
    buffer[curr] = '\0';
    return buffer;
}

// format : "1:20;:2;3:2;:1;"