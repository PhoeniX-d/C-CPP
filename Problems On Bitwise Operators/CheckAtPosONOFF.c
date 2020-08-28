
/*
*   Write a program which accept one number and position from user and
*   check whether bit at that position is on or off. If bit is one return TURE
*   otherwise return FALSE.
*   Input : 10 2
*   Output : TRUE 
*/
#include<stdio.h>
#define TRUE        1
#define FALSE       0
#define ERROR      -1

typedef char BOOL;
typedef unsigned int UINT;

BOOL CheckBit(UINT, int);

int main()
{
    UINT uNum = 0;
    BOOL bRet = FALSE;
    int iBit = 0;

    printf("Enter the number:\n");
    scanf("%u", &uNum);

    printf("Enter the bit position:\n");
    scanf("%d", &iBit);

    bRet = CheckBit(uNum, iBit);
    if(bRet == TRUE)
    {
        printf("TRUE\n");
    }
    else if(bRet == FALSE)
    {
        printf("FALSE\n");
    }
    else
    {
        printf("Invalid Bit Postion\n");
    }    
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CheckBit
//  Input       :UINT, int
//  Returns     :BOOL
//  Description :checks bit at given position is ON or OFF
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////////////////////////
BOOL CheckBit(UINT uNum, int iBit)
{
    UINT uRes = 0, uMask = 1;
    if(iBit > 32 || iBit < 1)
    {
        return -1;
    }

    /* uMask = 0000 0000 0000 0000 0000 0000 0000 0001 */
    uMask = uMask << (iBit - 1);
    /* 
    *   if iBit = 10
    *   uMask = uMask << (10 - 1);
    *   uMask = 0000 0000 0000 0000 0000 0010 0000 0000 
    */
    uRes = uNum & uMask;

    if(uRes != 0)
        return TRUE;
    else
        return FALSE;
}