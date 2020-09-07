/*
*   Write a recursive program which accept number from user and return
*   summation of its digits.
*   Input : 879
*   Output : 24
*/
#include<stdio.h>

int ProdDigit(long long int);

int main()
{
    long long int iNum = 0;
    int iRet = 0;
    printf("Enter the number\t:");
    scanf("%lld", &iNum);
    iRet = ProdDigit(iNum);
    printf("Product of digits is\t:%d\n", iRet);
    return 0;
}
/////////////////////////////////////////////////////////////////////////
//
//  Name        :ProdDigit
//  Input       :long long int
//  Returns     :int
//  Description :calculates product of digits of number using recursion
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
/////////////////////////////////////////////////////////////////////////
int ProdDigit(long long int iNo)
{
    static int iProd = 0;   /* Initialized only once */
    int iDigit = 0;
    if(iNo != 0)
    {
        iDigit = iNo % 10;
        if(iProd == 0)
        {
            iProd = 1;
        }
        if(iDigit == 0)
        {
            iDigit = 1;
        }
        iProd = iProd * iDigit;
        ProdDigit(iNo / 10);   /*  Recursive calls ProdDigit() until iNo becomes 0 */
    }
    return iProd;
}