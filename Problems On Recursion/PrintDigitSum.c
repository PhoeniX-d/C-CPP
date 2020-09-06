/*
*   Write a recursive program which accept number from user and return
*   summation of its digits.
*   Input : 879
*   Output : 24
*/
#include<stdio.h>

int SumDigit(int);

int main()
{
    int iNum = 0, iRet = 0;
    printf("Enter the number\t:");
    scanf("%d", &iNum);
    iRet = SumDigit(iNum);
    printf("Sum of digits is\t:%d\n", iRet);
    return 0;
}
/////////////////////////////////////////////////////////////////////////
//
//  Name        :SumDigit
//  Input       :void
//  Returns     :int
//  Description :calculates Summation of digits of number using recursion
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
/////////////////////////////////////////////////////////////////////////
int SumDigit(int iNo)
{
    static int iSum = 0;   /* Initialized only once */
    if(iNo != 0)
    {
        iSum = iSum + iNo % 10;
        iNo = iNo / 10;
        SumDigit(iNo);   /*  Recursive calls SumDigit() until iNo becomes 0 */
    }
    return iSum;
}