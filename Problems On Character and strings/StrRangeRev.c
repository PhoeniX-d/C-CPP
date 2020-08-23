/*
*   Write a program which accept string from user and then accept range and
*   reverse the string in that range without taking another string.
*   
*   Input : Hello World 
*           3 8 
*   Output : HeoW ollrld 
*/

#include<stdio.h>
#define MAXLEN      30

void StrRangeRev(char *, int, int);
int StrLen(const char *);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    int iStart = 0, iEnd = 0;

    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    printf("Enter start\n");
    scanf(" %d", &iStart);

    printf("Enter end\n");
    scanf("%d", &iEnd);
    
    StrRangeRev(cArr, iStart, iEnd);

    printf("Output String:\t%s\n", cArr);
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrLen
//  Input       :const char*
//  Returns     :int
//  Description :computes length of entered string
//  Author      :Pranav Choudhary
//  Date        :23 August 2020
//
//////////////////////////////////////////////////////////////////////
int StrLen(const char *cSrc)
{
    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return 0;
    }
    int iLen = 0;
    while(*cSrc != '\0')
    {
        iLen++;
        cSrc++;
    }
    return iLen;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrRangeRev
//  Input       :char*, int, int
//  Returns     :void
//  Description :reverse the string in that range without
//               taking another string
//  Author      :Pranav Choudhary
//  Date        :23 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrRangeRev(char* cSrc, int iS, int iE)
{
    if(iS < 0)
    {
        iS = -iS;
    }
    if(iE < 0)
    {
        iE = -iE;
    }
    if(cSrc == NULL || iS >= iE || StrLen(cSrc) < iS || StrLen(cSrc) < iE)
    {
        printf("Invalid Input\n");
        return;
    }

    char cTemp = '\0';
    char *cStart = cSrc;
    char *cEnd = cSrc;

    if(iS == 0)
    {
        cStart = cSrc + iS;
    }
    else
    {
        cStart = cSrc + (iS - 1);
    }    
    cEnd = cSrc + (iE - 1);

    while(cStart < cEnd)
    {
        cTemp = *cStart;
        *cStart = *cEnd;
        *cEnd = cTemp;
        cEnd--;
        cStart++;
    }
}