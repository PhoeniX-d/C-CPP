/*
*   Write a recursive program which accept number from user and return its
*   factorial.
*   Input : 5
*   Output : 120 
*/
#include<stdio.h>

typedef unsigned int UINT;

UINT Factorial(int);

int main()
{
    int iNum = 0;
    UINT uRet = 0;
    printf("Enter the number\t:");
    scanf("%d", &iNum);
    uRet = Factorial(iNum);
    printf("Factorial of number is\t:%d\n", uRet);
    return 0;
}
/////////////////////////////////////////////////////////////////////////
//
//  Name        :Factorial
//  Input       :void
//  Returns     :UINT
//  Description :calculates Summation of digits of number using recursion
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
/////////////////////////////////////////////////////////////////////////
UINT Factorial(int iNo)
{
    static UINT iFact = 1;   /* Initialized only once */
    if(iNo != 0)
    {
        iFact = iFact * iNo;
        iNo--;
        Factorial(iNo);   /*  Recursive calls Factorial() until iNo becomes 0 */
    }
    return iFact;
}