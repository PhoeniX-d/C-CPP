/*
*   Program to accept matrix from user and replace last column 
*   of that matrix with sum of that particular rows numbers digits
*/
#include <stdio.h>
#include <stdlib.h>

void ReplaceCol(int **, int, int);

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
    ReplaceCol(iArr, iRow, iCol);

    printf("\nMatrix after repalcement\n");
    for (i = 0; i < iRow; i++)
    {
        for (j = 0; j < iCol; j++)
        {
            printf("%-3d", iArr[i][j]);
        }
        printf("\n");
    }

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
//  Name        :ReplaceCol
//  Input       :int[][], int, int
//  Returns     :int*
//  Description :Replace last column with summation of digits of
//               numbers in that row
//  Author      :Pranav Choudhary
//  Date        :10 Oct 2020
//
//////////////////////////////////////////////////////////////////////
void ReplaceCol(int **iArr, int iRow, int iCol)
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

    int i = 0, j = 0, iSum = 0, iTemp = 0;

    for (i = 0; i < iRow; i++)
    {
        for (j = 0; j < iCol; j++)
        {
            iTemp = iArr[i][j];
            while (iTemp != 0)
            {
                iSum = iSum + iTemp % 10;
                iTemp = iTemp / 10;
            }
        }
        iArr[i][j - 1] = iSum;
        iSum = 0;
    }
}
