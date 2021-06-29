/*
*   Accept sing from user and reverse the contents of that string by
*   toggling the case.
*   Input : "aCBdef"
*   Output : "FEDcbA" 
*/
#include<stdio.h>
#define MAXLEN      30

void StrTglRev(char *);

int main()
{
    char cSrc[MAXLEN] = {'\0'};

    printf("Enter the string\n"); 
    scanf("%[^\n]", cSrc);

    StrTglRev(cSrc);

    printf("Output String:\t%s\n", cSrc);
    return 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Name        :StrTglRev
//  Input       :char*
//  Returns     :void
//  Description :reverse the contents of that string by toggling the case
//  Author      :Pranav Choudhary
//  Date        :28 August 2020
//
/////////////////////////////////////////////////////////////////////////////
void StrTglRev(char* cSrc)
{
    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    char *cStart = cSrc;
    char *cEnd = cSrc;
    char cTemp = '\0';

    while(*cEnd != '\0')
    {
        if(*cEnd >= 'a' && *cEnd <= 'z')
        {
            *cEnd = *cEnd - 32;
        }
        else if(*cEnd >= 'A' && *cEnd <= 'Z')
        {
            *cEnd = *cEnd + 32;
        }
        cEnd++;
    }
    cEnd--;
    while(cStart < cEnd)
    {
        cTemp = *cStart;
        *cStart = *cEnd;
        *cEnd = cTemp;
        cStart++;
        cEnd--;
    }
}