/*
*   Write a program which accept one number from user and count number of
*   ON (1) bits in it without using % and / operator. with least time complexity
*   Input : 11
*   Output : 3 
*/

#include<stdio.h>

typedef unsigned int UINT;

int CountONBits(UINT);

int main()
{
    UINT uNum = 0;
    int iRet = 0;

    printf("Enter the number:\n");
    scanf("%u", &uNum);

    iRet = CountONBits(uNum);
    printf("Output:\n%d\n", iRet);

    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CountONBits
//  Input       :UINT
//  Returns     :int
//  Description :count one's in Binary representation of enterd number
//               without using % and / operator
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////////////////////////
int CountONBits(UINT uNum)
{
    UINT uMask = 1;
    int iCnt = 0;
    /* uMask = 0000 0000 0000 0000 0000 0000 0000 0001 */
    uMask = 0x00000001;
    while(uNum > 0)
    {
        if((uNum & uMask) != 0)
        {
            iCnt++;
        }
        uNum = uNum >> 1;
    }
    return iCnt;
}