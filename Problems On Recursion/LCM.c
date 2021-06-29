/*
*   Program to find LCM of two numbers using Recursion method
*/
#include<stdio.h>

int FindLCM(int, int, int);

int main()
{
    int iNo1 = 0, iNo2 = 0, iRet = 0, iMax = 0;

    printf("Enter first number\t:");
    scanf("%d", &iNo1);

    printf("Enter second number\t:");
    scanf("%d", &iNo2);

    iNo1 = (iNo1 > 0) ? iNo1 : -iNo1;
    iNo2 = (iNo2 > 0) ? iNo2 : -iNo2;
    iMax = (iNo1 > iNo2) ? iNo1 : iNo2;

    iRet = FindLCM(iNo1, iNo2, iMax);

    printf("LCM of two number is\t:%d", iRet);

    return 0;
}

///////////////////////////////////////////////////////////
//
//  Name        :FindLCM
//  Input       :int int, int
//  Returns     :int
//  Description :Returns LCm of two numbers
//  Author      :Pranav Choudhary
//  Date        :21 Sept 2020
//
////////////////////////////////////////////////////////////
int FindLCM(int iNum1, int iNum2, int iMax)
{
    if((iMax % iNum1) == 0 && (iMax % iNum2) == 0)
    {
        return iMax;
    }
    else
    {
        iMax++;
        FindLCM(iNum1, iNum2, iMax);
    }    
}
