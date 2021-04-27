#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int **allocateMatrix(int, int, int);
void freeMatrix(int**, int);

int main(int argc, char ** argv)
{
    if (argc < 4)
    {
        printf("Utilisation : exercice5.out <lignes> <colonnes> <valeur>");
        return 0;
    }
    
    int rows = atoi(*(argv + 1));
    int cols = atoi(*(argv + 2));
    int **matrix = allocateMatrix(rows, cols, atoi(*(argv + 3)));

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
            printf("[%d]", matrix[i][j]);
        printf("\n");
    }

    freeMatrix(matrix, rows);
    return 0;
}

int **allocateMatrix(int rows, int cols, int value)
{
    int ** matrix = (int**) malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++)
    {
        matrix[i] = (int*) malloc(cols * sizeof(int));
        for (int j = 0; j < cols; j++)
            matrix[i][j] = value; // Affectation
    } 
        

    return matrix;
}

void freeMatrix(int ** matrix, int rows)
{
    for (int i = 0; i < rows; i++)
        free(matrix[i]);
    free(matrix);
}