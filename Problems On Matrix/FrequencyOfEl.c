/*
*   Write a program which accept matrix and one number from user and return
*   frequency of that number. 
*/
#include <stdio.h>
#include <stdlib.h>

int Maximum(int **, int, int, int);

int main()
{
    int iRow = 0, iCol = 0, i = 0, j = 0, iRet = 0, iNum = 0;
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

    printf("Enter the number\t:");
    scanf("%d", &iNum);

    // Usage
    iRet = Maximum(iArr, iRow, iCol, iNum);
    if (iRet != -1)
        printf("Frequency of %d in Matrix is\t:%d\n", iNum, iRet);
    else
        printf("Element not present in Matrix!\n");

    // Deallocation
    for (i = 0; i < iRow; i++)
    {
        free(iArr[i]);
    }
    free(iArr);
    return (0);
}

////////////////////////////////////////////////////////////////
//
//  Name        :Maximum
//  Input       :int[][], int, int, int
//  Returns     :int
//  Description :Return frequency of a number
//  Author      :Pranav Choudhary
//  Date        :7 Oct 2020
//
////////////////////////////////////////////////////////////////
int Maximum(int *iArr[], int iRow, int iCol, int iNum)
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

    int i = 0, j = 0, iCnt = 0;
    for (i = 0; i < iRow; i < i++)
    {
        for (j = 0; j < iCol; j++)
        {
            if (iNum == iArr[i][j])
            {
                iCnt++;
            }
        }
    }
    if (iCnt == 0)
    {
        return (-1);
    }
    return (iCnt);
}
