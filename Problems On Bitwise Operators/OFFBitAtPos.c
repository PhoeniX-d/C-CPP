/*
*   Write a program which accept one number and position from user and off
*   that bit. Return modified number.
*   Input : 10 2
*   Output : 8 
*/
#include<stdio.h>
#define ERROR      -1

typedef unsigned int UINT;

UINT OFFBit(UINT, int);

int main()
{
    UINT uNum = 0, uRet = 0;
    int iBit = 0;
    
    printf("Enter the number:\n");
    scanf("%u", &uNum);

    printf("Enter the bit position:\n");
    scanf("%d", &iBit);

    uRet = OFFBit(uNum, iBit);
    if(uRet != -1)
    {
        printf("Output:\n%u\n", uRet);
    }
    else
    {
        printf("Invalid Bit Postion\n");
    }    
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :OFFBit
//  Input       :UINT, int
//  Returns     :UINT
//  Description :OFF the bit at given position
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////////////////////////
UINT OFFBit(UINT uNum, int iBit)
{
    UINT uMask = 0xFFFFFFFE;
    if(iBit > 32 || iBit < 1)
    {
        return -1;
    }

    /* uMask = 1111 1111 1111 1111 1111 1111 1111 1110 */
    uMask = uMask << (iBit - 1);
    /* 
    *   if iBit = 10
    *   uMask = uMask << (10 - 1);
    *   uMask = 1111 1111 1111 1111 1111 1101 1111 1111 
    */
    
    return uNum & uMask;
}
