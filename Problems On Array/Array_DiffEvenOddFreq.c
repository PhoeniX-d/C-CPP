/*
*   Program to accept N numbers and return diff between 
*   frequency of even numbers and odd numbers
*/
#include<stdio.h>
#include<stdlib.h>
#define ERROR       -1

int DiffEvenOddFreq(int[], int);

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

    iRet = DiffEvenOddFreq(iArr, iNo);
    if(iRet != ERROR)
        printf("Difference  %d ", iRet);

    free(iArr);
    return 0;
}
//////////////////////////////////////////////////////////////////////////////
//
//	Name		:DiffEvenOddFreq
//	Input		:int[], int
//	Returns		:int
//	Description	:return diff between frequency of even numbers and odd numbers
//	Author		:Pranav Choudhary
//	Date		:20 August 2020
//
//////////////////////////////////////////////////////////////////////////////
int DiffEvenOddFreq(int iArr[], int iLen)
{
    int i = 0, iECnt = 0, iOCnt = 0;
    if(NULL == iArr || iLen < 0)
    {
        printf("Invalid Inputs !!\n");
        return ERROR;
    }
    for (i = 0; i < iLen; i++)
    {
        if(iArr[i] % 2 == 0)
        {
            iECnt++;
        }
        else
        {
            iOCnt++;
        }        
    }
    return iECnt - iOCnt;
}