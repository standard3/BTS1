#include <stdio.h>

#define CHAR_MAXIMUM 31

struct Student
{
    char    name[CHAR_MAXIMUM];
    char surname[CHAR_MAXIMUM];
    short   age;
    short level;
};

int main()
{
    struct Student student;
    int sizeStudent = sizeof(student);
    int sizeMemberStudent = sizeof(student.name) + sizeof(student.surname) + sizeof(student.age) + sizeof(student.level);

    printf("sizeStudent : %d octets\nsizeMemberStudent : %d octets\n", sizeStudent, sizeMemberStudent);

    FILE * file = fopen("test.bin", "wb");
    fwrite(&student, sizeof(student), 1, file);
    fclose(file);
    return 0;
}