/*
*   Program to accept N numbers and displays numbers in given range
*/

#include<stdio.h>
#include<stdlib.h>
#define ERROR       -1

void PrintInRange(int[], int, int, int);

int main()
{
    int iNo = 0, iStart = 0, iEnd = 0, *iArr = NULL, i = 0;
    printf("Enter the number of elements\n");
    scanf("%d", &iNo);

    if(iNo < 0)
    {
        iNo = -iNo;
    }

    if((iArr = (int *)malloc(iNo * sizeof(int))) == NULL)
    {
        printf("Memory Allocation failed!!\n");
        return ERROR;
    }  

    printf("Enter the %d elements\n", iNo);
    for(i = 0; i < iNo; i++)
    {
        scanf("%d", &iArr[i]);
    }

    printf("Enter start and end of range \n");
    scanf("%d %d", &iStart ,&iEnd);
    
    PrintInRange(iArr, iNo, iStart, iEnd);

    free(iArr);
    return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:PrintInRange
//	Input		:int[], int, int, int
//	Returns		:void
//	Description	:displays numbers in given range
//	Author		:Pranav Choudhary
//	Date		:21 August 2020
//
////////////////////////////////////////////////////////////////
void PrintInRange(int iArr[], int iLen, int iStart, int iEnd)
{
    int i = 0, iPos = 0;
    if(NULL == iArr || iLen < 0 || iStart >= iEnd)
    {
        printf("Invalid Inputs !!\n");
        return;
    }
    printf("Output :\n");
    for (i = iLen - 1; i >= 0; i--)
    {
        if(iArr[i] >= iStart && iArr[i] <= iEnd)
        {
            printf("%d ", iArr[i]);
        }
    }
}