/*
*   Write a program which accept n numbers from user and
*   return addition of that numbers in recursive manner.
*   Value of n is accepted from user
*/

#include<stdio.h>
#include<stdlib.h>
#define MAXNO       1000

int SumN(int[], int);

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
    iRet = SumN(iArr, iNum);
    printf("Summation of elements\t:%d\n", iRet);
    free(iArr);

    return 0;
}
///////////////////////////////////////////////////////////
//
//  Name        :SumN
//  Input       :int[], int
//  Returns     :int
//  Description :SumNs pattern on console using recursion
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
int SumN(int iArr[], int iNo)
{
    if(iArr == NULL)
    {
        return -1;
    }
    static int iSum = 0, i = 0;   /* Initialized only once */
    if(i < iNo)
    {
        iSum = iSum + iArr[i];
        i++;
        SumN(iArr, iNo);   /*  Recursive calls SumN() until i becomes iNo */
    }
    return iSum;
}