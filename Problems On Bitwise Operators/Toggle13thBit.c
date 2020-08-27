/*
*   Program which toggle 13th bit
*/
#include<stdio.h>

typedef unsigned int UINT;

UINT Toggle13thBit(UINT uNum);

int main()
{
    UINT uNum = 0, uRet = 0;
    printf("Enter the number\n");
    scanf("%u", &uNum);
   
    uRet = Toggle13thBit(uNum);
    printf("Output:\n%u\n", uRet);
    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//  Name        :Toggle13thBit
//  Input       :UINT
//  Returns     :BOOL
//  Description :toggles 13th bit
//  Author      :Pranav Choudhary
//  Date        :27 Aug 2020
//
//////////////////////////////////////////////////////////////////////
UINT Toggle13thBit(UINT uNum)
{
    UINT uMask = 0;
    
    /* uMask = 0000 0000 0000 0000 0001 0000 0000 0000 */
    uMask = 0x00001000;
    
    /* ^ will toggle that bit's status ON(0) or OFF(1) */
    return uNum ^ uMask;

}
