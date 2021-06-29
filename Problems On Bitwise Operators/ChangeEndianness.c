/*
*   Program to change endianness of entered number
*   Input   : Decimal -> 4210818301 => Hexadecimal -> FAFBFCFD
*   Output  : Decimal -> 4261215226 => HExadecimal -> FDFCFBFA
*/
#include<stdio.h>

#define BITS    sizeof(int) * 8
#define BYTE    8

typedef unsigned int UINT;

UINT ChangeEndianness(UINT);

int main()
{
    UINT uNum = 0, uRet = 0;

    printf("Enter the number:\n");
    scanf("%u", &uNum);
    printf("\nEnterd  number:\n\n");
    printf("Decimal     :\t%u\n", uNum);
    printf("Hexadecimal :\t%#X\n", uNum);

    uRet = ChangeEndianness(uNum);
    printf("\nOutput:\n\n");
    printf("Decimal     :\t%u\n", uRet);
    printf("Hexadecimal :\t%#X\n", uRet);

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
    UINT uMask = 0x000000FF, uByte = 0, uRes = 0;
    
    for (int i = 1; i <= sizeof(int); i++)
    {
        uByte = uNum & uMask;
        uByte = uByte << (BITS - i * 8);
        uRes = uRes | uByte;
        uNum = uNum >> BYTE;
    }
    return uRes;
}