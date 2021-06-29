/*
*   Program to accept N numbers and counts frequency of N number in array
*/

#include<stdio.h>
#include<stdlib.h>
#define ERROR       -1

int CountFreqN(int[], int, int);

int main()
{
    int iNo = 0, iEl = 0, *iArr = NULL, i = 0;
    int iRet = 0;

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

    printf("Enter element\n");
    scanf("%d", &iEl);
    
    iRet = CountFreqN(iArr, iNo, iEl);
    if(iRet != ERROR)
        printf("Frequency of %d in array = %d ", iEl, iRet);
    else
        printf("Cannot find element\n");
    free(iArr);
    return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:CountFreqN
//	Input		:int[], int, int
//	Returns		:int
//	Description	:counts frequency of N number in array
//	Author		:Pranav Choudhary
//	Date		:20 August 2020
//
////////////////////////////////////////////////////////////////
int CountFreqN(int iArr[], int iLen, int iTem)
{
    int i = 0, iCnt = 0;
    if(NULL == iArr || iLen < 0)
    {
        printf("Invalid Inputs !!\n");
        return ERROR;
    }
    for (i = 0; i < iLen; i++)
    {
        if(iArr[i] == iTem)
        {
            iCnt++;
        }
    }
    return iCnt;
}