/*
*   Program to Reverse the entered string
*/
#include<stdio.h>
#define MAXLEN      30

void StrRev(char *);
int StrLen(const char *);

int main()
{
    char cArr[MAXLEN] = {'\0'};

    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    printf("Entered String:\t%s\n", cArr);
    StrRev(cArr);
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
//  Date        :22 August 2020
//
//////////////////////////////////////////////////////////////////////
int StrLen(const char *cSrc)
{
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
//  Name        :StrRev
//  Input       :char*
//  Returns     :void
//  Description :Reverses entered string
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrRev(char* cSrc)
{
    int i = 0, j = StrLen(cSrc) - 1;
    char cTemp = '\0';
    while(i < j)
    {
        cTemp = *(cSrc + i);
        *(cSrc + i) = *(cSrc + j);
        *(cSrc + j) = cTemp;
        i++;
        j--;
    }
}