/*
*   Program to check whether entered char is alphabet or not
*/
#include<stdio.h>
#define TRUE    1
#define FALSE   0
typedef char BOOL;

BOOL IsAlpha(char);

int main()
{
    char cAlp = '\0';
    BOOL bRet = FALSE;

    printf("Enter the character\n");
    scanf("%c", &cAlp);
    bRet = IsAlpha(cAlp);
    if(bRet == TRUE)
    {
        printf("It is an Alphabet\n");
    }
    else
    {
        printf("It is Not an alphabet\n");
    }
    
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :IsAlpha
//  Input       :char
//  Returns     :BOOL
//  Description :check whether entered char is alphabet or not
//  Author      :Pranav Choudhary
//  Date        :21 August 2020
//
//////////////////////////////////////////////////////////////////////
BOOL IsAlpha(char ch)
{
    if(ch >= 'A' && ch <= 'Z' || ch >= 'a' && ch <= 'z')
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}