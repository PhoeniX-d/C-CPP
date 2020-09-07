/*
*   Write a program which accepts number from user and check whether
*   number is Armstrong number or not in recursive manner
*/

#include<stdio.h>
#define TRUE        1
#define FALSE       0
typedef int BOOL;

BOOL IsArmstrong(long long int);

int main()
{
    long long int iNum = 0;
    BOOL bRet = 0;
    printf("Enter the number\t:");
    scanf("%lld", &iNum);
    bRet = IsArmstrong(iNum);
    if(bRet == TRUE)
        printf("Armstrong number\n");
    else
        printf("Not Armstrong number\n");
    return 0;
}
////////////////////////////////////////////////////////////////
//
//  Name        :IsArmstrong
//  Input       :long long int
//  Returns     :void
//  Description :Check number is Armstrong or not using recursion
//  Author      :Pranav Choudhary
//  Date        :7 Sept 2020
//
/////////////////////////////////////////////////////////////////
BOOL IsArmstrong(long long int iNo)
{
    static int iSum = 0;  /* Initialized only once */
    int iDigit = 0;
    static long long int iTemp = 0;
    if(iNo < 0)
    {
        iNo = -iNo;
    }
    if(iNo != 0)
    {
        iDigit = iNo % 10;
        iSum = iSum + (iDigit * iDigit * iDigit);
        IsArmstrong(iNo / 10);      /*  Recursive calls IsArmstrong() until i becomes iNo */
        iTemp = iTemp * 10 + iDigit;
    }
    if(iSum == iTemp)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }    
}