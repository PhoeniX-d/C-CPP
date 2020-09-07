/*
*   Write a recursive program which accept number from user and return
*   largest digit
*   Input : 87983
*   Output : 9
*/

#include<stdio.h>

int MinDigit(long long int);

int main()
{
    long long int iNum = 0;
    int iRet = 0;
    printf("Enter the number:\n");
    scanf("%lld", &iNum);
    iRet = MinDigit(iNum);    
    printf("Smallest digit in %lld\t:%d\n", iNum, iRet);
    return 0;
}
///////////////////////////////////////////////////////////////////
//
//  Name        :MinDigit
//  Input       :long long int
//  Returns     :int
//  Description :computes smallest digit of number using recursion
//  Author      :Pranav Choudhary
//  Date        :7 Sept 2020
//
///////////////////////////////////////////////////////////////////
int MinDigit(long long int iNo)
{
    static int iMin = 9;   /* Initialized only once */
    if(iNo < 0)
    {
        iNo = -iNo;
    }
    if(iNo != 0)
    {
        if(iMin > (iNo % 10))
        {
            iMin = iNo % 10;
        }
        iNo = iNo / 10;
        MinDigit(iNo);   /*  Recursive calls MinDigit() until i becomes iNo */
    }
    return iMin;
}