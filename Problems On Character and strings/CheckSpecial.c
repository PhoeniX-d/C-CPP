/*
*   Program to check whether entered char is special or not
*/
#include<stdio.h>
#define TRUE    1
#define FALSE   0
typedef char BOOL;

BOOL IsSpecial(char);

int main()
{
    char cAlp = '\0';
    BOOL bRet = FALSE;

    printf("Enter the character\n");
    scanf("%c", &cAlp);
    bRet = IsSpecial(cAlp);
    if(bRet == TRUE)
    {
        printf("It is a Special character\n");
    }
    else
    {
        printf("It is Not a Special character\n");
    }
    
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :IsSpecial
//  Input       :char
//  Returns     :BOOL
//  Description :check whether entered char is special or not
//  Author      :Pranav Choudhary
//  Date        :21 August 2020
//
//////////////////////////////////////////////////////////////////////
BOOL IsSpecial(char ch)
{
    if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z' || ch >= '0' && ch <= '9' )
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
}