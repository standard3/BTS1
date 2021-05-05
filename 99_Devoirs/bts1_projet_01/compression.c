#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

#define MAX_KEY   4
#define MAX_VALUE 40

typedef struct
{
    char key[MAX_KEY];
    char value[MAX_VALUE];
}
Identifier;

int   countLinesInDictionnary (FILE*);
int   isInDictionnary         (int, Identifier[], char[]);
void  putInDictionnary        (int, FILE*,        char[]);
char* toLowerExtended         (char[]);
int   isDigitExtended         (char[]);
int   findIndexOf             (int, Identifier[], char[]);

/*  TODO:
*   Implémenter les valeurs numériques ou chaînes de caractères statiques (Surface...)
*   Implémenter système pour détecter si un chiffre (oui = pas de compression, pas d'entrée dans grammar.csv, sinon ignorer)
*   Implémenter système pour prendre en compte les éléments numériques ET chaînes de caractères (ex: )
*   Afficher arguments[] dans sortie standard
*/

// Si temps restant, optimiser avec passage d'arguments par pointeurs

int main(int argc, char * argv[])
{
    if (!((argc - 1) % 2 == 0)) // Si impair
    {
        printf("Error : key without value (%d arguments)\n", argc);
        return -1;
    } 
    
    FILE      *grammar = fopen("/home/abel/Desktop/Repositories/BTS1/99_Devoirs/bts1_projet_01/gramar.csv", "ra");
    int        grammarLinesCount = countLinesInDictionnary(grammar);
    int        j = 0;
    char      *buffer;
    Identifier arguments  [(argc - 1) / 2];
    Identifier dictionnary[grammarLinesCount];

    // Stockage des arguments d'entrée dans la structure
    for (int i = 1; i < argc; i++)
    {
        if (!(i % 2 == 0))
        {
            strcpy(arguments[j].key, argv[i]);
            j++;
        }
        else 
            strcpy(arguments[j - 1].value, argv[i]);

        // Si le mot n'a pas d'équivalence, on la créer
        if (!isInDictionnary(grammarLinesCount, dictionnary, argv[i]))
            putInDictionnary(grammarLinesCount, grammar, toLowerExtended(argv[i]));
    }

    // FIXXXXXX
    // Stockage du dictionnaire dans la structure
    fseek(grammar, 0, SEEK_SET);
    for (int i = 0; i < grammarLinesCount; i++)
        fscanf(grammar, "%s:%[^\n]", dictionnary[i].key, dictionnary[i].value);


    /* TEST Affichage du dictionnaire */
    for (int i = 0; i < grammarLinesCount; i++)
        printf("[%s:%s]\n", dictionnary[i].key, dictionnary[i].value);
    

    // Conversion des mots par leurs index dans le dictionnaire 
    for (int i = 0; i < argc; i++)
    {
        itoa(findIndexOf(grammarLinesCount, dictionnary, arguments[i].key), buffer, 10);
        strcpy(arguments[i].key, buffer);
        itoa(findIndexOf(grammarLinesCount, dictionnary, arguments[i].value), buffer, 10);
        strcpy(arguments[i].value, buffer);
    }

    // Format de fin : 1:200;:2;2:2;3:48;4:58,3,78;

    fclose(grammar);
    return 0;
}

/**
 * Count number of lines of the dictionnary
 * @param grammar Dictionnary file stream
 * @return Number of lines
 * */ 
int countLinesInDictionnary(FILE *grammar)
{
    int  counter;
    char ch;

    if (grammar != NULL)
    {
        while ((ch = fgetc(grammar)) != EOF)
            if (ch == '\n')
                counter++;
        return counter;
    }
    else
    {
        printf("Error : grammar file cannot be opened\n");
        exit(0);
    }
}

/**
 * Check if a string is in dictionnary
 * @param grammarLinesCount Number of lines of the file
 * @param dictionnary Identifier of dictionnary
 * @param word String to check if it's in dictionnary
 * @return 1 if string is in dictionnary, else 0
 * */ 
int isInDictionnary(int grammarLinesCount, Identifier dictionnary[], char word[])
{
    for (int i = 0; i < grammarLinesCount; i++)
        if (strcmp(dictionnary[i].value, word) == 0)
            return 1;

    return 0;
}

/**
 * Append a string to the dictionnary
 * @param grammarLinesCount Number of lines of the file
 * @param grammer Dictionnary file stream
 * @param word String to append into dictionnary
 * @return Nothing
 * */ 
void putInDictionnary(int grammarLinesCount, FILE *grammar, char word[])
{
    fprintf(grammar, "%d:%s", grammarLinesCount + 1, word);
}

/**
 * Lowercase a string
 * @param word The string in which the characters must be replaced
 * @return Lowercased string
 * */ 
char* toLowerExtended(char word[])
{
    char extended[] = "ÁÀÂÄÃÅÆÇÉÈÊËÍÌÎÏÑÓÒÔÖÕØŒÚÙÛÜ",
         lower[]    = "áàâäãåæçéèêëíìîïñóòôöõøœúùûü",
         c;
    for (int i = 0; i < strlen(word); i++) 
    {
        c = tolower(word[i]);
        if (c == word[i] && c != '-' && c != '\'') 
            for (int j = 0; j < strlen(extended); j++) 
                if (c == extended[j]) 
                {
                    c = lower[j];
                    break;
                }
        word[i] = c;
    }
    return word;
}

/**
 * Check if a string is full of digits
 * @param word The string in which we seek digits
 * @return 1 if the string is full of digits, else 0
 * */ 
int isDigitExtended(char word[])
{
    int counter;
    for (int i = 0; i < strlen(word); i++)
        if (isdigit(word[i]))
            counter++;

    if (counter == strlen(word))
        return 1;
    else
        return 0;
}

/**
 * Find index of a string in dictionnary
 * @param grammarLinesCount Number of lines of the file
 * @param dictionnary Identifier of dictionnary
 * @param word String to find index of
 * @return Index of word in dictionnary
 * */ 
int findIndexOf(int grammarLinesCount, Identifier dictionnary[], char word[])
{
    for (int i = 0; i < grammarLinesCount; i++)
        if (strcmp(dictionnary[i].value, word) == 0)
            return dictionnary[i].key;
}