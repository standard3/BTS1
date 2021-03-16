#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifdef _WIN32
#include <windows.h>
#else
#include <unistd.h>
#endif

#define CHAR_MAXIMUM 31
#define AGE_MIN 13
#define AGE_MAX 27

/* TODO:
* Saisie de fiche
* Affichage simple de fiche
*/

struct Student
{
    char    name[CHAR_MAXIMUM];
    char surname[CHAR_MAXIMUM];
    short   age;
    short level;
};

void drawCard();
void createCard(struct Student);
void save      (struct Student);
void delete();
void clearScreen();
void toUpperExtended(char *);

int main()
{
    struct Student student;
    int    choice;
    char   input[CHAR_MAXIMUM];
    FILE * file = fopen("E:\\Projects\\bts1\\BTS1\\02_C\\07_Structures\\01_students\\fiche", 'a');
    
    system("chcp 65001");

    do
    {
        //clearScreen(); /* À REMETTRE EN FIN DE PROGRAMME */
        printf("1. Afficher la liste des fiches \n2. Créer une fiche \n3. Quitter \n");
        gets(input);
        sscanf(input, "%d", &choice);
        
        if (choice == 1) // Afficher la liste des fiches
        {
            drawCard();
            // Implémenter suppression liste des fiches
            // delete();
            return 0;
        }
        else if (choice == 2) // Créer une fiche
        {
            do
            {
                clearScreen();
                printf("Saisir le nom de l'élève (30 caractères au maximum) : \n");
                gets(input);
                sscanf(input, "%s", &student.surname);

                if (strlen(student.surname) >= CHAR_MAXIMUM)
                {
                    printf("La saisie ne peut pas contenir plus de 30 caractères. \n");
                    Sleep(3000);
                }
                
                toUpperExtended(student.surname);
            } while (strlen(student.surname) >= CHAR_MAXIMUM);
            
            do
            {
                clearScreen();
                printf("Saisir le prénom de l'élève (30 caractères au maximum) : \n");
                gets(input);
                sscanf(input, "%s", &student.name);
                
                if (strlen(student.name) >= CHAR_MAXIMUM)
                {
                    printf("La saisie ne peut pas contenir plus de 30 caractères. \n");
                    Sleep(3000);
                }
                
                // Mettre première lettre en maj
                //toUpperExtended(&(student.name + 1));
                //puts(student.name);
                //Sleep(100000);
            } while (strlen(student.name) >= CHAR_MAXIMUM);
            
            do
            {
                clearScreen();
                printf("Saisir l'âge de l'élève (27 ans maximum) : \n");
                gets(input);
                sscanf(input, "%d", &student.age);

                if (student.age >= AGE_MAX)
                {
                    printf("L'âge ne peut pas être supérieur à %d ans. \n", AGE_MAX);
                    Sleep(3000);
                }
                else if (student.age <= AGE_MIN)
                {
                    printf("L'âge ne peut pas être inférieur à %d ans. \n", AGE_MIN);
                    Sleep(3000);
                }
                    
            } while (student.age >= AGE_MAX || student.age <= AGE_MIN);
                
            do
            {
                clearScreen();
                printf("-2 = Seconde, -1 = Première, 0 = Terminale, 1 = BTS1, 2 = BTS2 \n");
                printf("Saisir le niveau de l'élève : \n");
                gets(input);
                sscanf(input, "%d", &student.level);

                if (student.level < -2 || student.level > 2)
                {
                    printf("Saisie incorrecte. \n");
                    Sleep(3000);
                }

            } while (student.level < -2 || student.level > 2);

            // Stocker dans tableau
        }
        else if (choice == 3) // Quitter
            return 0;
        else
            printf("Erreur de saisie, veuillez réessayer.\n");

    } while(1);

    return 0;
}

void drawCard()
{
    // Implémenter protection si aucune liste n'existe
    // Implémenter newlign pour chaque fiche
    clearScreen();
    printf("+----------------------------------+----------------------------------+---------+-------------+\n");
    printf("|               Nom                |              Prénom              |   Age   |    Classe   |\n");
    printf("+----------------------------------+----------------------------------+---------+-------------+\n");
    // Boucle for pour chopper tous les etudiants dans le fichier binaire
    printf("| %-32s | %-32s | %-7d | %-11d |\n", student.surname, student.name, student.age, student.level);
    printf("+----------------------------------+----------------------------------+---------+-------------+\n");
}

void createCard(struct Student student)
{

}

void save(struct Student student)
{

}

void delete()
{

}

void clearScreen() { system("cls"); }

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