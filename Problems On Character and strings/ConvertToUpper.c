/*
*   Program to convert entered character into upper case
*/
#include<stdio.h>

char ToUpper(char);

int main()
{
    char cAlp = '\0', cRet = '\0';

    printf("Enter the character\n");
    scanf("%c", &cAlp);
    cRet = ToUpper(cAlp);
    printf("%c\n", cRet);
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :ToUpper
//  Input       :char
//  Returns     :char
//  Description :convert entered character into upper case
//  Author      :Pranav Choudhary
//  Date        :21 August 2020
//
//////////////////////////////////////////////////////////////////////
char ToUpper(char ch)
{
    if(ch >= 'a' && ch <= 'z')
        return ch - 32;
    else
        return ch;
}
