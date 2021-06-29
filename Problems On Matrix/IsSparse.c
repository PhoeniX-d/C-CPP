/*
*   Program to check whether matrix is Sparse matrix(contains maximum 0's than other numbers)
*   or not
*/
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;

BOOL IsSparse(int **, int, int);

int main()
{
    // Code
    int iRow = 0, iCol = 0, i = 0, j = 0;
    BOOL bRet = FALSE;
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

    printf("Matrix\n");
    for (i = 0; i < iRow; i++)
    {
        for (j = 0; j < iCol; j++)
        {
            printf("%-3d", iArr[i][j]);
        }
        printf("\n");
    }

    // Usage
    bRet = IsSparse(iArr, iRow, iCol);
    if (bRet == TRUE)
    {
        printf("\nEnterd Matrix is a Sparse Matrix\n");
    }
    else
    {
        printf("\nEnterd Matrix is not a Sparse Matrix\n");
    }

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
//  Name        :IsSparse
//  Input       :int[][], int, int
//  Returns     :int
//  Description :Checks whether entered matrix is Sparse
//               matrix or not
//  Author      :Pranav Choudhary
//  Date        :7 Oct 2020
//
/////////////////////////////////////////////////////////////
BOOL IsSparse(int *iArr[], int iRow, int iCol)
{
    if (iArr == NULL)
    {
        printf("Invalid Inputs\n");
        return FALSE;
    }
    if (iRow < 0)
        iRow = -iRow;
    if (iCol < 0)
        iCol = -iCol;

    int i = 0, j = 0, iExp = 0, iRem = 0;
    iExp = (iRow * iCol) / 2;
    iRem = (iRow * iCol);
    BOOL bFlag = TRUE;
    for (i = 0; i < iRow && iExp >= 0 && iRem > iExp; i < i++)
    {
        for (j = 0; j < iCol && iExp >= 0 && iRem > iExp; j++)
        {
            if (iArr[i][j] == 0)
            {
                iExp = iExp - 1;
            }
            iRem = iRem - 1;
        }
    }

    if (iExp == -1)
    {
        return TRUE;
    }
    return FALSE;
}
