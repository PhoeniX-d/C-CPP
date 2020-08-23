/*
*   Write a program which accept string from user and then reverse the 
*   string till 'last' N characters without taking another string.
*   
*   Input : Hello World 5 Output : Hello dlroW
*/
#include<stdio.h>
#define MAXLEN      30

void StrNRevL(char *, int);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    int iN = 0;

    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    printf("Enter N\n");
    scanf(" %d", &iN);
    
    StrNRevL(cArr, iN);

    printf("Output String:\t%s\n", cArr);
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrNRevL
//  Input       :char*, int
//  Returns     :void
//  Description :reverse the string till las    t N characters without 
//               taking another string.
//  Author      :Pranav Choudhary
//  Date        :23 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrNRevL(char* cSrc, int iN)
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
    char *cEnd = NULL;

    while(*cStart != '\0')
    {
        cStart++;
    }
    cEnd = cStart--;

    while(iN != 0 && cEnd != cSrc)
    {
        iN--;
        cEnd--;
    }

    while(cStart > cEnd)
    {
        cTemp = *cStart;
        *cStart = *cEnd;
        *cEnd = cTemp;
        cEnd++;
        cStart--;
    }
}