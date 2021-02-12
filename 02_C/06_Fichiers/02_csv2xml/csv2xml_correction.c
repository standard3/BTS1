#include <stdio.h>
#include <stdlib.h>
#include "csv2xml.h"

void lireUneLigne(char *, char *, char *, char *, char *, char *, char *, char *);
int estMajeur(int *, char *);

int main() {
    system("chcp 65001");
    FILE * fichierInput, * fichierContacts;
    char ligne[150], id[9], nom[30], prenom[25], dateDeNaissance[11], voie[100], cp[6], ville[50];
    int ajh[3];
    getToday(ajh);

    fichierInput = fopen("C:\\projects\\mathieu\\bts1_20-21\\02_C\\06_Fichiers\\02_csv2xml\\export_npa\\20210202_input_npa.csv", "r");
    fichierContacts = fopen("C:\\projects\\mathieu\\bts1_20-21\\02_C\\06_Fichiers\\02_csv2xml\\export_npa\\20210202_contacts_npa.csv", "w");

    if (fichierInput != NULL && fichierContacts != NULL) {
        while(fgets(ligne, 150, fichierInput) != NULL) {
            lireUneLigne(ligne, id, nom, prenom, dateDeNaissance, voie, cp, ville);
            estMajeur(ajh, dateDeNaissance);
        }
    } 

    fclose(fichierInput);
    fclose(fichierContacts);
    return 0;
}

void lireUneLigne(char * ligne, char * id, char * nom, char * prenom, char * dateDeNaissance, char * voie, char * cp, char *ville) {
    int i, cpt, cpe, tId, tNom, tPrenom, tDateDeNaissance, tNumero, tRue, tCp, tVille;
    cpt = cpe = tId = tNom = tPrenom = tDateDeNaissance = tNumero = tRue = tCp = tVille = 0;
    char c, numero[4], rue[97];

    for (i = 0; ligne[i] != '\0'; i++) {
        c = ligne[i];
        if (c == '\t') {
            cpt++;
        }
        // Id
        else if (cpt == 0) {
            id[tId++] = c;
        }
        // Prénom NOM
        else if (cpt == 1) {
            if (c == ' ') {
                cpe++;
            }
            if (cpe == 0) {
                prenom[tPrenom++] = c;
            }
            else {
                if (!(c == ' ' && cpe == 1)) { 
                    nom[tNom++] = c;
                }
            }
        }
        // Date de naissance
        else if (cpt == 2) {
            dateDeNaissance[tDateDeNaissance++] = c;
        }
        // Numero
        else if (cpt == 3) {
            numero[tNumero++] = c;
        }
        // Voie
        else if (cpt == 4) {
            rue[tRue++] = c;
        }
        // CP
        else if (cpt == 5) {
            cp[tCp++] = c;
        }
        // Ville
        else if (cpt == 6 && c != '\n') {
            ville[tVille++] = c;
        }
    }
    id[tId] = '\0';
    prenom[tPrenom] = '\0';
    nom[tNom] = '\0';
    toUpperExtended(nom); // mise en majuscules
    dateDeNaissance[tDateDeNaissance] = '\0';
    numero[tNumero] = '\0';
    rue[tRue] = '\0';
    sprintf(voie, "%s %s", numero, rue); // concaténation
    cp[tCp] = '\0';
    ville[tVille] = '\0';
    toUpperExtended(ville); // mise en majuscules
    /*
    puts(id);
    puts(prenom);
    puts(nom);
    puts(dateDeNaissance);
    puts(voie);
    puts(cp);
    puts(ville);
    puts("");
    */
}

int estMajeur(int * ajh, char * dateDeNaissance) {
    char sJour[3], sMois[3], sAnnee[5];
    int iJour, iMois, iAnnee, resultat = 0;

    strncpy(sJour, dateDeNaissance, 2);
    iJour = atoi(sJour);

    strncpy(sMois, dateDeNaissance + 3, 2);
    iMois = atoi(sMois);

    strncpy(sAnnee, dateDeNaissance + 6, 4);
    iAnnee = atoi(sAnnee);

    if (ajh[0] - iAnnee > 18) {
        resultat = 1
    }
    else if (ajh[0] - iAnnee == 18) {
        if (iMois < ajh[1]) {
            resultat = 1;
        }
        // TODO - A finir à partir d'ici
    }

    return resultat;
}