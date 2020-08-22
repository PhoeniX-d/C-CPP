/*
*   Program to copy lower letters from source string
*   into destination string
*/
#include<stdio.h>
#define MAXLEN      30

void StrCpyLwr(const char *, char*);

int main()
{
    char cSrc[MAXLEN] = {'\0'};
    char cDest[MAXLEN] = {'\0'};

    printf("Enter the string\n"); 
    scanf("%[^\n]", cSrc);

    printf("Entered String:\t%s\n", cSrc);;
    StrCpyLwr(cSrc, cDest);

    printf("Output String:\t%s\n", cDest);
    return 0;
}

////////////////////////////////////////////////////////////
//
//  Name        :StrCpyLwr
//  Input       :const char*, char*
//  Returns     :void
//  Description :copy lower letters from source string 
//               into destination string
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
////////////////////////////////////////////////////////////
void StrCpyLwr(const char* cSrc, char* cDest)
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
            *cDest = *cSrc;
            cDest++;
        }
        cSrc++;
    }
    *cDest = '\0';
}
