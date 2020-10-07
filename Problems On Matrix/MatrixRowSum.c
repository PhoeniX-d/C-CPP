/*
*   Program to perform seperate addition of the Matrix rows
*/
#include <stdio.h>
#include <stdlib.h>

int *RowsSum(int **, int, int);

int main()
{
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

    iRet = (int *)malloc(sizeof(int) * iRow);
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
    iRet = RowsSum(iArr, iRow, iCol);
    if (iRet == NULL)
    {
        return -1;
    }
    printf("\nSummation of Matrix rows are:\n");
    for (i = 0; i < iRow; i++)
    {
        printf("%d\n", iRet[i]);
    }
    // Deallocation
    for (i = 0; i < iRow; i++)
    {
        free(iArr[i]);
    }
    free(iRet);
    free(iArr);

    return (0);
}

/////////////////////////////////////////////////////////////
//
//  Name        :RowsSum
//  Input       :int[][], int, int
//  Returns     :int
//  Description :Adds each row of matrix seperately
//  Author      :Pranav Choudhary
//  Date        :7 Oct 2020
//
/////////////////////////////////////////////////////////////
int *RowsSum(int *iArr[], int iRow, int iCol)
{
    if (iArr == NULL)
    {
        printf("Invalid Inputs\n");
        return 0;
    }
    if (iRow < 0)
        iRow = -iRow;
    if (iCol < 0)
        iCol = -iCol;

    int i = 0, j = 0, *iSum = NULL;
    iSum = (int *)malloc(sizeof(int) * iRow);
    if (iSum == NULL)
    {
        printf("Unable to allocate memmory\n");
        return NULL;
    }
    for (i = 0; i < iRow; i < i++)
    {
        iSum[i] = 0;
        for (j = 0; j < iCol; j++)
        {
            iSum[i] = iSum[i] + iArr[i][j];
        }
    }
    return iSum;
}
