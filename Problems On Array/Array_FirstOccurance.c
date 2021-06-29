/*
*   Program to accept N numbers and finds first occurance of N number
*/

#include<stdio.h>
#include<stdlib.h>
#define ERROR       -1

int FirstOccurance(int[], int, int);

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
    
    iRet = FirstOccurance(iArr, iNo, iEl);
    if(iRet != -1)
        printf("First Occurance of %d in array is at %d ", iEl, iRet + 1);
    else
        printf("Array does not contain %d\n", iEl);

    free(iArr);
    return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:FirstOccurance
//	Input		:int[], int, int
//	Returns		:int
//	Description	:finds first occurance of N number
//	Author		:Pranav Choudhary
//	Date		:21 August 2020
//
////////////////////////////////////////////////////////////////
int FirstOccurance(int iArr[], int iLen, int iTem)
{
    int i = 0, iPos = 0;
    if(NULL == iArr || iLen < 0)
    {
        printf("Invalid Inputs !!\n");
        return ERROR;
    }
    for (i = 0; i < iLen; i++)
    {
        if(iArr[i] == iTem)
        {
            iPos = i;
            break;
        }
    }
    if(i == iLen)
        return -1;
    else
        return iPos;
}