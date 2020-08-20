/*
*   Program to accept N numbers and displays sum of each elements digits
*/

#include<stdio.h>
#include<stdlib.h>
#define ERROR       -1

void SumDigits(int[], int);

int main()
{
    int iNo = 0, *iArr = NULL, i = 0;

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

    printf("Output :\n");
    SumDigits(iArr, iNo);

    free(iArr);
    return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:SumDigits
//	Input		:int[], int
//	Returns		:void
//	Description	:displays sum of each elements digits
//	Author		:Pranav Choudhary
//	Date		:21 August 2020
//
////////////////////////////////////////////////////////////////
void SumDigits(int iArr[], int iLen)
{
    int i = 0, iTemp = 0, iSum = 0;
    if(NULL == iArr || iLen < 0)
    {
        printf("Invalid Inputs !!\n");
        return;
    }
    for (i = 0; i < iLen; i++)
    {
        iTemp = iArr[i];
        iSum = 0;
        while(iTemp != 0)
        {
            iSum = iSum + (iTemp % 10);
            iTemp = iTemp / 10;
        }
        printf("%d ", iSum);
    }
}