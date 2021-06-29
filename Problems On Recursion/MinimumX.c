/*
*   Write a program which accept n numbers from user and print Minimum
*   number from that numbers in recursive manner
*/
#include<stdio.h>
#include<stdlib.h>
#define MAXNO       1000

int MinimumX(int[], int);

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
    iRet = MinimumX(iArr, iNum);
    printf("Minimum of %d elements\t:%d\n", iNum, iRet);
    free(iArr);

    return 0;
}
///////////////////////////////////////////////////////////
//
//  Name        :MinimumX
//  Input       :int[], int
//  Returns     :int
//  Description :Prints Minimum of N elements
//  Author      :Pranav Choudhary
//  Date        :7 Sept 2020
//
////////////////////////////////////////////////////////////
int MinimumX(int iArr[], int iNo)
{
    static int iMin = 0, i = 0;   /* Initialized only once */
    if(i == 0)
        iMin = iArr[0];
    if(i < iNo)
    {
        if(iMin > iArr[i])
        {
            iMin = iArr[i];
        }
        i++;
        MinimumX(iArr, iNo);   /*  Recursive calls MinimumX() until i becomes iNo */
    }
    return iMin;
}