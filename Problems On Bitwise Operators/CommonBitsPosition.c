/*
*   Write a program which accept two numbers from user and display position
*   of common ON bits from that two numbers.
*   Input : 10 15 (1010 1111)
*   Output : 2 4 
*/

#include<stdio.h>

typedef unsigned int UINT;

void CommonBits(UINT, UINT);

int main()
{
    UINT uNum1 = 0, uNum2 = 0;

    printf("Enter the first number:\n");
    scanf("%u", &uNum1);

    printf("Enter the second number;\n");
    scanf("%u", &uNum2);

    printf("Common Bits ON at Position:\n");
    CommonBits(uNum1, uNum2);

    return 0;
}

////////////////////////////////////////////////////////////////
//
//  Name        :CommonBits
//  Input       :UINT, UINT
//  Returns     :void
//  Description :Displays Common ON bits in both numbers
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
////////////////////////////////////////////////////////////////
void CommonBits(UINT uNum1, UINT uNum2)
{
    UINT uMask = 0x00000001;
    int iPos = 1;
    while(iPos <= 32)
    {
        /* brackets are important here */
        if(((uNum1 & uMask) != 0) && ((uNum2 & uMask) != 0))
        {
            printf("%d ", iPos);
        }
        uMask = uMask << 1;
        iPos++;
    }
}