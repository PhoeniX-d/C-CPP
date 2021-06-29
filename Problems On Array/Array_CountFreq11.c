/*
*   Program to accept N numbers and counts frequency of 11 in it
*/

#include<stdio.h>
#include<stdlib.h>
#define ERROR       -1

int Count11(int[], int);

int main()
{
    int iNo = 0, *iArr = NULL, i = 0;
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

    iRet = Count11(iArr, iNo);
    if(iRet != ERROR)
        printf("Number of 11s in array = %d ", iRet);
    else
        printf("Cannot find element\n");
    free(iArr);
    return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:Count11
//	Input		:int[], int
//	Returns		:int
//	Description	:counts frequency of 11 in array
//	Author		:Pranav Choudhary
//	Date		:20 August 2020
//
////////////////////////////////////////////////////////////////
int Count11(int iArr[], int iLen)
{
    int i = 0, iCnt = 0;
    if(NULL == iArr || iLen < 0)
    {
        printf("Invalid Inputs !!\n");
        return ERROR;
    }
    for (i = 0; i < iLen; i++)
    {
        if(iArr[i] % 11 == 0)
        {
            iCnt++;
        }
    }
    return iCnt;
}