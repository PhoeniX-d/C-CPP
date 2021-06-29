/*
*   Program to club bytes of an IP address
*/
#include<stdio.h>
#include<string.h>

#define BITS    sizeof(int) * 8
#define BYTE                  8
#define MAXLEN               16

typedef unsigned int UINT;
typedef char *PCHAR;

UINT ClubBytes(PCHAR);

int main()
{
    UINT uRet = 0;
    char cIp[MAXLEN] = {'\0'};

    printf("Enter the IP address:\n");
    scanf("%s", cIp);

    uRet = ClubBytes(cIp);

    printf("\nOutput:\n\n");
    printf("Decimal     :\t%u\n", uRet);


    return 0;
}

//////////////////////////////////////////////////////////////
//
//  Name        :ClubBytes
//  Input       :PCAHR
//  Output      :UINT
//  Description :club bytes of an IP address
//  Author      :Pranav Choudhary
//  Date        :28 Aug 2020
//
//////////////////////////////////////////////////////////////
UINT ClubBytes(PCHAR cIp)
{
    char *cIPnum = NULL;
    int iArr[4] = {0}, i = 0;
    UINT uMask = 0x0000000F, uByte = 0, uRes = 0;

    cIPnum = strtok(cIp, ".");
    while(cIPnum != NULL)
    {
        iArr[i] = atoi(cIPnum);
        if(iArr[i] > 255 && iArr[i] < 0)
        {
            printf("Invalid IP address\n");
            return uRes;
        }
        cIPnum = strtok(NULL, ".");
        i++;
    }

    for (int i = 1; i <= sizeof(int); i++)
    {
        uByte = iArr[i - 1] & uMask;
        uByte = uByte << (BITS - i * 8);
        uRes = uRes | uByte;
    }

    return uRes;
}