/*
*	Accept a matrix from user which contains information about specific area
*	Matrix contins only 2 types of element i.e. 0 and 1
*	1 indicates land and 0 indiicates  water.
*	We have to find all such lands which are completely surrounded by water
*	In  single matrix there may be possibility of 0 or more such lands
*	After geting specified land we've to display index of such land
*/
#include <stdio.h>
#include <stdlib.h>

void FindIsland(int **, int, int);

int main(int argc, char const *argv[])
{
    /* code */
    int iRow = 0, iCol = 0, i = 0, j = 0, *iRet = NULL;
    int **iArr = NULL;

    printf("Enter the total number of rows in a Matrix\t:");
    scanf("%d", &iRow);
    printf("Enter the total number of colums in a Matrix\t:");
    scanf("%d", &iCol);

    // Updator
    if (iRow < 0)
        iRow = -iRow;
    if (iCol < 0)
        iCol = -iCol;

    iRet = (int *)malloc(sizeof(int) * (iRow * 2 - 1));
    if (iRet == NULL)
    {
        printf("Unable to allocate memory\n");
        return -1;
    }
    iArr = (int **)malloc(sizeof(int *) * iRow);
    if (iArr == NULL)
    {
        printf("Unable to allocate memory\n");
        return -1;
    }

    // Allocation
    for (int i = 0; i < iRow; i++)
    {
        iArr[i] = (int *)malloc(sizeof(int) * iCol);
        if (iArr[i] == NULL)
        {
            printf("Unable to allocate memory\n");
            return -1;
        }
    }

    // Initialization
    printf("Enter the numbers\n");
    for (i = 0; i < iRow; i++)
    {
        for (j = 0; j < iCol; j++)
        {
            scanf("%d", &iArr[i][j]);
        }
    }

    printf("\nMatrix\n");
    for (i = 0; i < iRow; i++)
    {
        for (j = 0; j < iCol; j++)
        {
            printf("%-3d", iArr[i][j]);
        }
        printf("\n");
    }

    // Usage
    FindIsland(iArr, iRow, iCol);

    // Deallocation
    for (i = 0; i < iRow; i++)
    {
        free(iArr[i]);
    }
    free(iArr);

    return (0);
}

////////////////////////////////////////////////////////////////////
//
//  Name        :FindIsland
//  Input       :int[][], int, int
//  Returns     :int*
//  Description :Find a Island and displays its index
//  Author      :Pranav Choudhary
//  Date        :9 Oct 2020
//
////////////////////////////////////////////////////////////////////
void FindIsland(int **iArr, int iRow, int iCol)
{
    if (iArr == NULL)
    {
        printf("Invalid inputs to FindIsland()\n");
        return;
    }

    // Updator
    if (iRow < 0)
        iRow = -iRow;
    if (iCol < 0)
        iCol = -iCol;

    int i = 0, j = 0, iCnt = 0;
    for (i = 1; i < iRow - 1; i++)
    {
        for (j = 1; j < iCol - 1; j++)
        {
            if (iArr[i][j] == 1)
            {
                if (iArr[i - 1][j - 1] == 0 &&
                    iArr[i - 1][j] == 0 &&
                    iArr[i - 1][j + 1] == 0 &&
                    iArr[i][j + 1] == 0 &&
                    iArr[i][j - 1] == 0 &&
                    iArr[i + 1][j - 1] == 0 &&
                    iArr[i + 1][j] == 0 &&
                    iArr[i + 1][j + 1] == 0)
                {
                    printf("Island Found at index\t:%d and %d\n", i, j);
                    iCnt++;
                }
            }
        }
    }
    printf("Total Island found\t:%d\n\n", iCnt);
}
