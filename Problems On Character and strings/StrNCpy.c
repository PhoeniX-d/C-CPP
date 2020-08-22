/*
*   Program to copy source string's N chars into destination string
*/
#include<stdio.h>
#define MAXLEN      30

void StrNCpy(const char *, char*, int);

int main()
{
    char cSrc[MAXLEN] = {'\0'};
    char cDest[MAXLEN] = {'\0'};
    int iN = 0;

    printf("Enter the string\n"); 
    scanf("%[^\n]", cSrc);

    printf("Enter number of characters\n");
    scanf(" %d", &iN);

    printf("Entered String:\t%s\n", cSrc);;
    StrNCpy(cSrc, cDest, iN);

    printf("Output String:\t%s\n", cDest);
    return 0;
}

///////////////////////////////////////////////////////////////////////
//
//  Name        :StrNCpy
//  Input       :const char*, char*, int
//  Returns     :void
//  Description :copy source string's N chars into destination string
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
///////////////////////////////////////////////////////////////////////
void StrNCpy(const char* cSrc, char* cDest, int iN)
{
    if(cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    if(iN < 0)
        iN = -iN;

    while(*cSrc != '\0' && iN != 0)
    {
        *cDest = *cSrc;
        cSrc++;
        cDest++;
        iN--;
    }
    *cDest = '\0';
}