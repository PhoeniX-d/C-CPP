/*
*   Program to convert capital letters to small letters from source string
*   into destination string
*/
#include<stdio.h>
#define MAXLEN      30

void StrCpyLwrX(const char *, char*);

int main()
{
    char cSrc[MAXLEN] = {'\0'};
    char cDest[MAXLEN] = {'\0'};

    printf("Enter the string\n"); 
    scanf("%[^\n]", cSrc);

    printf("Entered String:\t%s\n", cSrc);;
    StrCpyLwrX(cSrc, cDest);

    printf("Output String:\t%s\n", cDest);
    return 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Name        :StrCpyLwrX
//  Input       :const char*, char*
//  Returns     :void
//  Description :convert capital letters to small letters from source string
//               into destination string
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
/////////////////////////////////////////////////////////////////////////////
void StrCpyLwrX(const char* cSrc, char* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    while(*cSrc != '\0')
    {
        if(*cSrc >= 'A' && *cSrc <= 'Z')
        {
            *cDest = *cSrc + 32;
            cDest++;
        }
        else
        {
            *cDest = *cSrc;
            cDest++;
        }        
        cSrc++;
    }
    *cDest = '\0';
}