/*
*   Write a program which sets last N characters in string to a specific character 
*   (Implement strnset()).
*   Input   : HelloWorld 
*           : a 8
*   Output  : aaaaaaaald 
*/

#include<stdio.h>

#define MAXLEN      30

void StrNSetL(char *, char, int);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    char cAlp = '\0';
    int iN = 0;

    printf("Enter the string\n");
    scanf("%[^\n]", cArr);

    printf("Enter the character\n");
    scanf(" %c", &cAlp);

    printf("Enter N\n");
    scanf("%d", &iN);

    StrNSetL(cArr, cAlp, iN);
    printf("Ouput string:\t%s\n", cArr);
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrNSetL
//  Input       :char*, char
//  Returns     :void
//  Description :sets last N characters in string to a specific 
//               character (Implement strnset())
//  Author      :Pranav Choudhary
//  Date        :23 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrNSetL(char *cSrc, char ch, int iN)
{
    char *cEnd = cSrc;
    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    if(iN < 0)
    {
        iN = -iN;
    }

    while(*(cEnd + 1) != '\0')
    {
        cEnd++;
    }
    while(cEnd != cSrc && iN != 0)
    {
        *cEnd = ch;
        cEnd--;
        iN--;
    }
    *cEnd = ch;
}
