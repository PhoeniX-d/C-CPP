/*
*   Write a recursive program which accept number from user and return
*   summation of its digits.
*   Input : 879
*   Output : 24
*/
#include<stdio.h>

int ProdDigit(int);

int main()
{
    int iNum = 0, iRet = 0;
    printf("Enter the number\t:");
    scanf("%d", &iNum);
    iRet = ProdDigit(iNum);
    printf("Product of digits is\t:%d\n", iRet);
    return 0;
}
/////////////////////////////////////////////////////////////////////////
//
//  Name        :ProdDigit
//  Input       :void
//  Returns     :int
//  Description :calculates product of digits of number using recursion
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
/////////////////////////////////////////////////////////////////////////
int ProdDigit(int iNo)
{
    static int iProd = 0;   /* Initialized only once */
    if(iNo != 0)
    {
        if(iProd == 0)
        {
            iProd = 1;
        }
        iProd = iProd * (iNo % 10);
        iNo = iNo / 10;
        ProdDigit(iNo);   /*  Recursive calls ProdDigit() until iNo becomes 0 */
    }
    return iProd;
}