/*
*   Program which checks Bits On Or OFF
*/
#include<stdio.h>

#define true    1
#define false   0

typedef unsigned int UINT;

class Bits
{
    public:

        bool CheckONOFF1(UINT); /* Pos of Bits 9, 10, 11, 25 */
        bool CheckONOFF2(UINT); /* Pos of Bits 5, 18 */
        bool CheckONOFF3(UINT); /* Pos of Bits 7, 15, 21, 28 */
        bool CheckONOFF4(UINT); /* Pos of Bits 7, 8, 9 */
        bool CheckONOFF5(UINT); /* Pos of Bits 1 ,32 */
        bool CheckONOFF6(UINT); /* Pos of Bits 4 */
        bool CheckONOFF7(UINT); /* Pos of Bits 13 */
        bool CheckONOFF8(UINT); /* Pos of Bits 23 */
};

//////////////////////////////////////////////////////////////////////
//
//  Name        :CheckONOFF
//  Input       :UINT
//  Returns     :bool
//  Description :checks whether 9th, 10th, 11th, 25th bit is On or OFF
//  Author      :Pranav Choudhary
//  Date        :27 Aug 2020
//
//////////////////////////////////////////////////////////////////////
bool Bits:: CheckONOFF1(UINT uNum)
{
    UINT uRes = 0, uMask = 0;

    /* uMask = 0000 0001 0000 0000 0000 0111 0000 0000 */
    uMask = 0x01000700;
    
    /* & will tell that bit's status ON(0) or OFF(1) */
    uRes = uNum & uMask;

    if(uRes == uMask)
        return true;
    else
        return false;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CheckONOFF
//  Input       :UINT
//  Returns     :bool
//  Description :checks whether 5th, 18th bit is On or OFF
//  Author      :Pranav Choudhary
//  Date        :27 Aug 2020
//
//////////////////////////////////////////////////////////////////////
bool Bits:: CheckONOFF2(UINT uNum)
{
    UINT uRes = 0, uMask = 0;

    /* uMask = 0000 0000 0000 0010 0000 0000 0001 0000 */
    uMask = 0x00020010;
    
    /* & will tell that bit's status ON(0) or OFF(1) */
    uRes = uNum & uMask;

    if(uRes == uMask)
        return true;
    else
        return false;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CheckONOFF
//  Input       :UINT
//  Returns     :bool
//  Description :checks whether 7th, 15th, 21th, 28th bit is On or OFF
//  Author      :Pranav Choudhary
//  Date        :27 Aug 2020
//
//////////////////////////////////////////////////////////////////////
bool Bits:: CheckONOFF3(UINT uNum)
{
    UINT uRes = 0, uMask = 0;

    /* uMask = 0000 1000 0001 0000 0100 0000 0100 0000 */
    uMask = 0x08104040;
    
    /* & will tell that bit's status ON(0) or OFF(1) */
    uRes = uNum & uMask;

    if(uRes == uMask)
        return true;
    else
        return false;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CheckONOFF
//  Input       :UINT
//  Returns     :bool
//  Description :checks whether 7th, 8th, 9th bit is On or OFF
//  Author      :Pranav Choudhary
//  Date        :27 Aug 2020
//
//////////////////////////////////////////////////////////////////////
bool Bits:: CheckONOFF4(UINT uNum)
{
    UINT uRes = 0, uMask = 0;

    /* uMask = 0000 0000 0000 0000 0000 0001 1100 0000 */
    uMask = 0x000001C0;
    
    /* & will tell that bit's status ON(0) or OFF(1) */
    uRes = uNum & uMask;

    if(uRes == uMask)
        return true;
    else
        return false;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CheckONOFF
//  Input       :UINT
//  Returns     :bool
//  Description :checks whether 1th, 32th bit is On or OFF
//  Author      :Pranav Choudhary
//  Date        :27 Aug 2020
//
//////////////////////////////////////////////////////////////////////
bool Bits:: CheckONOFF5(UINT uNum)
{
    UINT uRes = 0, uMask = 0;

    /* uMask = 1000 0000 0000 0000 0000 0000 0000 0001 */
    uMask = 0x80000001;
    
    /* & will tell that bit's status ON(0) or OFF(1) */
    uRes = uNum & uMask;

    if(uRes == uMask)
        return true;
    else
        return false;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CheckONOFF6
//  Input       :UINT
//  Returns     :bool
//  Description :checks whether 4th bit is On or OFF
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////////////////////////
bool Bits:: CheckONOFF6(UINT uNum)
{
    UINT uRes = 0, uMask = 0;

    /* uMask = 0000 0000 0000 0000 0000 0000 0000 1000 */
    uMask = 0x00000008;
    uRes = uNum & uMask;
    if(uRes == uMask)
        return true;
    else
        return false;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CheckONOFF7
//  Input       :UINT
//  Returns     :bool
//  Description :checks whether 13th bit is On or OFF
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////////////////////////
bool Bits:: CheckONOFF7(UINT uNum)
{
    UINT uRes = 0, uMask = 0;
    
    /* uMask = 0000 0000 0000 0000 0001 0000 0000 0000 */
    uMask = 0x00001000;
    
    /* & will tell that bit's status ON(0) or OFF(1) */
    uRes = uNum & uMask;

    if(uRes == uMask)
        return true;
    else
        return false;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CheckONOFF8
//  Input       :UINT
//  Returns     :bool
//  Description :checks whether 23rd bit is On or OFF
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////////////////////////
bool Bits:: CheckONOFF8(UINT uNum)
{
    UINT uRes = 0, uMask = 0;
    
    /* uMask = 0000 0000 0100 0000 0001 0000 0000 0000 */
    uMask = 0x00400000;
    
    /* & will tell that bit's status ON(0) or OFF(1) */
    uRes = uNum & uMask;

    if(uRes == uMask)
        return true;
    else
        return false;
}

int main()
{
    UINT uNum = 0;
    bool bRet = 0;
    int iCh = 0;
    Bits bObj;
    printf("Enter the number\n");
    scanf("%u", &uNum);

    printf("1. Check bits position 9, 10, 11, 25\n");
    printf("2. Check bits position 5, 18\n");
    printf("3. Check bits position 7, 15, 21, 28\n");
    printf("4. Check bits position 7, 8, 9\n");
    printf("5. Check bits position 1, 32\n");
    printf("6. Check bits position 4\n");
    printf("7. Check bits position 13\n");
    printf("8. Check bits position 23\n");
     printf("\nEnter Choice\n");
    scanf("%d", &iCh);
    switch(iCh)
    {
        case 1: bRet = bObj.CheckONOFF1(uNum);
                break;
        case 2: bRet = bObj.CheckONOFF2(uNum);
                break;
        case 3: bRet = bObj.CheckONOFF3(uNum);
                break;
        case 4: bRet = bObj.CheckONOFF4(uNum);
                break;
        case 5: bRet = bObj.CheckONOFF5(uNum);
                break;
        case 6: bRet = bObj.CheckONOFF6(uNum);
                break;
        case 7: bRet = bObj.CheckONOFF7(uNum);
                break;
        case 8: bRet = bObj.CheckONOFF8(uNum);
                break;
        default:
            printf("Enter Valid Choice\n");
    }
    if(bRet == true)
    {
        printf("TRUE\n");
    }
    else
    {
        printf("FALSE\n");
    }  
    return 0;
}
