/*
*   Program to check whether entered char is Digit or not
*/
#include<stdio.h>
#define TRUE    1
#define FALSE   0
typedef char BOOL;

BOOL IsDigit(char);

int main()
{
    char cAlp = '\0';
    BOOL bRet = FALSE;

    printf("Enter the character\n");
    scanf("%c", &cAlp);
    bRet = IsDigit(cAlp);
    if(bRet == TRUE)
    {
        printf("It is an Digit\n");
    }
    else
    {
        printf("It is Not an Digit\n");
    }
    
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :IsDigit
//  Input       :char
//  Returns     :BOOL
//  Description :check whether entered char is Digit or not
//  Author      :Pranav Choudhary
//  Date        :21 August 2020
//
//////////////////////////////////////////////////////////////////////
BOOL IsDigit(char ch)
{
    if(ch >= '0' && ch <= '9')
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}