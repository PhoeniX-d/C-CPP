/*
*   Program to accept N numbers and check whether array contains 11 in it or not
*/

#include<stdio.h>
#include<stdlib.h>
#define TRUE        1
#define FALSE       0
#define ERROR       -1
typedef char BOOL;

BOOL Check11(int[], int);

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

    if(Check11(iArr, iNo) == TRUE)
    {
        printf("It contains 11 in it");
    }
    else
    {
        printf("It doesnt contains 11 in it");
    }    
    return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:Check11
//	Input		:int[], int
//	Returns		:void
//	Description	:check whether array contains 11 in it or not
//	Author		:Pranav Choudhary
//	Date		:20 August 2020
//
////////////////////////////////////////////////////////////////
BOOL Check11(int iArr[], int iLen)
{
    int i = 0;
    if(NULL == iArr || iLen < 0)
    {
        printf("Invalid Inputs !!\n");
        return ERROR;
    }
    for (i = 0; i < iLen; i++)
    {
        if(iArr[i] % 11 == 0)
        {
            break;
        }
    }
    if(i == iLen)
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}