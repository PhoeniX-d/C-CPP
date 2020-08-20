/*
*   Program to accept N numbers and checks whether it contains N number or not
*/

#include<stdio.h>
#include<stdlib.h>
#define TRUE        1
#define FALSE       0
#define ERROR      -1
typedef char BOOL;

BOOL CheckHaveN(int[], int, int);

int main()
{
    int iNo = 0, iEl = 0, *iArr = NULL, i = 0;

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
    
    if(CheckHaveN(iArr, iNo, iEl) == TRUE)
        printf("It contains %d ", iEl);
    else
        printf("It does not contains %d ", iEl);

    free(iArr);
    return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:CheckHaveN
//	Input		:int[], int, int
//	Returns		:BOOL
//	Description	:checks whether it contains N number or not
//	Author		:Pranav Choudhary
//	Date		:20 August 2020
//
////////////////////////////////////////////////////////////////
BOOL CheckHaveN(int iArr[], int iLen, int iTem)
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
            break;
        }
    }
    if(i == iLen)
        return FALSE;
    else
        return TRUE;
}