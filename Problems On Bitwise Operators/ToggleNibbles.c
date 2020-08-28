<<<<<<< HEAD
/*
*   Write a program which accept one number from user and toggle contents
*   of first and last nibble of the number. Return modified number. (Nibble is a
*   group of four bits)  
*/
#include<stdio.h>
#define ERROR      -1

typedef unsigned int UINT;

UINT ToggleNibble(UINT);

int main()
{
    UINT uNum = 0, uRet = 0;

    printf("Enter the number:\n");
    scanf("%u", &uNum);

    uRet = ToggleNibble(uNum);
    if(uRet != -1)
    {
        printf("Output:\n%u\n", uRet);
    }
    else
    {
        printf("Invalid Bit Postion\n");
    }    
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :ONBit
//  Input       :UINT
//  Returns     :UINT
//  Description :ON the bit at given position
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////////////////////////
UINT ToggleNibble(UINT uNum)
{
    /* uMask = 1111 0000 0000 0000 0000 0000 0000 1111 */
    UINT uMask = 0xF000000F;

    return uNum ^ uMask;
}
=======
/*
*   Write a program which accept one number from user and toggle contents
*   of first and last nibble of the number. Return modified number. (Nibble is a
*   group of four bits)  
*/
#include<stdio.h>
#define ERROR      -1

typedef unsigned int UINT;

UINT ToggleNibble(UINT);

int main()
{
    UINT uNum = 0, uRet = 0;

    printf("Enter the number:\n");
    scanf("%u", &uNum);

    uRet = ToggleNibble(uNum);
    if(uRet != -1)
    {
        printf("Output:\n%u\n", uRet);
    }
    else
    {
        printf("Invalid Bit Postion\n");
    }    
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :ONBit
//  Input       :UINT
//  Returns     :UINT
//  Description :ON the bit at given position
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////////////////////////
UINT ToggleNibble(UINT uNum)
{
    /* uMask = 1111 0000 0000 0000 0000 0000 0000 1111 */
    UINT uMask = 0xF000000F;

    return uNum ^ uMask;
}
>>>>>>> f61d4d83763659717ccd253f1cc0c0278324f79a
