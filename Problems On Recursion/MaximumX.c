/*
*   Write a program which accept n numbers from user and print maximum
*   number from that numbers in recursive manner
*/
#include<stdio.h>
#include<stdlib.h>
#define MAXNO       1000

int MaximumX(int[], int);

int main()
{
    int iNum = 0, *iArr = NULL, iRet = 0;
    printf("Enter the number of elements\t:");
    scanf("%d", &iNum);
    if(iNum > MAXNO)
    {
        printf("Please Enter numbers upto 1000[in case its recursion]\n");
        return -1;
    }
    if(iNum < 0)
        iNum = -iNum;
    iArr = (int *)malloc(sizeof(int) * iNum);
    printf("Enter the elements:\n");
    for (int i = 0; i < iNum; i++)
    {
        scanf("%d", &iArr[i]);
    }
    iRet = MaximumX(iArr, iNum);
    printf("Maximum of %d elements\t:%d\n", iNum, iRet);
    free(iArr);

    return 0;
}

///////////////////////////////////////////////////////////
//
//  Name        :MaximumX
//  Input       :int[], int
//  Returns     :int
//  Description :Prints maximum of N elements
//  Author      :Pranav Choudhary
//  Date        :7 Sept 2020
//
////////////////////////////////////////////////////////////
int MaximumX(int iArr[], int iNo)
{
    static int iMax = 0, i = 0;   /* Initialized only once */
    if(i == 0)
    {
        iMax = iArr[0];
    }
    if(i < iNo)
    {
        if(iMax < iArr[i])
        {
            iMax = iArr[i];
        }
        i++;
        MaximumX(iArr, iNo);   /*  Recursive calls MaximumX() until i becomes iNo */
    }
    return iMax;
}