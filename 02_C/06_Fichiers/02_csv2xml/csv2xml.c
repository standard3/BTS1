#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "csv2xml.h"

#define TRUE 1
#define FALSE 0
#define LINE_SIZE 150

int  hasLegalAge(char *);
void readLine(char *, char *, char *, char *, char *, char *, char *, char *, char *);
void createXML(char *, char *, char *, char *, char *, char *, char *);

int main()
{
    FILE * fileInput   = fopen("E:\\Projects\\bts1\\BTS1\\02_C\\06_Fichiers\\02_csv2xml\\export_npa\\input_npa.csv",    "r"); // fichier de test
    FILE * fileContact = fopen("E:\\Projects\\bts1\\BTS1\\02_C\\06_Fichiers\\02_csv2xml\\export_npa\\contacts_npa.csv", "a"); // fichier de test
    char   line[LINE_SIZE];
    char   id[9];
    char   lastname[30];
    char   firstname[25];
    char   date_of_birth[11];
    char   number[4];
    char   street[100];
    char   zipcode[6];
    char   city[50];

    system("chcp 65001");

    if (fileInput != NULL && fileContact != NULL)
        while (fgets(line, LINE_SIZE, fileInput) != NULL)
        {
            readLine(line, id, lastname, firstname, date_of_birth, number, street, zipcode, city);
            if (hasLegalAge(date_of_birth))
            {
                createXML(id, lastname, firstname, number, street, zipcode, city);
            }
                
        }
            
    // Calculer âge => hasLegalAge()

    // Générer fichier XML => générerXML()

    // Écrire ligne dans contacts

    fclose(fileInput);
    fclose(fileContact);
    
    return 0;
}


int hasLegalAge(char * dob)
{
    const int daysInMonths[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    int today[3];
    getToday(today);

    int current_year = today[0], 
        current_month = today[1], 
        current_day = today[0];

    int birth_year, 
        birth_month, 
        birth_day;

    memcpy(&birth_year, &dob[0], 2);
    memcpy(&birth_month, &dob[3], 2);
    memcpy(&birth_day, &dob[6], 2);
    
    if (birth_day > current_day)
    {
        current_day += daysInMonths[birth_month - 1];
        current_month--;
    }
    
    if (birth_month > current_month)
    {
        current_month += 12;
        current_year--;
    }

    // Voir si ça marche vraiment...
    if ((current_year - birth_year) < 18)
        return FALSE;
    else
        return TRUE;
}

void readLine(char * line, char * id, char * lastname, char * firstname, char * dob, char * number, char * street, char * zipcode, char * city)
{
    int count, countSpaces, countId, countLastname, countFirstname, countDob, countNumber, countStreet, countZipcode, countCity;
    count = countSpaces = countId = countLastname = countFirstname = countDob = countNumber = countStreet = countZipcode = countCity = 0;
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
                id[countId++] = c;
            // Prénom Nom
            else if (count == 1)
            {
                if (c == ' ')
                    countSpaces++;
                if (countSpaces == 0)
                {
                    firstname[countFirstname] = c;
                    countFirstname++;
                }
                else if (!(c == ' ' && countSpaces == 1))
                {
                    lastname[countLastname] = c;
                    countLastname++;
                }
            }
            // Date de naissance
            else if (count == 2)
                dob[countDob++] = c;
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

        id[countId] = 
        lastname[countLastname] = 
        firstname[countFirstname] = 
        dob[countDob] = 
        number[countNumber] = 
        street[countStreet] = 
        zipcode[countZipcode] = 
        city[countCity] = '\0';
    }

    /* DEBUG */
    printf("ID          : %s\n", id);
    printf("Prenom Nom  : %s %s\n", firstname, lastname);
    printf("Dob         : %s\n", dob);
    printf("Numero voie : %s\n", number);
    printf("Voie        : %s\n", street);
    printf("Code postal : %s\n", zipcode);
    printf("Ville       : %s\n\n", city);
}

void createXML(char * id, char * lastname, char * firstname, char * number, char * street, char * zipcode, char * city)
{
    // Créé le fichier courrier_npa avec l'id
    char buf[38];
    snprintf(buf, sizeof(buf), "E:\\Projects\\bts1\\BTS1\\02_C\\06_Fichiers\\02_csv2xml\\export_npa\\courrier_npa_%s.xml", id);
    FILE * xml = fopen(buf, "a");

    for (int i = 0; i < 10; i++)
    {
        switch (i)
        {
        case 0:
            fprintf(xml, "<?xml version=\"1.0\" encoding=\"UTF-8\"?>");
            break;
        case 1:
            fprintf(xml, "<CLIENT>");
            break;
        case 2:
            toUpperExtended(lastname);
            fprintf(xml, "\t<LASTNAME>%s</LASTNAME>", lastname);
            break;
        case 3:
            fprintf(xml, "\t<FIRSTNAME>%s</FIRSTNAME>", firstname);
            break;
        case 4:
            fprintf(xml, "\t<ADDRESS>");
            break;
        case 5:
            fprintf(xml, "\t\t<STREET>%s %s</STREET>", number, street);
            break;
        case 6:
            fprintf(xml, "\t\t<ZIPCODE>%s</ZIPCODE>", zipcode);
            break;
        case 7:
            fprintf(xml, "\t\t<CITY>%s</CITY>", city);
            break;
        case 8:
            fprintf(xml, "\t</ADRESS>");
            break;
        case 9:
            fprintf(xml, "</CLIENT>");
            break;
        }
    }
}