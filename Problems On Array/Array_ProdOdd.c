/*
*   Program to accept N numbers and calculates Product of all odd elements
*/

#include<stdio.h>
#include<stdlib.h>
#define ERROR       -1

int ProductOdd(int[], int);

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

    iRet = ProductOdd(iArr, iNo);
    if(iRet != -1)
        printf("Product of all odd elements in array = %d ", iRet);

    free(iArr);
    return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:ProductOdd
//	Input		:int[], int
//	Returns		:int
//	Description	:calculates Product of all odd elements
//	Author		:Pranav Choudhary
//	Date		:21 August 2020
//
////////////////////////////////////////////////////////////////
int ProductOdd(int iArr[], int iLen)
{
    int i = 0, iProd = 1;
    char cFlag = 0;
    if(NULL == iArr || iLen < 0)
    {
        printf("Invalid Inputs !!\n");
        return ERROR;
    }
    for (i = 0; i < iLen; i++)
    {
        if(iArr[i] % 2 != 0)
        {
            cFlag = 1;
            iProd = iProd * iArr[i];
        }
    }
    if(cFlag != 0)
        return iProd;
    else
        return 0;
}