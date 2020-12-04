#include <stdio.h>
#include <stdlib.h>


int main()
{
    int **iArr = NULL, iRows = 0, *iCols = NULL, i = 0, j = 0;
    printf("Enter the number of Rows:\t");
    scanf("%d", &iRows);
    if(iRows < 0 || iRows > 50)
    {
        printf("Out of range number of rows entered !!!\n");
        return -1;
    }
    iArr = (int **)malloc(sizeof(int*) * iRows);
    if(iArr == NULL)
    {
        printf("Memory Allocation Failed\n");
        return -1;
    }
    iCols = (int *)malloc(sizeof(int) * iRows);
    if(iCols == NULL)
    {
        printf("Memory Allocation Failed\n");
        return -1;
    }

    for(i = 0; i < iRows; i++)
    {
        printf("Enter the number of columns:\t");
        scanf("%d", &iCols[i]);
        if(iCols[i] < 0 || iCols[i] > 50)
        {
            printf("Out of range number of colummns entered !!!\n");
            return -1;
        }
        iArr[i] = (int*)malloc(sizeof(int) * iCols[i]);
        if(iArr[i] == NULL)
        {
            printf("Memory Allocation Failed\n");
            return -1;
        }
        for (j = 0; j < iCols[i]; j++)
        {
            scanf("%d", &iArr[i][j]);
        }
    }

    printf("Ragged Array is:\n");
    for (i = 0; i < iRows; i++)
    {
        for (j = 0; j < iCols[i]; j++)
        {
            printf("%d\t", iArr[i][j]);
        }
        printf("\n");
    }

    for (i = 0; i < iRows; i++)
    {
        free(iArr[i]);
    }
    free(iArr);
    free(iCols);

    return 0;
}
