/*
*   Program to change endianness of entered number
*   Input   : Decimal -> 43981 => Hexadecimal -> ABCD
*   Output  : Decimal -> 56506 => HExadecimal -> DCBA
*/
#include<stdio.h>

typedef unsigned int UINT;

UINT ChangeEndianness(UINT);

int main()
{
    UINT uNum = 0, uRet = 0;

    printf("Enter the number:\n");
    scanf("%u", &uNum);
    printf("Enterd  number:\n");
    printf("Decimal     :\t%u\n", uNum);
    printf("Hexadecimal :\t%X\n", uNum);

    uRet = ChangeEndianness(uNum);
    printf("Output:\n");
    printf("Decimal     :\t%u\n", uRet);
    printf("Hexadecimal :\t%X\n", uRet);

    return 0;
}

//////////////////////////////////////////////////////////////
//
//  Name        :ChangeEndianness
//  Input       :UINT
//  Output      :UINT
//  Description :Changes Endianness of a number
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////////////////
UINT ChangeEndianness(UINT uNum)
{
    UINT uMask = 0x000000FF, uByte1 = 0, uByte2 = 0, uByte3 = 0, uByte4 = 0;
    
    uByte1 = uNum & uMask;
    uByte1 = uByte1 << 24;

    uNum = uNum >> 8;
    uByte2 = uNum & uMask;
    uByte2 = uByte2 << 16;

    uNum = uNum >> 8;
    uByte3 = uNum & uMask;
    uByte3 = uByte3 << 8;

    uNum = uNum >> 8;
    uByte4 = uNum & uMask;

    uByte1 = uByte1 | uByte2 | uByte3 | uByte4;
    return uByte1;
}