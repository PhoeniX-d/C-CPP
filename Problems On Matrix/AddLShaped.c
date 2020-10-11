/*
*   Program to add L shaped subarray
*/
#include <stdio.h>
#include <stdlib.h>

void AddSubarray(int **, int, int);

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
    AddSubarray(iArr, iRow, iCol);

    // Deallocation
    for (i = 0; i < iRow; i++)
    {
        free(iArr[i]);
    }
    free(iArr);

    return (0);
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :AddSubarray
//  Input       :int[][], int, int
//  Returns     :int*
//  Description :Add all L shaped subarray
//  Author      :Pranav Choudhary
//  Date        :10 Oct 2020
//
//////////////////////////////////////////////////////////////////////
void AddSubarray(int **iArr, int iRow, int iCol)
{
    if (iArr == NULL)
    {
        printf("Invalid inputs for ReplaceCol()\n");
        return;
    }

    // Updator
    if (iRow < 0)
        iRow = -iRow;
    if (iCol < 0)
        iCol = -iCol;

    int L = 0, d = 0, r = 0, iSum = 0;

    for (L = 0; L < iCol; L++)
    {
        /* Travel from top to bottom */
        for (d = 0; d < iCol - L; d++)
        {
            iSum = iSum + iArr[d][L];
        }

        /* Travel from left to right */
        for (r = L; r < iCol - L; r++)
        {
            iSum = iSum + iArr[d - 1][r];
        }
        printf("Summation\t:%d\n", iSum);
        iSum = 0;
    }
}