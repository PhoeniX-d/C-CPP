/*
*   Write a program which accept one number from user and on its first 4
*   bits. Return modified number.
*   Input : 73
*   Output : 79 
*/
#include<stdio.h>

typedef unsigned int UINT;

UINT ON4thBit(UINT uNum);

int main()
{
    UINT uNum = 0, uRet = 0;

    printf("Enter the number\n");
    scanf("%u", &uNum);
   
    uRet = ON4thBit(uNum);
    printf("Output :\n%u", uRet);

    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//  Name        :ON4thBit
//  Input       :UINT
//  Returns     :UINT
//  Description :on its first 4 bits. Return modified number.
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////////////////////////
UINT ON4thBit(UINT uNum)
{
    UINT uMask = 0;

    /* uMask = 0000 0000 0000 0000 0000 0000 0000 1111 */
    uMask = 0x0000000F;
    
    return uNum | uMask;

}
