/*
*   Program to find GCD of two numbers using Recursion method
*/
#include<stdio.h>

int FindGCD(int, int);

int main()
{
    int iNo1 = 0, iNo2 = 0, iRet = 0;

    printf("Enter first number\t:");
    scanf("%d", &iNo1);

    printf("Enter second number\t:");
    scanf("%d", &iNo2);

    iNo1 = (iNo1 > 0) ? iNo1 : -iNo1;
    iNo2 = (iNo2 > 0) ? iNo2 : -iNo2;

    iRet = FindGCD(iNo1, iNo2);

    printf("GCD of two number is\t:%d", iRet);

    return 0;
}

///////////////////////////////////////////////////////////
//
//  Name        :FindGCD
//  Input       :int int
//  Returns     :int
//  Description :Returns GCD of two numbers
//  Author      :Pranav Choudhary
//  Date        :21 Sept 2020
//
////////////////////////////////////////////////////////////
int FindGCD(int iNum1, int iNum2)
{
    static int i = 1, iGCD = 1;
    if(i <= iNum1 && i <= iNum2)
    {
        if((iNum1 % i) == 0 && (iNum2 % i) == 0)
        {
            iGCD = i;
        }
        i++;
        FindGCD(iNum1, iNum2);
    }
    return iGCD;
}
