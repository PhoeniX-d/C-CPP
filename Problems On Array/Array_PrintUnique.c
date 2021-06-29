/*
*    Write a program in C to print all unique elements in an array
*/
#include<stdio.h>
#include<stdlib.h>
#define ERROR       -1

void DisplayUnique(int[], int);

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
    DisplayUnique(iArr, iNo);

    free(iArr);
    return 0;
}
////////////////////////////////////////////////////////////////////////
//
//  Name        :DisplayUnique
//  Input       :int[], int
//  Returns     :void
//  Description :print all unique elements in an array
//  Author      :Pranav Choudhary
//  Date        :21 August 2020
//
/////////////////////////////////////////////////////////////////////////
void DisplayUnique(int iArr[], int iLen)
{
    int i = 0, j = 0;
    char cFlags = 0;
    if(NULL == iArr || iLen <= 0)
    {
        printf("Invalid Inputs\n");
        return;
    }
    
    for (i = 0; i < iLen; i++)
    {
        cFlags = 0;
        for (j = 0; j < iLen; j++)
        {
            if(iArr[i] == iArr[j] && i != j)
            {
                cFlags++;
            }
        }
        if(cFlags == 0)
        {
            printf("%d ", iArr[i]);
        }
    }

}
