/*
*   Program to accept N numbers and return summation between odd and even
*   elements
*/
#include<stdio.h>
#include<stdlib.h>
#define ERROR       -1

int DiffEvenOdd(int[], int);

int main()
{
    int iNo = 0, *iArr = NULL, i = 0, iRet = 0;

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

    iRet = DiffEvenOdd(iArr, iNo);
    printf("Difference of summation of even and odd numbers = %d", iRet);

    return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:DiffEvenOdd
//	Input		:int[], int
//	Returns		:int
//	Description	:return summation between odd and even elements
//	Author		:Pranav Choudhary
//	Date		:20 August 2020
//
////////////////////////////////////////////////////////////////
int DiffEvenOdd(int iArr[], int iLen)
{
    int iEvenSum = 0, iOddSum = 0, i = 0;
    printf("Output :\n");
    for (i = 0; i < iLen; i++)
    {
        if(iArr[i] % 2 == 0)
        {
            iEvenSum = iEvenSum + iArr[i];
        }
        else
        {
            iOddSum = iOddSum + iArr[i];
        }
    }
    return iEvenSum - iOddSum;
}