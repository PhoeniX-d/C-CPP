/*
*   Write a program which accept one number from user and range of
*   positions from user. Toggle all bits from that range.
*   Input : 897 9 13
*   Toggle all bits from position 9 to 13 of input number ie 879
*/
#include<stdio.h>

#define ERROR  -1
#define BITS    sizeof(int) * 8

typedef unsigned int UINT;

UINT ToggleRange(UINT, int, int);

int main()
{
    UINT uNum = 0, uRet = 0;
    int iStart = 0, iEnd = 0;

    printf("Enter the number:\n");
    scanf("%u", &uNum);

    printf("Enter start position:\n");
    scanf("%d", &iStart);

    printf("Enter end position:\n");
    scanf("%d", &iEnd);

    uRet = ToggleRange(uNum, iStart, iEnd);
    if(uRet != ERROR)
    {
        printf("Output:\n%u\n", uRet);
    }
    else
    {
        printf("Invalid Range\n");
    }    

    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :ToggleRange
//  Input       :UINT, int, int
//  Returns     :UINT
//  Description :Toggle all bits from that range
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////////////////////////
UINT ToggleRange(UINT uNum, int iStart, int iEnd)
{
    if(iStart < 1 || iStart > 32 || iEnd < 1 || iEnd > 32 || iEnd < iStart)
    {
        return ERROR;
    }
    /* way 1 */
    UINT uMask1 = 0xFFFFFFFF, uMask2 = 0xFFFFFFFF;

    uMask1 = uMask1 << (iStart - 1);
    uMask2 = uMask2 >> (BITS - iEnd);
    uMask1 = uMask1 & uMask2;
    
    return uMask1 ^ uNum;
    /* way 2
    UINT uMask = 0;
    // uMask1 = 1111 1111 1111 1111 1111 1111 1111 1111
    uMask = 0xFFFFFFFF;

    uMask = uMask << ((iStart - 1) + (BITS - iEnd));
    uMask = uMask >> (BITS - iEnd);
    
    return uNum ^ uMask;
    */
}