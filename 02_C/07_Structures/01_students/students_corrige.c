#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct student
{
    char lastname[31];
    char firstname[31];
    int age;
    int grade;
};

int displayMainMenu();
int displayListMenu(int);
void toUpperExtended(char *);
void UCFirstExtended(char *);
struct student getStudent();
void displayStudent(struct student);
int displayStudents(struct student *, int);
void orderStudents(struct student *, int);
int compareStudents(struct student, struct student);
void save(struct student *, int);
void saveExcept(struct student *, int, int);
int load(struct student *);

int main () {
    struct student students[100];
    int studentsCount = load(students), choice, toDelete;

    system("chcp 65001");

    while ((choice = displayMainMenu()) != 0) {
        switch (choice) {
            case 1 : 
                students[studentsCount] = getStudent();
                studentsCount++;
                orderStudents(students, studentsCount);
                save(students, studentsCount);
                break;
            case 2 :
                toDelete = displayStudents(students, studentsCount);
                if (toDelete > 0) {
                    saveExcept(students, studentsCount, toDelete - 1);
                    studentsCount = load(students);
                }
                break;
        }
    }

    return 0;
}

/**
 * Replace extended chararacters non replaced by classic toupper()
 * @param destination The string in which the characters must be replaced
 * @return Nothing (argument passed by address)
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

/**
 * Replace extended chararacters non replaced by classic toupper()
 * @param destination The string in which the characters must be replaced
 * @return Nothing (argument passed by address)
 * */ 
void UCFirstExtended(char * destination) {
    char extended[] = "áàâäãåæçéèêëíìîïñóòôöõøœúùûü",
         upper[]    = "ÁÀÂÄÃÅÆÇÉÈÊËÍÌÎÏÑÓÒÔÖÕØŒÚÙÛÜ",
         c, p = ' ';
    for (int i = 0; i < strlen(destination); i++) {
        if (i == 0 || p == '-') {
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
        p = destination[i];
    }
}

// Menu
int displayMainMenu() {
    int choice;
    char input[2];
    
    system("cls");

    printf("[Fichier des élèves]\n");
    printf("[1] Saisir une fiche\n");
    printf("[2] Voir la liste complète\n");
    printf("[0] Quitter\n> ");

    do {
        gets(input);
        sscanf(input, "%d", &choice);
    } while(choice < 0 || choice > 2);

    return choice;
}

// Lecture
struct student getStudent() {
    struct student s;
    char input[31];
    
    system("cls");

    printf("[Saisie d'une fiche]\n");

    // Saisie du nom
    printf("Nom : ");
    gets(s.lastname);
    toUpperExtended(s.lastname);
    
    // Saisie du prénom
    printf("Prénom : ");
    gets(s.firstname);
    UCFirstExtended(s.firstname);
    
    // Saisie de l'âge
    do {
        printf("Age : ");
        gets(input);
        sscanf(input, "%d", &s.age);
    } while(s.age < 0 || s.age > 27);

    // Saisie de la classe
    do {
        printf("[-2] Seconde  [-1] Première  [0] Terminale  [1] BTS1  [2] BTS2\nClasse : ");
        gets(input);
        sscanf(input, "%d", &s.grade);
    } while (s.grade < -2 || s.grade > 2);

    displayStudent(s);

    return s;
}

// Affichage solo
void displayStudent(struct student s) {
    char grades[5][10] = {"Seconde", "Première", "Terminale", "BTS1", "BTS2"}; 

    system("cls");
    
    printf("[Fiche saisie]\n   NOM : %s\nPrénom : %s\n   Age : %d\nClasse : %s\n\n", s.lastname, s.firstname, s.age, grades[s.grade + 2]);

    system("pause");
}

// Affichage tableau
int displayStudents(struct student * students, int studentsCount) {
    char grades[5][10] = {"Seconde", "Première", "Terminale", "BTS1", "BTS2"}; 
    int i;

    system("cls");

    printf("[Liste complète des fiches]\n\n");
    printf("N°  Nom                            Prénom                         Age Classe\n");
    printf("-----------------------------------------------------------------------------------\n");
    for(i = 0; i < studentsCount; i++) {
        printf("%3d %-30s %-30s %3d %-12s\n", i + 1, students[i].lastname, students[i].firstname, students[i].age, grades[students[i].grade + 2]);
    }
    printf("\n");
    
    return displayListMenu(studentsCount);
}

void orderStudents(struct student * students, int studentsCount) {
    int i, j;
    struct student temp;
    for (i = 0; i < studentsCount; i++) {
        for (j = i + 1; j < studentsCount; j++) {
            if (compareStudents(students[i], students[j])) {
                temp = students[i];
                students[i] = students[j];
                students[j] = temp;
            }
        }
    }
}

int compareStudents(struct student a, struct student b) {
    int c = strcmp(a.lastname, b.lastname);
    return  c > 0 || (c == 0 && strcmp(a.firstname, b.firstname));
}

int displayListMenu(int studentsCount) {
    char input[3];
    int choice;

    printf("[0] Retour\n[1] Supprimer une ligne\n> ");

    do {
        gets(input);
        sscanf(input, "%d", &choice);
    } while(choice != 0 && choice != 1);

    if (choice == 1) {
        printf("\nIndiquer le numéro de la ligne à supprimer ou 0 pour annuler :\n");
        do {
            printf("> ");
            gets(input);
            sscanf(input, "%d", &choice);
        } while(choice < 0 || choice > studentsCount);
    }

    return choice;
}

void save(struct student * students, int studentsCount) {
    FILE * fs = fopen("./students.dat", "wb");
    if (fs != NULL) {
        fwrite(students, sizeof(struct student), studentsCount, fs);
    }
    fclose(fs);
}

void saveExcept(struct student * students, int studentsCount, int toDelete) {
    int i;
    FILE * fs = fopen("./students.dat", "wb");
    if (fs != NULL) {
        for (i = 0; i < studentsCount; i++) {
            if (i != toDelete) {
                fwrite(students + i, sizeof(struct student), 1, fs);
            }
        }
    }
    fclose(fs);
}

int load(struct student * students) {
    int i;
    struct student s;
    FILE * fs = fopen("./students.dat", "rb");
    if (fs != NULL) {
        for (i = 0; fread(&s, sizeof(struct student), 1, fs) != 0; i++) {
            students[i] = s;
        }
    }
    fclose(fs);
    return i;
}