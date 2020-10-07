/*
*   Program to check whether matrix is Identity matrix(contains only 0's and 1's)
*   or not
*/
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;

BOOL IsIdentity(int **, int, int);

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
    bRet = IsIdentity(iArr, iRow, iCol);
    if (bRet == TRUE)
    {
        printf("\nEnterd Matrix is an Identity Matrix\n");
    }
    else
    {
        printf("\nEnterd Matrix is not an Identity Matrix\n");
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
//  Name        :IsIdentity
//  Input       :int[][], int, int
//  Returns     :int
//  Description :Checks whether entered matrix is Identity
//               matrix or not
//  Author      :Pranav Choudhary
//  Date        :7 Oct 2020
//
/////////////////////////////////////////////////////////////
BOOL IsIdentity(int *iArr[], int iRow, int iCol)
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
        return FALSE;
    }

    int i = 0, j = 0;
    BOOL bFlag = TRUE;
    for (i = 0; i < iRow; i < i++)
    {
        for (j = 0; j < iCol; j++)
        {
            if (i == j && iArr[i][j] != 1)
            {
                bFlag = FALSE;
                break;
            }
        }
    }

    if (bFlag == FALSE)
    {
        return FALSE;
    }
    return TRUE;
}
