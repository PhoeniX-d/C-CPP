/*
*   Write a program to check whether given strings are Anagram strings or not.
*   
*   Input : abccd cbcda Output : Strings are anagram
*/
#include<stdio.h>

#define MAXLEN      30
#define ERROR       -1
#define MAX_CAHR   127
#define TRUE         1
#define FALSE        0

typedef char BOOL;

BOOL StrAnagram(const char *, const char *);

int main()
{
    char cStr1[MAXLEN] = {'\0'};
    char cStr2[MAXLEN] = {'\0'};
    BOOL bRet = 0;

    printf("Enter the string 1\n"); 
    scanf("%[^\n]", cStr1);

    printf("Enter the string 2\n"); 
    scanf(" %[^\n]", cStr2);

    bRet = StrAnagram(cStr1, cStr2);

    if(bRet == TRUE)
    {
        printf("Strings are Anagram\n");
    }
    else
    {
        printf("Strings are not Anagram\n");
    }
    
    return 0;
}

/////////////////////////////////////////////////////////////////////////
//
//  Name        :StrAnagram
//  Input       :const char*, const char*
//  Returns     :BOOL
//  Description :check whether given strings are Anagram strings or not.
//  Author      :Pranav Choudhary
//  Date        :23 August 2020
//
/////////////////////////////////////////////////////////////////////////
BOOL StrAnagram(const char* cStr1, const char* cStr2)
{
    char cChars[MAX_CAHR] = {0};
    int i = 0;
    if(cStr1 == NULL || cStr2 == NULL)
    {
        printf("Invalid Input\n");
        return ERROR;
    }

    while(*cStr1 != '\0' && *cStr2 != '\0')
    {
        cChars[*cStr1]++;
        cChars[*cStr2]--;
        cStr1++;
        cStr2++;
    }
    if(*cStr1 == '\0' && *cStr2 == '\0' )
    {
       for (i = 0; i < MAX_CAHR; i++)
        {
            if(cChars[i] != 0)
            {
                break;
            }
        }
    }
    if(i == MAX_CAHR)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }    
}
