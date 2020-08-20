/*
*   Program to accept N numbers and finds maximum of N numbers
*/

#include<stdio.h>
#include<stdlib.h>
#define ERROR       -1

int MaximumN(int[], int);

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
    iRet = MaximumN(iArr, iNo);
    if(iRet != -1)
        printf("Maximum is %d ", iRet);

    free(iArr);
    return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:MaximumN
//	Input		:int[], int
//	Returns		:int
//	Description	:finds maximum of N numbers
//	Author		:Pranav Choudhary
//	Date		:21 August 2020
//
////////////////////////////////////////////////////////////////
int MaximumN(int iArr[], int iLen)
{
    int i = 0, iMax = 0;
    if(NULL == iArr || iLen < 0)
    {
        printf("Invalid Inputs !!\n");
        return ERROR;
    }
    iMax = iArr[0];
    for (i = 0; i < iLen; i++)
    {
        if(iArr[i] > iMax)
        {
            iMax = iArr[i];
        }
    }
    return iMax;
}