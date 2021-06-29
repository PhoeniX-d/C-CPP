/*
*   Program to copy capital letters from source string
*   into destination string
*/
#include<stdio.h>
#define MAXLEN      30

void StrCpyCap(const char *, char*);

int main()
{
    char cSrc[MAXLEN] = {'\0'};
    char cDest[MAXLEN] = {'\0'};

    printf("Enter the string\n"); 
    scanf("%[^\n]", cSrc);

    printf("Entered String:\t%s\n", cSrc);;
    StrCpyCap(cSrc, cDest);

    printf("Output String:\t%s\n", cDest);
    return 0;
}

////////////////////////////////////////////////////////////
//
//  Name        :StrCpyCap
//  Input       :const char*, char*
//  Returns     :void
//  Description :copy capital letters from source string 
//               into destination string
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
////////////////////////////////////////////////////////////
void StrCpyCap(const char* cSrc, char* cDest)
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
            *cDest = *cSrc;
            cDest++;
        }
        cSrc++;
    }
    *cDest = '\0';
}