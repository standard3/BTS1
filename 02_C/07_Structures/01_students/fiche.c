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
void clearScreen();

int main()
{
    struct student
    {
        char name[CHAR_MAXIMUM];
        char surname[CHAR_MAXIMUM];
        short age;
        short level;
    };

    struct student student;
    short choice;
    
    system("chcp 65001");
    clearScreen();

    // Implémenter boucle while pour attendre bonne saisie
    printf("1. Afficher la liste des fiches \n2. Créer une fiche \n3. Quitter \n");
    scanf("%d", &choice);

    if (choice == 1) // Afficher la liste des fiches
    {
        // Implémenter newlign pour chaque fiche
        printf("+----------------------------------+----------------------------------+---------+-------------+\n");
        printf("|               Nom                |              Prénom              |   Age   |    Classe   |\n");
        printf("+----------------------------------+----------------------------------+---------+-------------+\n");
        printf("| %30s                             | %30s                             |   %2d   | %2d         |\n", student.surname, student.name, student.age, student.level);
        return 0;
        // Supprimer la liste des fiches
    }
    else if (choice == 2) // Créer une fiche
    {
        do
        {
            clearScreen();
            printf("Saisir le nom de l'élève (30 caractères au maximum) : \n");
            scanf("%s", &student.surname);

            if (strlen(student.surname) >= CHAR_MAXIMUM)
            {
                printf("La saisie ne peut pas contenir plus de 30 caractères. \n");
                Sleep(3000);
            }
            
            // Mettre toutes les lettres en majuscule
        } while (strlen(student.surname) >= CHAR_MAXIMUM);
        
        do
        {
            clearScreen();
            printf("Saisir le prénom de l'élève (30 caractères au maximum) : \n");
            scanf("%s", &student.name);
            
            if (strlen(student.name) >= CHAR_MAXIMUM)
            {
                printf("La saisie ne peut pas contenir plus de 30 caractères. \n");
                Sleep(3000);
            }
            // Mettre première lettre en majuscule
        } while (strlen(student.name) >= CHAR_MAXIMUM);
        
        do
        {
            clearScreen();
            printf("Saisir l'âge de l'élève (27 ans maximum) : \n");
            scanf("%d", &student.age);

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
            scanf("%d", &student.level);

            if (student.level < -2 || student.level > 2)
            {
                printf("Saisie incorrecte. \n");
                Sleep(3000);
            }

        } while (student.level < -2 || student.level > 2);
    }
    else if (choice == 3)
        return 0;
    else
        printf("Erreur de saisie, veuillez réessayer.\n");
    

    return 0;
}

void clearScreen() { system("cls"); }