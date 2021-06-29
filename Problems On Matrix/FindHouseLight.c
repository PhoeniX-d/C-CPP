/*
*	Accept a matrix from user which contains information about specific area
*	Matrix contins only 2 types of element i.e. 1 and 2
*	1 indicates street lights and 2 indiicates  house.
*	We have to find all such houses which contains all path (verically and
*   horizontaly) street lights
*	After geting specified land we've to display index of such land
*/
#include <stdio.h>
#include <stdlib.h>
#define TRUE 1
#define FALSE 0
typedef int BOOL;

void FindHouse(int **, int, int);

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
    FindHouse(iArr, iRow, iCol);

    // Deallocation
    for (i = 0; i < iRow; i++)
    {
        free(iArr[i]);
    }
    free(iArr);

    return (0);
}

////////////////////////////////////////////////////////////////////
//
//  Name        :FindHouse
//  Input       :int[][], int, int
//  Returns     :int*
//  Description :Find a House with all path having street lights
//               and displays its index
//  Author      :Pranav Choudhary
//  Date        :9 Oct 2020
//
////////////////////////////////////////////////////////////////////
void FindHouse(int **iArr, int iRow, int iCol)
{
    if (iArr == NULL)
    {
        printf("Invalid inputs to FindHouse()\n");
        return;
    }

    // Updator
    if (iRow < 0)
        iRow = -iRow;
    if (iCol < 0)
        iCol = -iCol;

    int i = 0, j = 0, iCnt = 0, iLeft = 0, iRight = 0, iUp = 0, iDown = 0;
    BOOL bFlag = TRUE;
    for (i = 0; i < iRow; i++)
    {
        for (j = 0; j < iCol; j++)
        {
            if (iArr[i][j] == 2)
            {
                /* Traverse left of house */
                for (iLeft = 0; iLeft < j; iLeft++)
                {
                    if (iArr[i][iLeft] != 1)
                    {
                        bFlag = FALSE;
                        break;
                    }
                }

                /* Traverse right of house */
                for (iRight = j + 1; (iRight < iCol) && (bFlag == TRUE); iRight++)
                {
                    if (iArr[i][iRight] != 1)
                    {
                        bFlag = FALSE;
                        break;
                    }
                }

                /* Traverse up of house */
                for (iUp = 0; (iUp < i) && (bFlag == TRUE); iUp++)
                {
                    if (iArr[iUp][j] != 1)
                    {
                        bFlag = FALSE;
                        break;
                    }
                }

                /* Traverse down of house */
                for (iDown = i + 1; (iDown < iRow) && (bFlag == TRUE); iDown++)
                {
                    if (iArr[iDown][j] != 1)
                    {
                        bFlag = FALSE;
                        break;
                    }
                }

                if (bFlag == TRUE)
                {
                    printf("House Found at indes\t:%d and %d\n", i, j);
                    iCnt++;
                }
            }
            bFlag = TRUE;
        }
    }
    printf("\nTotal House found\t:%d\n\n", iCnt);
}
