/*
*   Program to copy source string into destination string
*/
#include<stdio.h>
#define MAXLEN      30

void StrCpySpace(const char *, char*);

int main()
{
    char cSrc[MAXLEN] = {'\0'};
    char cDest[MAXLEN] = {'\0'};

    printf("Enter the string\n"); 
    scanf("%[^\n]", cSrc);

    StrCpySpace(cSrc, cDest);
    printf("Output String:\n%s\n", cDest);
    return 0;
}

////////////////////////////////////////////////////////////
//
//  Name        :StrCpySpace
//  Input       :const char*, char*
//  Returns     :void
//  Description :copy source string into destination string
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
////////////////////////////////////////////////////////////
void StrCpySpace(const char* cSrc, char* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    while(*cSrc != '\0')
    {
        if(*cSrc != ' ')
        {
            *cDest = *cSrc;
            cDest++;
        }
        cSrc++;
    }
    *cDest = '\0';
}
