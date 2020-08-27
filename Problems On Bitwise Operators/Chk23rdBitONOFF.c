/*
*   Program which checks whether 23rd bit is On or OFF
*/
#include<stdio.h>

#define TRUE    1
#define FALSE   0

typedef char BOOL;
typedef unsigned int UINT;

BOOL Check23rd(UINT uNum);

int main()
{
    UINT uNum = 0;
    BOOL bRet = 0;
    printf("Enter the number\n");
    scanf("%u", &uNum);
   
    bRet = Check23rd(uNum);
    if(bRet == TRUE)
    {
        printf("TRUE\n");
    }
    else
    {
        printf("FALSE\n");
    }    
    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//  Name        :Check23rd
//  Input       :UINT
//  Returns     :BOOL
//  Description :checks whether 23rd bit is On or OFF
//  Author      :Pranav Choudhary
//  Date        :27 Aug 2020
//
//////////////////////////////////////////////////////////////////////
BOOL Check23rd(UINT uNum)
{
    UINT uRes = 0, uMask = 0;
    
    /* uMask = 0000 0000 0100 0000 0001 0000 0000 0000 */
    uMask = 0x00400000;
    
    /* & will tell that bit's status ON(0) or OFF(1) */
    uRes = uNum & uMask;

    if(uRes == uMask)
        return TRUE;
    else
        return FALSE;
}
