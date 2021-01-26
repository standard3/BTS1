#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>

char* replace_char(char*, char, char);

/* TODO
* Sécuriser argc/argv: si pas bons arguments...
* Améliorer lisibilité, tout commenter
*/

int main(int argc, char ** argv)
{   
    // Extrait de la longitude, latitude et de fichier source
    float userLongitude = atof(replace_char(*(argv + 1), ',', '.'));
    float userLatitude = atof(replace_char(*(argv + 2), ',', '.'));
    FILE * file = fopen(*(argv + 3), "r");

    char defibrillateur[60] = {0};
    char nearestDefibrillateur[60] = {0};
    char fileLongitude[30] = {0};
    char fileLatitude[30] = {0};

    int  nb = 0;
    char c;
    char line[210] = {0};

    float x;
    float y;
    float distance; 
    float nearestDistance = FLT_MAX;

    // Si pas d'erreur d'ouverture de fichier
    if (file != NULL)
    {
        // Tant que toutes les lignes n'ont pas été lues
        while (fgets(line, 210, file) != NULL)
        {
            int j = 0;
            int a = 0;
            int b = 0;

            for (int i = 0; i <= strlen(line); i++)
            {
                c = line[i]; // Régler ça

                if (c == ';')
                    nb++;
                else if (nb == 1)
                {
                    defibrillateur[j] = c;
                    j++;
                }
                else if (nb == 4)
                {
                    if (c == ',')
                        c = '.';

                    if (a == 0)
                        j = 0; a++;

                    fileLongitude[j] = c;
                    fileLongitude[17] = '\0';
                    j++;
                }
                else if (nb == 5)
                {
                    if (c == ',')
                        c = '.';

                    if (b == 0)
                        j = 0; b++;
                    
                    fileLatitude[j] = c;
                    fileLatitude[17] = '\0';
                    j++;
                }
                else if (c == '\0')
                {
                    x = (atof(fileLongitude) - userLongitude) * cos((userLatitude + atof(fileLatitude)) / 2);
                    y = (atof(fileLatitude) - userLatitude);
                    distance = sqrt(pow(x, 2) + pow(y, 2)) * 6371;

                    // Sauvegarde la distance et le nom du défibrillateur
                    if (distance < nearestDistance)
                    {
                        nearestDistance = distance;
                        for (int i = 0; i < 60; i++)
                            nearestDefibrillateur[i] = defibrillateur[i];
                    }
                }
            }
        }      
    }

    printf("%s\n", nearestDefibrillateur);

    fclose(file);

    return 0;
}

/**
 * Remplace un caractère par un autre dans la chaine de 
 * caractères fournie
 * @param str un tableau de caractères
 * @param find caractère à trouver
 * @param replace caractère à remplacer
 * */
char* replace_char(char* str, char find, char replace)
{
    char *current_pos = strchr(str, find);
    while (current_pos) 
    {
        *current_pos = replace;
        current_pos = strchr(current_pos, find);
    }
    return str;
}