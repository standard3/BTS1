#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

int main(int argc, char ** argv) {
    int i, nb = 0, i_nom_courant, i_lng_courant, i_lat_courant;
    double longitude, latitude, lat, lng, distance;
    char nom_courant[100], lng_courant[22], lat_courant[22];
    FILE * fichier;
    char ligne[210];

    for (i = 0; i < strlen(argv[1]); i++) {
        if (argv[1][i] == ',') {
            argv[1][i] = '.';
        }
    }
    longitude = atof(argv[1]) * acos(-1) / 180;
    for (i = 0; i < strlen(argv[2]); i++) {
        if (argv[2][i] == ',') {
            argv[2][i] = '.';
        }
    }
    latitude = atof(argv[2]) * acos(-1) / 180;
    //printf("%f, %f\n", longitude, latitude);

    fichier = fopen(argv[3], "r");

    if (fichier != NULL) {

        while(fgets(ligne, 210, fichier) != NULL) {
            nb = 0;
            i_nom_courant = 0;
            i_lng_courant = 0;
            i_lat_courant = 0;
            for (i = 0; i < strlen(ligne); i++) {
                if (ligne[i] == ';') {
                    nb++;
                }
                else if(nb == 1) {
                    nom_courant[i_nom_courant] = ligne[i];
                    i_nom_courant++;
                }
                else if(nb == 4) {
                    if (ligne[i] == ',') {
                        ligne[i] = '.';
                    }
                    lng_courant[i_lng_courant] = ligne[i];
                    i_lng_courant++;
                }
                else if(nb == 5) {
                    if (ligne[i] == ',') {
                        ligne[i] = '.';
                    }
                    lat_courant[i_lat_courant] = ligne[i];
                    i_lat_courant++;
                }
            }
            nom_courant[i_nom_courant] = '\0';
            lng_courant[i_lng_courant] = '\0';
            lat_courant[i_lat_courant] = '\0';
            lng = atof(lng_courant) * acos(-1) / 180;
            lat = atof(lat_courant) * acos(-1) / 180;

            distance = sqrt(pow((lng - longitude) * cos((lat + latitude) / 2), 2) + pow(lat - latitude, 2)) * 6371;
            //printf("%s : %.3f km\n", nom_courant, lat, lng, distance);

            // TO DO : Ne conserver que la plus petite distance et le nom du défibrillateur correspondant

        }

        fclose(fichier);
    }

}