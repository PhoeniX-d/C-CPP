/*
*   Program to Reverse the entered string
*/
#include<stdio.h>
#define MAXLEN      30

void StrRev(char *);

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
    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    char cTemp = '\0';
    char *cStart = cSrc;
    char *cEnd = cSrc;

    while(*cEnd != '\0')
    {
        cEnd++;
    }
    cEnd--;
    while(cStart < cEnd)
    {
        cTemp = *cStart;
        *cStart = *cEnd;
        *cEnd = cTemp;
        cEnd--;
        cStart++;
    }
}