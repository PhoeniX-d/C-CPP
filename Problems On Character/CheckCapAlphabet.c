/*
*   Program to check whether entered char is capital alphabetor not
*/
#include<stdio.h>
#define TRUE    1
#define FALSE   0
typedef char BOOL;

BOOL IsCapAlpha(char);

int main()
{
    char cAlp = '\0';
    BOOL bRet = FALSE;

    printf("Enter the character\n");
    scanf("%c", &cAlp);
    bRet = IsCapAlpha(cAlp);
    if(bRet == TRUE)
    {
        printf("It is an capital Alphabet\n");
    }
    else
    {
        printf("It is Not an capital alphabet\n");
    }
    
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :IsCapAlpha
//  Input       :char
//  Returns     :BOOL
//  Description :check whether entered char is capital alphabetor not
//  Author      :Pranav Choudhary
//  Date        :21 August 2020
//
//////////////////////////////////////////////////////////////////////
BOOL IsCapAlpha(char ch)
{
    if(ch >= 'A' && ch <= 'Z')
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}