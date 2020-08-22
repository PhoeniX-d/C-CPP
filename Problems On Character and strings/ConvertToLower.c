/*
*   Program to convert entered character into lower case
*/
#include<stdio.h>

char ToLower(char);

int main()
{
    char cAlp = '\0', cRet = '\0';

    printf("Enter the character\n");
    scanf("%c", &cAlp);
    cRet = ToLower(cAlp);
    printf("%c\n", cRet);
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :ToLower
//  Input       :char
//  Returns     :char
//  Description :convert entered character into lower case
//  Author      :Pranav Choudhary
//  Date        :21 August 2020
//
//////////////////////////////////////////////////////////////////////
char ToLower(char ch)
{
    if(ch >= 'A' && ch <= 'Z')
        return ch + 32;
    else
        return ch;
}
