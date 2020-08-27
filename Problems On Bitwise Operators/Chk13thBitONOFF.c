/*
*   Program which checks whether 13th bit is On or OFF
*/
#include<stdio.h>

#define TRUE    1
#define FALSE   0

typedef char BOOL;
typedef unsigned int UINT;

BOOL Check13th(UINT uNum);

int main()
{
    UINT uNum = 0;
    BOOL bRet = 0;
    printf("Enter the number\n");
    scanf("%u", &uNum);
   
    bRet = Check13th(uNum);
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
//  Name        :Check13th
//  Input       :UINT
//  Returns     :BOOL
//  Description :checks whether 13th bit is On or OFF
//  Author      :Pranav Choudhary
//  Date        :27 Aug 2020
//
//////////////////////////////////////////////////////////////////////
BOOL Check13th(UINT uNum)
{
    UINT uRes = 0, uMask = 0;
    
    /* uMask = 0000 0000 0000 0000 0001 0000 0000 0000 */
    uMask = 0x00001000;
    
    /* & will tell that bit's status ON(0) or OFF(1) */
    uRes = uNum & uMask;

    if(uRes == uMask)
        return TRUE;
    else
        return FALSE;
}
