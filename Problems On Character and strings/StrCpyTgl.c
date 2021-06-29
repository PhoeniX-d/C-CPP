/*
*   Program to toggle letters from source string into destination string
*/
#include<stdio.h>
#define MAXLEN      30

void StrCpyTgl(const char *, char*);

int main()
{
    char cSrc[MAXLEN] = {'\0'};
    char cDest[MAXLEN] = {'\0'};

    printf("Enter the string\n"); 
    scanf("%[^\n]", cSrc);

    printf("Entered String:\t%s\n", cSrc);;
    StrCpyTgl(cSrc, cDest);

    printf("Output String:\t%s\n", cDest);
    return 0;
}

////////////////////////////////////////////////////////////////////////////
//
//  Name        :StrCpyTgl
//  Input       :const char*, char*
//  Returns     :void
//  Description :toggle letters from source string into destination string
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
/////////////////////////////////////////////////////////////////////////////
void StrCpyTgl(const char* cSrc, char* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    while(*cSrc != '\0')
    {
        if(*cSrc >= 'a' && *cSrc <= 'z')
        {
            *cDest = *cSrc - 32;
            cDest++;
        }
        else if(*cSrc >= 'A' && *cSrc <= 'Z')
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
