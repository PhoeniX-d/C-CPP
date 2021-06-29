/*
*   Program to accept N numbers and finds Difference between Min and Max of N numbers
*/

#include<stdio.h>
#include<stdlib.h>
#define ERROR       -1

int DiffMinMaxN(int[], int);

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
    iRet = DiffMinMaxN(iArr, iNo);
    if(iRet != -1)
        printf("Difference between Min and Max is %d ", iRet);

    free(iArr);
    return 0;
}
///////////////////////////////////////////////////////////////////
//
//	Name		:DiffMinMaxN
//	Input		:int[], int
//	Returns		:int
//	Description	:finds Difference between Min and Max of N numbers
//	Author		:Pranav Choudhary
//	Date		:21 August 2020
//
///////////////////////////////////////////////////////////////////
int DiffMinMaxN(int iArr[], int iLen)
{
    int i = 0, iMin = 0, iMax = 0;
    if(NULL == iArr || iLen < 0)
    {
        printf("Invalid Inputs !!\n");
        return ERROR;
    }
    iMin = iArr[0];
    iMax = iArr[0];
    for (i = 0; i < iLen; i++)
    {
        if(iArr[i] < iMin)
        {
            iMin = iArr[i];
        }
        else if(iArr[i] > iMax)
        {
            iMax = iArr[i];
        }
    }
    return iMax - iMin;
}