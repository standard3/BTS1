#include <string.h>
#include <ctype.h>
#include <time.h>

void toUpperExtended(char *);
void getToday(int *);

/*
int main() {
    system("chcp 65001");

    // Get and display current date
    int today[3];
    getToday(today);
    printf("%02d/%02d/%4d\n", today[2], today[1], today[0]);

    // To upper extended chars
    char city[] = "de l'Andaï";
    toUpperExtended(city);
    puts(city);
}
*/

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

/**
 * Replace extended chararacters non replaced by classic toupper()
 * @param today An empty array of 3 integers which will be filled following this template : [year, month, day]
 * @return Nothing
 * */ 
void getToday(int * today) {
    time_t t = time(NULL);
    struct tm tm = *localtime(&t);
    today[0] = tm.tm_year + 1900;
    today[1] = tm.tm_mon + 1;
    today[2] = tm.tm_mday;
}