
/*
*   Write a program which accept one number and position from user and toggle
*   that bit. Return modified number.
*   Input : 10 3
*   Output : 14 
*/
#include<stdio.h>
#define ERROR      -1

typedef unsigned int UINT;

UINT ToggleBit(UINT, int);

int main()
{
    UINT uNum = 0, uRet = 0;
    int iBit = 0;

    printf("Enter the number:\n");
    scanf("%u", &uNum);

    printf("Enter the bit position:\n");
    scanf("%d", &iBit);

    uRet = ToggleBit(uNum, iBit);
    if(uRet != uNum)
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
//  Name        :ONBit
//  Input       :UINT, int
//  Returns     :UINT
//  Description :ON the bit at given position
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////////////////////////
UINT ToggleBit(UINT uNum, int iBit)
{
    UINT uMask = 1;
    if(iBit > 32 || iBit < 1)
    {
        return uNum;
    }

    /* uMask = 0000 0000 0000 0000 0000 0000 0000 0001 */
    uMask = uMask << (iBit - 1);
    /* 
    *   if iBit = 10
    *   uMask = uMask << (10 - 1);
    *   uMask = 0000 0000 0000 0000 0000 0010 0000 0000
    */
    
    return uNum ^ uMask;
}
