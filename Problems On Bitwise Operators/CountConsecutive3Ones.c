/*
*   Program to count consecutive 3 ones
*/

#include<stdio.h>

typedef unsigned int UINT;

int CountConOnes(UINT);

int main()
{
    UINT uNum = 0;
    int iRet = 0;
    printf("Enter the number\n");
    scanf("%u", &uNum);

    iRet = CountConOnes(uNum);
    printf("Number of consecutive ones:\n%d\n", iRet);

    return 0;
}


//////////////////////////////////////////////////////////////
//
//  Name        :CountConOnes
//  Input       :UINT
//  Output      :void
//  Description :count consecutive 3 ones
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////////////////
int CountConOnes(UINT uNum)
{
    UINT uMask = 0x00000007, uRes = 0;
    int iPos = 1, iOnes = 0;
    while(iPos <= 32)
    {
        uRes = uNum & uMask;
        if(uRes == uMask)
        {
            iPos = iPos + 3;
            if(iPos >= 32)
            {
                break;
            }
            uMask = uMask << 3;
            iOnes++;
        }
        else
        {
            iPos = iPos + 1;
            if(iPos >= 32)
            {
                break;
            }
            uMask = uMask << 1;
        }
    }
    return iOnes;
}