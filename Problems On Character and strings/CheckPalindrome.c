/*
*   Write a program which accept string from user and check whether string is
*   palindrome or not.
*   Input : level Output : String is palindrome. 
*/
#include<stdio.h>
#define MAXLEN      30
#define TRUE         1
#define FALSE         0

typedef char BOOL;

BOOL ChkPalindrome(const char *);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    BOOL bRet = FALSE;

    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    printf("Entered String:\t%s\n", cArr);
    bRet = ChkPalindrome(cArr);
    if(bRet == TRUE)
    {
        printf("Palindrome\n");
    }
    else 
    {
        printf("Not Palindrome\n");
    }
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :ChkPalindrome
//  Input       :const char*
//  Returns     :BOOL
//  Description :check whether string is palindrome or not
//  Author      :Pranav Choudhary
//  Date        :23 August 2020
//
//////////////////////////////////////////////////////////////////////
BOOL ChkPalindrome(const char* cSrc)
{
    char *cStart = NULL;
    char *cEnd = NULL;

    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return FALSE;
    }

    cStart = cSrc;
    cEnd = cSrc;
    
    while(*(cEnd + 1) != '\0')
    {
        cEnd++;
    }
    while(cStart < cEnd)
    {
        if(*cStart != *cEnd)
        {
            break;
        }
        cEnd--;
        cStart++;
    }
    if(cStart >= cEnd)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}