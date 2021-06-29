/*
*   Program to accept N numbers and display numbers divisible by 11
*/
#include<stdio.h>
#include<stdlib.h>
#define ERROR       -1

void DivisibleBy11(int[], int);

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

    DivisibleBy11(iArr, iNo);

    free(iArr);
    return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:DivisibleBy11
//	Input		:int[], int
//	Returns		:void
//	Description	:display numbers divisible by 11
//	Author		:Pranav Choudhary
//	Date		:20 August 2020
//
////////////////////////////////////////////////////////////////
void DivisibleBy11(int iArr[], int iLen)
{
    int i = 0;
    if(NULL == iArr || iLen < 0)
    {
        printf("Invalid Inputs !!\n");
        return;
    }
    printf("Output :\n");
    for (i = 0; i < iLen; i++)
    {
        if(iArr[i] % 11 == 0)
        {
            printf("%d ", iArr[i]);
        }
    }
}