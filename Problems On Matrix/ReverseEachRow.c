/*
*   Write a program which accept matrix and reverse the contents of each row. 
*/
#include<stdio.h>
#include<stdlib.h>

void ReverseRows(int*[], int, int);

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
    ReverseRows(iArr, iRow, iCol);

    printf("\nAfter reverse rows Matrix becomes:\n");
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

/////////////////////////////////////////////////////////////
//
//  Name        :ReverseRows
//  Input       :int[][], int, int
//  Returns     :int
//  Description :Reverses the contents of each row
//  Author      :Pranav Choudhary
//  Date        :7 Oct 2020
//
/////////////////////////////////////////////////////////////
void ReverseRows(int *iArr[], int iRow, int iCol)
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

    int i = 0, j = 0, iTemp = 0;
    for (i = 0; i < iRow; i++)
    {
        for (j = 0; j < iCol / 2; j++)
        {
            iTemp = iArr[i][j];
            iArr[i][j] = iArr[i][iCol - j - 1];
            iArr[i][iCol - j - 1] = iTemp;
        }
    }
}