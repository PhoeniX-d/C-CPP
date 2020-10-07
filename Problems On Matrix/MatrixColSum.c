/*
*   Program to perform seperate addition of the Matrix rows
*/
#include <stdio.h>
#include <stdlib.h>

void ColumnSum(int **, int, int);

int main()
{
    int iRow = 0, iCol = 0, i = 0, j = 0;
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
    ColumnSum(iArr, iRow, iCol);

    // Deallocation
    for (i = 0; i < iRow; i++)
    {
        free(iArr[i]);
    }
    free(iArr);

    return (0);
}

/////////////////////////////////////////////////////////////
//
//  Name        :ColumnSum
//  Input       :int[][], int, int
//  Returns     :int
//  Description :Adds each columns of matrix seperately
//  Author      :Pranav Choudhary
//  Date        :7 Oct 2020
//
/////////////////////////////////////////////////////////////
void ColumnSum(int *iArr[], int iRow, int iCol)
{
    if (iArr == NULL)
    {
        printf("Invalid Inputs\n");
        return;
    }
    if (iRow < 0)
        iRow = -iRow;
    if (iCol < 0)
        iCol = -iCol;

    int i = 0, j = 0, *iColSum = NULL;
    iColSum = (int *)malloc(sizeof(int) * iCol);
    if (iColSum == NULL)
    {
        printf("Unable to allocate memmory\n");
        return;
    }
    for (i = 0; i < iCol; i++)
    {
        iColSum[i] = 0;
    }
    for (i = 0; i < iRow; i < i++)
    {
        for (j = 0; j < iCol; j++)
        {
            iColSum[j] = iColSum[j] + iArr[i][j];
        }
    }
    printf("Summation of each column elements are:\n");
    for (i = 0; i < iCol; i++)
    {
        printf("%-3d", iColSum[i]);
    }
}
