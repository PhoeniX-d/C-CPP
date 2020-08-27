/*
*   Program which toggles the bits
*/
#include<stdio.h>
typedef unsigned int UINT;

class ToggleBits
{
    public:
        UINT Toggle7thBit(UINT);
        UINT Toggle13thBit(UINT);
        UINT Toggle7th10thBit(UINT);
};

//////////////////////////////////////////////////////////////////////
//
//  Name        :Toggle7thBit
//  Input       :UINT
//  Returns     :UINT
//  Description :toggles 7th bit
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////////////////////////
UINT ToggleBits::Toggle7thBit(UINT uNum)
{
    UINT uMask = 0;
    
    /* uMask = 0000 0000 0000 0000 0000 0000 0100 0000 */
    uMask = 0x00000040;
    
    /* ^ will toggle that bit's status ON(0) or OFF(1) */
    return uNum ^ uMask;

}

//////////////////////////////////////////////////////////////////////
//
//  Name        :Toggle13thBit
//  Input       :UINT
//  Returns     :UINT
//  Description :toggles 13th bit
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////////////////////////
UINT ToggleBits::Toggle13thBit(UINT uNum)
{
    UINT uMask = 0;
    
    /* uMask = 0000 0000 0000 0000 0001 0000 0000 0000 */
    uMask = 0x00001000;
    
    /* ^ will toggle that bit's status ON(0) or OFF(1) */
    return uNum ^ uMask;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :Toggle7th10thBit
//  Input       :UINT
//  Returns     :UINT
//  Description :toggles 7th and 10th bit
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////////////////////////
UINT ToggleBits::Toggle7th10thBit(UINT uNum)
{
    UINT uMask = 0;
    
    /* uMask = 0000 0000 0000 0000 0000 0010 0100 0000 */
    uMask = 0x00000240;
    
    /* ^ will toggle that bit's status ON(0) or OFF(1) */
    return uNum ^ uMask;
}


int main()
{
    UINT uNum = 0, uRet = 0;
    int iCh = 0;
    ToggleBits tbObj;

    printf("Enter the number\n");
    scanf("%u", &uNum);

    printf("1. Toggle 7th bit\n");
    printf("2. Toggle 13th bit\n");
    printf("3. Toggle 7th and 10th bit\n");
    printf("\nEnter choice\n");
    scanf("%d", &iCh);

    switch(iCh)
    {
        case 1:
            uRet = tbObj.Toggle7thBit(uNum);
            break;
        case 2:
            uRet = tbObj.Toggle13thBit(uNum);
            break;
        case 3:
            uRet = tbObj.Toggle7th10thBit(uNum);
            break;
        default:
            printf("Enter Valid Choice\n");
    }

    printf("Output:\n%u\n", uRet);

    return 0;
}