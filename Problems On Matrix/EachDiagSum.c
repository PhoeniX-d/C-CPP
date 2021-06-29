/*
*   Program to perform addition of the each diagonal els of matrix
*/
#include <stdio.h>
#include <stdlib.h>

int* EachDiagSum(int **, int, int);

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

    if (iRow != iCol)
    {
        printf("Number of Rows should match with number of Columns\n");
        return -1;
    }

    iRet = (int *)malloc(sizeof(int) * (iRow * 2 - 1));
    if(iRet == NULL)
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
    iRet = EachDiagSum(iArr, iRow, iCol);
    printf("\nSummation of Each Diagonal elements of is:\n");
    if(iRet == NULL)
    {
        return -1;
    }
    for (i = 0; i < (iRow * 2 - 1); i++)
    {
        printf("%-3d", iRet[i]);
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

////////////////////////////////////////////////////////////////////
//
//  Name        :EachDiagSum
//  Input       :int[][], int, int
//  Returns     :int*
//  Description :Returns addition of the each diagonal els of matrix
//  Author      :Pranav Choudhary
//  Date        :7 Oct 2020
//
////////////////////////////////////////////////////////////////////
int* EachDiagSum(int *iArr[], int iRow, int iCol)
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

    if (iRow != iCol)
    {
        printf("Number of Rows should match with number of Columns\n");
        return NULL;
    }

    int i = 0, j = 0, *iSum = NULL, s = 0, x = 0, y = 0;
    iSum = (int *)malloc(sizeof(int) * (iRow + iCol - 1));
    if(iSum == NULL)
    {
        printf("Unable to allocate memory\n");
        return NULL;
    }
    for (i = 0; i < (iRow * 2 - 1); i++)
    {
        iSum[i] = 0;
    }

    /* Calculate Summation of diagonals of Lower trangular matrix */
    for (i = iRow - 1, s = 0; i >= 0; i--, s++)
    {
        for (j = 0, x = i; j < iCol - i && x < iRow; j++, x++)
        {
            iSum[s] = iSum[s] + iArr[x][j];
        }
    }

    /* Calculate Summation of digonals of Upper trangular matrix */
    for (j = 1; j < iCol; j++, s++)
    {
        for (i = 0, y = j; i < iRow - j && y < iCol; i++, y++)
        {
            iSum[s] = iSum[s] + iArr[i][y];
        }
    }
    return iSum;
}
