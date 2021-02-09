#include <stdio.h>
#include "csv2xml.h"

void readLine(char *, char *, char *, char *, char *, char *, char *, char *);
void createXML(char *, char *, char *, char *, char *, char *, char *);

int main()
{
    FILE * fileInput   = fopen("/export_npa/input_npa.csv",    "r"); // fichier de test (mettre chemin absolu)
    FILE * fileContact = fopen("/export_npa/contacts_npa.csv", "a"); // fichier de test
    char   line[150];
    char   id[9];
    char   lastname[30];
    char   firstname[25];
    char   date_of_birth[11];
    char   street[100];
    char   zipcode[6];
    char   city[50];

    if (fileInput != NULL && fileContact != NULL)
    {
        while (fgets(line, 150, fileInput) != NULL)
        {
            readLine(line, id, lastname, firstname, street, zipcode, city);
        }
    }

    // Calculer âge => estMajeur()

    // Générer fichier XML => générerXML()

    // Écrire ligne dans contacts

    fclose(fileInput);
    fclose(fileContact);

    return 0;
}

void readLine(char * line, char * id, char * lastname, char * firstname, char * number, char * street, char * zipcode, char * city)
{
    int countId, countLastname, countFirstname, countNumber, countStreet, countZipcode, countCity;
    int count, countId, countLastname, countFirstname, countNumber, countStreet, countZipcode, countCity = 0;
    char c;
    
    for (int i = 0; i < strlen(line); i++)
    {
        c = line[i];

        if (c == '\t')
            count++;
        else
        {
            // ID
            if (count == 0)
            {
                id[countId++] = c;
            }
            // Prénom Nom
            else if (count == 1)
            {

            }
            // Date de naissance
            else if (count == 2)
            {

            }
            // Numéro de voie
            else if (count == 3)
                number[countNumber++] = c;
            // Voie
            else if (count == 4)
                street[countStreet++] = c;
            // Code postal
            else if (count == 5)
                zipcode[countZipcode++] = c;
            // Ville
            else if (count == 6)
                city[countCity++] = c;
        }
        
    }

}

void createXML(char * id, char * lastname, char * firstname, char * number, char * street, char * zipcode, char * city)
{
    // Créé le fichier courrier_npa avec l'id
    char buf[38];
    snprintf(buf, sizeof(buf), "/export_npa/courrier_npa_%s.xml", id);
    FILE * xml = fopen(buf, "a");

    for (int i = 0; i < 10; i++)
    {
        switch (i)
        {
        case 0:
            fprintf(xml, "a", "<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
            break;
        case 1:
            fprintf(xml, "a", "<CLIENT>");
            break;
        case 2:
            fprintf(xml, "a", "\t<LASTNAME>%s</LASTNAME>", topUpperExtended(lastname));
            break;
        case 3:
            fprintf(xml, "a", "\t<FIRSTNAME>%s</FIRSTNAME>", firstname);
            break;
        case 4:
            fprintf(xml, "a", "\t<ADDRESS>");
            break;
        case 5:
            fprintf(xml, "a", "\t\t<STREET>%s %s</STREET>", number, street);
            break;
        case 6:
            fprintf(xml, "a", "\t\t<ZIPCODE>%s</ZIPCODE>", zipcode);
            break;
        case 7:
            fprintf(xml, "a", "\t\t<CITY>%s</CITY>", city);
            break;
        case 8:
            fprintf(xml, "a", "\t</ADRESS>");
            break;
        case 9:
            fprintf(xml, "a", "</CLIENT>");
            break;
        }
    }
}