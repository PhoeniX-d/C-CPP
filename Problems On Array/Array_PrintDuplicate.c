/*
*    Write a program in C to print all Duplicate elements in an array
*/
#include<stdio.h>
#include<stdlib.h>
#define ERROR       -1

void DisplayDuplicate(int[], int);

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

    printf("Output:\n");
    DisplayDuplicate(iArr, iNo);

    free(iArr);
    return 0;
}
////////////////////////////////////////////////////////////////////////
//
//  Name        :DisplayDuplicate
//  Input       :int[], int
//  Returns     :void
//  Description :print all Duplicate elements in an array
//  Author      :Pranav Choudhary
//  Date        :21 August 2020
//
/////////////////////////////////////////////////////////////////////////
void DisplayDuplicate(int iArr[], int iLen)
{
    int i = 0, j = 0, *iTemp = NULL;
    int Count = 0, cFlag = 0;
    if(NULL == iArr || iLen <= 0)
    {
        printf("Invalid Inputs\n");
        return;
    }
    iTemp = (int *)malloc(sizeof(int) * iLen);
    if(iTemp == NULL)
    {
        printf("Memory allocation failed!!\n");
        return;
    }
    for (i = 0; i < iLen; i++)
    {
        iTemp[i] = 0;
    }
    for (i = 0; i < iLen; i++)
    {
        Count = 0;
        for (j = 0; j < iLen; j++)
        {
            if (iArr[i] == iArr[j] && i != j)
            {
                Count++;
            }
        }
        if (Count >= 1)
        {
            for (j = 0; j < iLen; j++)
            {
                if (iTemp[j] == iArr[i])
                {
                    break;
                }
            }
            if (j == iLen)
            {
                printf("%d ", iArr[i]);
                iTemp[i] = iArr[i];
            }
        }
    }
    free(iTemp);
}
