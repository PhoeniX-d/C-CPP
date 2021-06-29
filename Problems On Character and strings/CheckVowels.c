/*
*   Program to check whether given string contains vowels in it or not
*/

#include<stdio.h>
#define MAXLEN      30
#define ERROR       -1
#define TRUE         1
#define FALSE        0
typedef char BOOL;

BOOL CheckVowel(char *);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    BOOL bRet = 0;
    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    bRet = CheckVowel(cArr);
    if(bRet == TRUE)
        printf("TRUE\n");
    else if(bRet == FALSE)
        printf("FALSE\n");

    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//  Name        :CheckVowel
//  Input       :char *
//  Returns     :BOOL
//  Description :check whether given string contains vowels in it or not
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
//////////////////////////////////////////////////////////////////////
BOOL CheckVowel(char *cSrc)
{
    int iLcnt = 0;
    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
        return ERROR;
    }
    
    while(*cSrc != '\0')
    {
        if (
            *cSrc >= 'a' && *cSrc <= 'e' || *cSrc == 'i' || *cSrc == 'o' || *cSrc == 'u' ||
            *cSrc >= 'A' && *cSrc <= 'E' || *cSrc == 'I' || *cSrc == 'O' || *cSrc == 'U'
            )
        {
            break;
        }
        cSrc++;
    }
    
    if(*cSrc != '\0')
        return TRUE;
    else
        return FALSE;
}
