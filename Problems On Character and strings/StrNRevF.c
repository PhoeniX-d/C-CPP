/*
*   Write a program which accept string from user and then reverse the 
*   string till 'first' N characters without taking another string.
*   
*   Input : Hello World 5 Output : olleH World 
*/
#include<stdio.h>
#define MAXLEN      30

void StrNRevF(char *, int);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    int iN = 0;

    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    printf("Enter N\n");
    scanf(" %d", &iN);
    
    StrNRevF(cArr, iN);

    printf("Output String:\t%s\n", cArr);
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrNRevF
//  Input       :char*, int
//  Returns     :void
//  Description :reverse the string till first N characters without 
//               taking another string.
//  Author      :Pranav Choudhary
//  Date        :23 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrNRevF(char* cSrc, int iN)
{
    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }

    if(iN < 0)
    {
        iN = -iN;
    }

    char cTemp = '\0';
    char *cStart = cSrc;
    char *cEnd = cSrc;

    while(*cEnd != '\0' && iN != 1)
    {
        iN--;
        cEnd++;
    }
    if(iN != 1)
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