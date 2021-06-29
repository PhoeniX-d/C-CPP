/*
*   Program to check whether matrix is Toeplitz matrix(contains maximum 0's than 1's)
*   or not
*/
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;

BOOL IsToeplitz(int **, int, int);

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

    if (iRow != iCol)
    {
        printf("Number of Rows should match with number of Columns\n");
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
    bRet = IsToeplitz(iArr, iRow, iCol);
    if (bRet == TRUE)
    {
        printf("\nEnterd Matrix is a Toeplitz Matrix\n");
    }
    else
    {
        printf("\nEnterd Matrix is not a Toeplitz Matrix\n");
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
//  Name        :IsToeplitz
//  Input       :int[][], int, int
//  Returns     :int
//  Description :Checks whether entered matrix is Toeplitz
//               matrix or not
//  Author      :Pranav Choudhary
//  Date        :7 Oct 2020
//
/////////////////////////////////////////////////////////////
BOOL IsToeplitz(int *iArr[], int iRow, int iCol)
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

    if (iRow != iCol)
    {
        printf("Number of Rows should match with number of Columns\n");
        return -1;
    }

    int i = 0, j = 0;
    BOOL bFlag = TRUE;

    for (i = 0; i < (iRow - 1) && bFlag == TRUE; i < i++)
    {
        for (j = 0; j < (iCol - 1); j++)
        {
            if (iArr[i][j] != iArr[i + 1][j + 1])
            {
                bFlag = FALSE;
                break;
            }
        }
    }
    return bFlag;
}
