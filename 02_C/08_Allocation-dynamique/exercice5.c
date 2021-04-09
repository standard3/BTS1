#include <stdlib.h>
#include <stdio.h>

int **allocateMatrix(int, int, int);
void freeMatrix(int**, int);

#define ROWS 3
#define COLS 3

int main()
{
    int **matrix = allocateMatrix(ROWS, COLS, 0);

    for (int i = 0; i < ROWS; i++)
    {
        for (int j = 0; j < COLS; j++)
            printf("[%d]", matrix[i][j]);
        printf("\n");
    }

    freeMatrix(matrix, ROWS);
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