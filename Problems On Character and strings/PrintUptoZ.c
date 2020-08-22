/*
*   Program to print upto Z from entered character
*/
#include<stdio.h>

void UptoZ(char);

int main()
{
    char cAlp = '\0';

    printf("Enter the character\n");
    scanf("%c", &cAlp);
    UptoZ(cAlp);
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :UptoZ
//  Input       :char
//  Returns     :void
//  Description :print upto Z from entered character
//  Author      :Pranav Choudhary
//  Date        :21 August 2020
//
//////////////////////////////////////////////////////////////////////
void UptoZ(char ch)
{
    char i = 0;
    if(ch >= 'A' && ch <= 'Z')
    {
        for (i = ch; i <= 'Z'; i++)
        {
            printf("%c ", i);
        }
    }
    else if(ch >= 'a' && ch <= 'z')
    {
        for (i = ch; i <= 'z'; i++)
        {
            printf("%c ", i);
        }
    }
}
