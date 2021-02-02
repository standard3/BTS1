#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <float.h>

#define SIZE_1 100

char* replace_char(char*, char, char);

/* TODO
* Sécuriser argc/argv: si pas bons arguments...
* Améliorer lisibilité, tout commenter
* Voir pourquoi appel programme position exacte ne marche pas
*/

int main(int argc, char ** argv)
{   
    // Extrait de la longitude, latitude et de fichier source
    double userLongitude = atof(replace_char(*(argv + 1), ',', '.'));
    double userLatitude = atof(replace_char(*(argv + 2), ',', '.'));
    FILE * file = fopen(*(argv + 3), "r");

    char defibrillateur[SIZE_1] = {0};
    char nearestDefibrillateur[SIZE_1] = {0};
    char fileLongitude[30] = {0};
    char fileLatitude[30] = {0};

    int  nb = 0;
    char c;
    char line[210] = {0};

    double x;
    double y;
    double distance; 
    double nearestDistance = FLT_MAX;

    int j, k, l;

    // Si pas d'erreur d'ouverture de fichier
    if (file != NULL)
    {
        // Tant que toutes les lignes n'ont pas été lues
        while (fgets(line, 210, file) != NULL)
        {
            j = k = l = 0;
            nb = 0;

            // Reset du contenu de defibrillateur
            for (int i = 0; i < SIZE_1; i++)
                defibrillateur[i] = '\0';

            for (int i = 0; i < strlen(line); i++)
            {
                c = line[i];

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

                    fileLongitude[17] = '\0'; // FIX
                    fileLongitude[k] = c;
                    k++;
                }
                else if (nb == 5)
                {
                    if (c == ',')
                        c = '.';

                    fileLatitude[17] = '\0';
                    fileLatitude[l] = c;
                    l++;
                }
            }

            x = (atof(fileLongitude) - userLongitude) * cos((userLatitude + atof(fileLatitude)) / 2);
            y = (atof(fileLatitude) - userLatitude);
            distance = sqrt(pow(x, 2) + pow(y, 2)) * 6371;

            // Sauvegarde la distance et le nom du défibrillateur
            if (distance < nearestDistance)
            {
                nearestDistance = distance;
                // Reset du contenu de nearestDefibrillateur
                for (int i = 0; i < SIZE_1; i++)
                    nearestDefibrillateur[i] = '\0';

                for (int i = 0; i < SIZE_1; i++)
                    nearestDefibrillateur[i] = defibrillateur[i];                    
            }
        }      
    }
    
    /*
    printf("userLongitude: %.14f\n", userLongitude);
    printf("userLatitude : %.14f\n\n", userLatitude);
    printf("fileLongitude: %.14f\n", atof(fileLongitude));
    printf("fileLatitude : %.14f\n\n", atof(fileLatitude));
    printf("distance     : %.14f\n", distance);
    printf("defibrillateur : %s\n", defibrillateur);
    printf("nearestDefibrillateur : %s\n", nearestDefibrillateur);
    */
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