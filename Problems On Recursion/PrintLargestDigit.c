/*
*   Write a recursive program which accept number from user and return
*   largest digit
*   Input : 87983
*   Output : 9
*/

#include<stdio.h>

int MaxDigit(long long int);

int main()
{
    long long int iNum = 0;
    int iRet = 0;
    printf("Enter the number:\n");
    scanf("%lld", &iNum);
    iRet = MaxDigit(iNum);    
    printf("Largest digit in %lld\t:%d\n", iNum, iRet);
    return 0;
}
//////////////////////////////////////////////////////////////
//
//  Name        :MaxDigit
//  Input       :long long int
//  Returns     :int
//  Description :computes largest digit of number using recursion
//  Author      :Pranav Choudhary
//  Date        :7 Sept 2020
//
///////////////////////////////////////////////////////////////
int MaxDigit(long long int iNo)
{
    static int iMax = 0;   /* Initialized only once */
    if(iNo < 0)
    {
        iNo = -iNo;
    }
    if(iNo != 0)
    {
        if(iMax < (iNo % 10))
        {
            iMax = iNo % 10;
        }
        iNo = iNo / 10;
        MaxDigit(iNo);   /*  Recursive calls MaxDigit() until i becomes iNo */
    }
    return iMax;
}