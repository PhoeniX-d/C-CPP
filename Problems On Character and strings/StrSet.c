/*
*   Write a program which sets all characters in string to a specific character
*   (Implement strset()).
*   Input   : HelloWorld 
*           : a 
*   Output  : aaaaaaaaaa 
*/

#include<stdio.h>

#define MAXLEN      30

void StrSet(char *, char);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    char cAlp = '\0';

    printf("Enter the string\n");
    scanf("%[^\n]", cArr);

    printf("Enter the character\n");
    scanf(" %c", &cAlp);

    StrSet(cArr, cAlp);
    printf("Ouput string:\t%s\n", cArr);
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrSet
//  Input       :char*, char
//  Returns     :void
//  Description :sets all characters in string to a specific character
//               (Implement strset())
//  Author      :Pranav Choudhary
//  Date        :23 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrSet(char *cSrc, char ch)
{
    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    while(*cSrc != '\0')
    {
        *cSrc = ch;
        cSrc++;
    }
}
