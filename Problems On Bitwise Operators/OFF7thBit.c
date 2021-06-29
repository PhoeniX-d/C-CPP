/*
*   Write a program which accept one number from user and off 7th bit of that
*   number if it is on. Return modified number.
*   Input : 79
*   Output : 15 
*/
#include<stdio.h>

typedef unsigned int UINT;

UINT OFF7thBit(UINT uNum);

int main()
{
    UINT uNum = 0, uRet = 0;

    printf("Enter the number\n");
    scanf("%u", &uNum);
   
    uRet = OFF7thBit(uNum);
    printf("Output :\n%u", uRet);

    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//  Name        :OFF7thBit
//  Input       :UINT
//  Returns     :UINT
//  Description :off 7th bit of that number if it is on. 
//               Return modified number
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////////////////////////
UINT OFF7thBit(UINT uNum)
{
    UINT uMask = 0;

    /* uMask = 1111 1111 1111 1111 1111 1111 1011 1111 */
    uMask = 0xFFFFFFBF;
    
    return uNum & uMask;

}
