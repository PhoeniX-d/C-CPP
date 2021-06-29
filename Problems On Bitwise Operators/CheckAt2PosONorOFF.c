/*
*   Write a program which accept one number ,two positions from user and
*   check whether bit at first and bit at second position is ON or OFF.
*   Input : 10 3 7
*   Output : TRUE 
*/

#include<stdio.h>

#define TRUE    1
#define FALSE   0
#define ERROR  -1

typedef unsigned int UINT;
typedef char BOOL;

BOOL CheckONorOFF(UINT, int, int);

int main()
{
    UINT uNum = 0;
    int iBit1 = 1, iBit2 = 0;
    BOOL bRet = FALSE;

    printf("Enter the number:\n");
    scanf("%u", &uNum);

    printf("Enter 1st Bit position:\n");
    scanf("%d", &iBit1);

    printf("Enter 2nd Bit position:\n");
    scanf("%d", &iBit2);

    bRet = CheckONorOFF(uNum, iBit1, iBit2);
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
        printf("Invalid Input\n");
    }
    
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CheckONorOFF
//  Input       :UINT, int, int
//  Returns     :BOOL
//  Description :check whether bit at first or bit at second position
//               is ON or OFF
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////////////////////////
BOOL CheckONorOFF(UINT uNum, int iBit1, int iBit2)
{
    if(iBit1 < 1 || iBit1 > 32 || iBit2 < 1 || iBit2 > 32)
    {
        return ERROR;
    }

    UINT uMask1 = 1, uMask2 = 1, uRes1 = 0, uRes2 = 0;

    uMask1 = uMask1 << (iBit1 - 1);
    uMask2 = uMask2 << (iBit2 - 1);

    uRes1 = uMask1 & uNum;
    uRes2 = uMask2 & uNum;

    if(uRes1 == uMask1 || uRes2 == uMask2)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
    
}