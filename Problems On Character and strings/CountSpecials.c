/*
*   Program to count special characters in given string
*/

#include<stdio.h>
#define MAXLEN      20
#define ERROR       -1

int CountSpecials(const char *);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    int iRet = 0;

    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    iRet = CountSpecials(cArr);
    if(iRet != ERROR)
        printf("Special characters:\t%d\n", iRet);

    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//  Name        :CountSpecials
//  Input       :const char *
//  Returns     :int
//  Description :count special characters in given string
//  Author      :Pranav Choudhary
//  Date        :21 August 2020
//
//////////////////////////////////////////////////////////////////////
int CountSpecials(const char *cSrc)
{
    int iCnt = 0;
    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
        return ERROR;
    }
    
    while(*cSrc != '\0')
    {
        if ( !(*cSrc >= 'a' && *cSrc <= 'z') && 
             !(*cSrc >= 'A' && *cSrc <= 'Z') && 
             !(*cSrc >= '0' && *cSrc <= '9'))
        {
            iCnt++;
        }
        cSrc++;
    }

    return iCnt;
}