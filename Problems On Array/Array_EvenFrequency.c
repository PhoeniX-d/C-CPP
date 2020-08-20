/*
*   Program to accept N numbers and return frequency of even numbers
*   and even
*/
#include<stdio.h>
#include<stdlib.h>
#define ERROR       -1

int CountEvenFreq(int[], int);

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

    iRet = CountEvenFreq(iArr, iNo);
    printf("Even number of elements are %d ", iRet);
    return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:CountEvenFreq
//	Input		:int[], int
//	Returns		:int
//	Description	:return frequency of even numbers
//	Author		:Pranav Choudhary
//	Date		:20 August 2020
//
////////////////////////////////////////////////////////////////
int CountEvenFreq(int iArr[], int iLen)
{
    int i = 0, iCnt = 0;
    for (i = 0; i < iLen; i++)
    {
        if(iArr[i] % 2 == 0)
        {
            iCnt++;
        }
    }
    return iCnt;
}