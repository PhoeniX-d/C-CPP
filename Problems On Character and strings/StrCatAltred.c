/*
*   Write a program which accept two strings from user and concat
*   alternate characters from second string at the end of first string.
*   Input : "Hello, "    "Universe"
*   Output : Hello,Uies
*/
#include<stdio.h>
#define MAXLEN      20

void StrCatAltr(char *, const char*);

int main()
{
    char cDest[MAXLEN * 2] = {'\0'};
    char cSrc[MAXLEN] = {'\0'};

    printf("Enter the 1st string\n"); 
    scanf("%[^\n]", cDest);

    printf("Enter the 2nd string\n"); 
    scanf(" %[^\n]", cSrc);

    StrCatAltr(cDest, cSrc);

    printf("Output String:\t%s\n", cDest);
    return 0;
}

////////////////////////////////////////////////////////////
//
//  Name        :StrCatAltr
//  Input       :char*, const char*
//  Returns     :void
//  Description :concate two strings
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
////////////////////////////////////////////////////////////
void StrCatAltr(char* cDest, const char* cSrc)
{
    if(cDest == NULL || cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    while(*cDest != '\0')
    {
        cDest++;
    }
    while(*cSrc != '\0')
    {
        *cDest = *cSrc;
        if(*(cSrc + 1) == '\0') 
        {
            cDest++;
            break;
        }
        cSrc = cSrc + 2;           
        cDest++;
    }
    *cDest = '\0';
}
