/*
*   Program to check whether entered char is present in string or not
*/
#include<stdio.h>
#define TRUE     1
#define FALSE    0
#define MAXLEN  30
#define ERROR   -1

typedef char BOOL;

BOOL CheckChar(char*, char);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    char cAlp = '\0';
    BOOL bRet = FALSE;

    printf("Enter the string\n");
    scanf("%[^\n]", cArr);

    printf("Enter the character\n");
    scanf(" %c", &cAlp);

    bRet = CheckChar(cArr, cAlp);
    if(bRet == TRUE)
    {
        printf("TRUE\n");
    }
    else
    {
        printf("FALSE\n");
    }
    
    return 0;
}

////////////////////////////////////////////////////////////////////////
//
//  Name        :CheckChar
//  Input       :char*, char
//  Returns     :BOOL
//  Description :check whether entered char is present in string or not
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
////////////////////////////////////////////////////////////////////////
BOOL CheckChar(char* cSrc, char ch)
{
    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
        return ERROR;
    }

    while(*cSrc != '\0')
    {
        if(*cSrc == ch)
        {
            break;
        }
        cSrc++;
    }
    if(*cSrc == '\0')
    {
        return FALSE;
    }
    else
    {
        return TRUE;
    }
    
}