#include <stdio.h>
#include <stdlib.h>
#include "my_mat.h"
#define MATRIX_SIZE 10
int main()
{
    int i, j;
    char action;
    int** matrix= (int**) malloc(MATRIX_SIZE* sizeof(int));                 
    for(int i = 0; i < MATRIX_SIZE; i++)
    {
       matrix[i]= (int*) malloc(MATRIX_SIZE* sizeof(int));
    }

    do
    {
        scanf("%c", &action);
        switch (action)
        {
        case 'A':
        {                       
            acceptMatrixValues(matrix, MATRIX_SIZE);
            break;
        }

        case 'B':
        {
            scanf("%d%d", &i, &j);
            printf("%s\n", (isTherePath(matrix, i, j)>0? "yes": "no"));
            break;
        }
        case 'C':
        {
            scanf("%d%d", &i, &j);
            printf("%d\n", weightOfShortestPath(matrix, i, j, MATRIX_SIZE));
            break;
        }
        default:
            break;
        }
    } while (action!='D' && action!=EOF);

    for (int i = 0; i < MATRIX_SIZE; i++)
    {
        free(matrix[i]);
    }
    free(matrix);
    return 0;

}