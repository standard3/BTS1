// gcc -lm prepareData.c -o prepareData.out && ./prepareData.out "Surface" "1200m2" "Niveau" "0" "Total niveaux" "1" "Issues" "5" "Pieces" "5" "Charpente" "Metallique" "Toit" "Acier" "Murs" "Parpaing beton" "Gaz" "Arrivee gaz de ville" "" "Nord est" "" "25m"

#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

#define MAX_KEY   4
#define MAX_VALUE 40

typedef struct
{
    char key[MAX_KEY];
    char value[MAX_VALUE];
}
Identifier;

typedef struct
{
    int  key;
    char value[MAX_VALUE];
}
Dictionnary;

Identifier*  compressData            (int, int, Dictionnary[], Identifier[]);
Dictionnary* fillDictionnary         (int, Dictionnary[], FILE*);
int          countLinesInDictionnary (FILE*);
int          isInDictionnary         (int, Dictionnary[], char[]);
void         putInDictionnary        (int, FILE*,         char[]);
char*        toLowerExtended         (char[]);
int          isDigitExtended         (char[]);
int          containsDigit           (char[]);
int          findIndexOf             (int, Dictionnary[], char[]);
char*        itoa                    (int, char*, int);

int main(int argc, char * argv[])
{
    if (!((argc - 1) % 2 == 0)) // Si impair
    {
        printf("Error : key without value (%d arguments => odd number)\n", argc);
        return -1;
    } 
    
    FILE        *grammar = fopen("gramar.csv", "a+"); // Read + append
    int         grammarLinesCount = countLinesInDictionnary(grammar);
    int         j = 0;
    Identifier  *arguments   = malloc((argc - 1) / 2    * sizeof(Identifier));
    Dictionnary *dictionnary = malloc(grammarLinesCount * sizeof(Dictionnary));
    
    // Stockage du dictionnaire dans la structure
    dictionnary = fillDictionnary(grammarLinesCount, dictionnary, grammar);

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
        if (!containsDigit(argv[i]) && !isDigitExtended(argv[i]) && !isInDictionnary(grammarLinesCount, dictionnary, argv[i]))
            putInDictionnary(grammarLinesCount, grammar, toLowerExtended(argv[i]));
    }

    // Màj du dictionnaire au cas où nouveau mot
    dictionnary = fillDictionnary(grammarLinesCount, dictionnary, grammar);
    
    // Conversion des mots par leurs index dans le dictionnaire
    arguments = compressData((argc - 1) / 2, grammarLinesCount, dictionnary, arguments); 
    
    // Format de fin : 1:200;:2;2:2;3:48;4:58,3,78;
    for (int i = 0; i < (argc - 1) / 2; i++)
        printf("%s:%s;", arguments[i].key, arguments[i].value);

    free(arguments);
    free(dictionnary);
    fclose(grammar);
    return 0;
}

/**
 * Compress data to export, replaces strings by their numerical value in dictionnary
 * @param totalIdentifier Number of total identifiers (key:value)
 * @param grammarLinesCount Number of lines in dictionnary
 * @param dictionnary Dictionnary to copy values from
 * @param arguments Identifier to return with compressed data
 * @return Compressed data
 * */ 
Identifier* compressData(int totalIdentifier, int grammarLinesCount, Dictionnary dictionnary[], Identifier arguments[])
{
    char buffer[256];
    for (int i = 0; i < totalIdentifier; i++)
    {
        // Clé
        itoa(
            findIndexOf(grammarLinesCount, dictionnary, arguments[i].key), 
            buffer, 
            10
        );
        strcpy(arguments[i].key, buffer);

        // Valeur
        if (!isDigitExtended(arguments[i].value)) // On ne compresse pas les chiffres
        {
            if (containsDigit(arguments[i].value)) // Chaine + entier (ex: Bouteilles x 25)
            {
                char tmpValue[41];
                char tmpNumber[5];

                sscanf(arguments[i].value, "%s x %s", tmpValue, tmpNumber);
                itoa(
                    findIndexOf(grammarLinesCount, dictionnary, tmpValue),
                    buffer,
                    10
                );
                strcat(buffer, tmpNumber);
                strcpy(arguments[i].value, buffer);
            }
            else // Chaine seulement
            {
                itoa(
                    findIndexOf(grammarLinesCount, dictionnary, arguments[i].value), 
                    buffer, 
                    10
                );
                strcpy(arguments[i].value, buffer);
            }
            
        }
    }

    return arguments;
}

/**
 * Count number of lines of the dictionnary
 * @param grammar Dictionnary file stream
 * @return Number of lines
 * */ 
int countLinesInDictionnary(FILE *grammar)
{
    int  counter = 0;
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
 * Fills a dictionnary structure with file stream 
 * @param grammarLinesCount Number of lines in dictionnary
 * @param dictionnary Dictionnary to copy values from
 * @param grammar Dictionnary file stream
 * @return Filled dictionnary
 * */ 
Dictionnary* fillDictionnary(int grammarLinesCount, Dictionnary dictionnary[], FILE *grammar)
{
    fseek(grammar, 0, SEEK_SET);
    for (int i = 0; i < grammarLinesCount; i++)
        fscanf(grammar, "%d:%[^\n]", &dictionnary[i].key, dictionnary[i].value);

    return dictionnary;
}

/**
 * Check if a string is in dictionnary
 * @param grammarLinesCount Number of lines of the file
 * @param dictionnary Identifier of dictionnary
 * @param word String to check if it's in dictionnary
 * @return 1 if string is in dictionnary, else 0
 * */ 
int isInDictionnary(int grammarLinesCount, Dictionnary dictionnary[], char word[])
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
    static int localCount = 1;
    fprintf(grammar, "\n%d:%s", grammarLinesCount + localCount + 1, word);
    localCount++;
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

    return (counter == strlen(word)) ? 1 : 0;
}

/**
 * Check if a string contains digits
 * @param word The string in which we seek digits
 * @return 1 if the string contains digits, else 0
 * */ 
int containsDigit(char word[])
{
    int counter;
    for (int i = 0; i < strlen(word); i++)
        if (isdigit(word[i]))
            counter++;

    return (counter > 0) ? 1 : 0;
}

/**
 * Find index of a string in dictionnary
 * @param grammarLinesCount Number of lines of the file
 * @param dictionnary Identifier of dictionnary
 * @param word String to find index of
 * @return Index of word in dictionnary
 * */ 
int findIndexOf(int grammarLinesCount, Dictionnary dictionnary[], char word[])
{
    for (int i = 0; i < grammarLinesCount; i++)
        if (strcmp(dictionnary[i].value, word) == 0)
            return dictionnary[i].key;
}

/**
 * Transforms int to ASCII
 * @param num Number to transform
 * @param buffer Where to store our result
 * @param base Base to convert to (only 10 supported)
 * @return buffer
 * */ 
char* itoa(int num, char* buffer, int base) {
    int curr = 0;
 
    if (num == 0) {
        // Base case
        buffer[curr++] = '0';
        buffer[curr] = '\0';
        return buffer;
    }
 
    int num_digits = 0;
 
    if (num < 0) {
        if (base == 10) {
            num_digits ++;
            buffer[curr] = '-';
            curr ++;
            // Make it positive and finally add the minus sign
            num *= -1;
        }
        else
            // Unsupported base. Return NULL
            return NULL;
    }
 
    num_digits += (int)floor(log(num) / log(base)) + 1;
 
    // Go through the digits one by one
    // from left to right
    while (curr < num_digits) {
        // Get the base value. For example, 10^2 = 1000, for the third digit
        int base_val = (int) pow(base, num_digits-1-curr);
 
        // Get the numerical value
        int num_val = num / base_val;
 
        char value = num_val + '0';
        buffer[curr] = value;
 
        curr ++;
        num -= base_val * num_val;
    }
    buffer[curr] = '\0';
    return buffer;
}