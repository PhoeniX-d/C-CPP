/*
*   Write a program which accept number from user and print the reverse
*   number.
*   Input : 5428 Output : 8245
*/
#include<stdio.h>

long long ReverseX(long long int);

int main()
{
    long long int iNum = 0, iRet = 0;

    printf("\nEnter the number\t:");
    scanf("%lld", &iNum);
    if(iNum < 0)
    {
        iNum = -iNum;
    }
    iRet = ReverseX(iNum);
    printf("\nReverse of number\t:%lld\n", iRet);
    return 0;
}
////////////////////////////////////////////////////////////////
//
//  Name        :ReverseX
//  Input       :long long int
//  Returns     :void
//  Description :Reverse number using recursion
//  Author      :Pranav Choudhary
//  Date        :7 Sept 2020
//
/////////////////////////////////////////////////////////////////
long long ReverseX(long long int iNo)
{
    int iDigit = 0;
    static long long int iTemp = 0;
    if(iNo != 0)
    {
        iDigit = iNo % 10;
        iTemp = iTemp * 10 + iDigit;
        ReverseX(iNo / 10);      /*  Recursive calls ReverseX() until i becomes iNo */   
    }
    return iTemp;
}