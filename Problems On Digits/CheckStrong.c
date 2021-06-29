/* Program to check strong number or not
*  Strong number is such a number whose summation
* of factorial of each digit is original number
*/

#include<stdio.h>
#define TRUE     1
#define FALSE    0
typedef int BOOL;

BOOL ChkStrong(int);

int main()
{
    int iNo = 0;
    BOOL bRet = FALSE;
    printf("Enter the number\n");
    scanf("%d", &iNo);
    bRet = ChkStrong(iNo);
    if(bRet == TRUE)
    {
        printf("%d is Strong Number",iNo);
    }
    else
    {
        printf("%d is not strong number", iNo);
    }    
    return 0;
}

///////////////////////////////////////////////////////////////
//
//  Name        :ChkStrong
//  Input       :int
//  Returns     :BOOL
//  Desription  :checks whether number is strong number or not
//  Author      :Pranav P. Choudhary
//  Date        :1 August 2020
//
///////////////////////////////////////////////////////////////
BOOL ChkStrong(
                    int iNo
               )
{
    int iFact = 1, iSum = 0, iTemp = iNo, iDigit = 0;
    iNo = (iNo < 0) ? -iNo : iNo;

    while(iTemp != 0)
    {
        iDigit = iTemp % 10;
        for (iFact = 1; iDigit >= 1; iDigit--)
        {
            iFact = iFact * iDigit;
        }
        iSum = iSum + iFact;
        iTemp = iTemp / 10;
    }
    return (iSum == iNo) ? TRUE : FALSE;
}