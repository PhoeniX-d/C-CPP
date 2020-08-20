/*
*   Program to accept N numbers and displays numbers which contains 3 in it
*/

#include<stdio.h>
#include<stdlib.h>
#define ERROR       -1

void Contains3(int[], int);

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

    printf("Output :\n");
    Contains3(iArr, iNo);

    free(iArr);
    return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:Contains3
//	Input		:int[], int
//	Returns		:void
//	Description	:displays numbers which contains 3 in it
//	Author		:Pranav Choudhary
//	Date		:21 August 2020
//
////////////////////////////////////////////////////////////////
void Contains3(int iArr[], int iLen)
{
    int i = 0, iTemp = 0;
    if(NULL == iArr || iLen < 0)
    {
        printf("Invalid Inputs !!\n");
        return;
    }
    for (i = 0; i < iLen; i++)
    {
        iTemp = iArr[i];
        while(iTemp != 0)
        {
            if(iTemp % 10 == 3)
            {
                printf("%d ", iArr[i]);
            }
            iTemp = iTemp / 10;
        }
    }
}