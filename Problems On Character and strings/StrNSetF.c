/*
*   Write a program which sets first N characters in string to a specific character 
*   (Implement strnset()).
*   Input   : HelloWorld 
*           : a 8
*   Output  : aaaaaaaald 
*/

#include<stdio.h>

#define MAXLEN      30

void StrNSetF(char *, char, int);

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

    StrNSetF(cArr, cAlp, iN);
    printf("Ouput string:\t%s\n", cArr);
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrNSetF
//  Input       :char*, char
//  Returns     :void
//  Description :sets first N characters in string to a specific 
//               character (Implement strnset())
//  Author      :Pranav Choudhary
//  Date        :23 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrNSetF(char *cSrc, char ch, int iN)
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
    while(*cSrc != '\0' && iN != 0)
    {
        *cSrc = ch;
        cSrc++;
        iN--;
    }
}
