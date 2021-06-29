/*
*   Program to concate 2nd string to first in reverse
*/
#include<stdio.h>
#define MAXLEN      20

void StrCatRev(char *, const char*);

int main()
{
    char cDest[MAXLEN * 2] = {'\0'};
    char cSrc[MAXLEN] = {'\0'};

    printf("Enter the 1st string\n"); 
    scanf("%[^\n]", cDest);

    printf("Enter the 2nd string\n"); 
    scanf(" %[^\n]", cSrc);

    StrCatRev(cDest, cSrc);

    printf("Output String:\t%s\n", cDest);
    return 0;
}

////////////////////////////////////////////////////////////
//
//  Name        :StrCatRev
//  Input       :char*, const char*
//  Returns     :void
//  Description :concate 2nd string to first in reverse
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
////////////////////////////////////////////////////////////
void StrCatRev(char* cDest, const char* cSrc)
{
    if(cDest == NULL || cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    const char *cEnd = cSrc;

    while(*cDest != '\0')
    {
        cDest++;
    }
    while(*(cEnd + 1) != '\0')
    {
        cEnd++;
    }

    while(cEnd != (cSrc - 1))
    {
        *cDest = *cEnd;
        cEnd--;
        cDest++;
    }
    *cDest = '\0';
}
