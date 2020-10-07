/*
*   Write a program which accept matrix from user and display transpose of the
*   matrix. 
*/
#include<stdio.h>
#include<stdlib.h>

void Transpose(int*[], int, int);

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
    Transpose(iArr, iRow, iCol);

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
//  Name        :Transpose
//  Input       :int[][], int, int
//  Returns     :int
//  Description :Displays transpose of a matrix
//  Author      :Pranav Choudhary
//  Date        :7 Oct 2020
//
/////////////////////////////////////////////////////////////
void Transpose(int *iArr[], int iRow, int iCol)
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

    if (iRow != iCol)
    {
        printf("Number of Rows should match with number of Columns\n");
        return;
    }

    int i = 0, j = 0;
    /* Way 1 
    int **iArr2 = NULL;
    iArr2 = (int **)malloc(sizeof(int *) * iRow);
    if(iArr2 == NULL)
    {
        printf("Unable to allocate memory\n");
        return;
    }
    for (i = 0; i < iRow; i++)
    {
        iArr2[i] = (int *)malloc(sizeof(int) * iCol);
        if(iArr2[i] == NULL)
        {
            printf("Unable to allocate memory\n");
            return;
        }
        for (j = 0; j < iCol; j++)
        {
            iArr2[i][j] = iArr[j][i];
        }
    }
    */
    //Display Transpose
    printf("Transpose of matrix is\n");
    for (i = 0; i < iRow; i++)
    {
        for (j = 0; j < iCol; j++)
        {
            //printf("%-3d", iArr2[i][j]);
            printf("%-3d", iArr[j][i]);
        }
        printf("\n");
    }

    /* Deallocate
    for (i = 0; i < iRow; i++)
    {
        free(iArr2[i]);
    }
    free(iArr2);*/
}
