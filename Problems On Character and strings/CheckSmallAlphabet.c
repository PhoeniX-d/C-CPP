/*
*   Program to check whether entered char is small alphabetor not
*/
#include<stdio.h>
#define TRUE    1
#define FALSE   0
typedef char BOOL;

BOOL IsSmallAlpha(char);

int main()
{
    char cAlp = '\0';
    BOOL bRet = FALSE;

    printf("Enter the character\n");
    scanf("%c", &cAlp);
    bRet = IsSmallAlpha(cAlp);
    if(bRet == TRUE)
    {
        printf("It is an small Alphabet\n");
    }
    else
    {
        printf("It is Not an small alphabet\n");
    }
    
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :IsSmallAlpha
//  Input       :char
//  Returns     :BOOL
//  Description :check whether entered char is small alphabetor not
//  Author      :Pranav Choudhary
//  Date        :21 August 2020
//
//////////////////////////////////////////////////////////////////////
BOOL IsSmallAlpha(char ch)
{
    if(ch >= 'a' && ch <= 'z')
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}