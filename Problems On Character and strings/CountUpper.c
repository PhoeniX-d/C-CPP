/*
*   Program to count capital letters in given string
*/

#include<stdio.h>
#define MAXLEN      15
#define ERROR       -1

int CountUpr(char *);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    int iRet = 0;
    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    iRet = CountUpr(cArr);
    if(iRet != ERROR)
        printf("%d", iRet);

    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//  Name        :CountUpr
//  Input       :char *
//  Returns     :int
//  Description :count capital letters in given string
//  Author      :Pranav Choudhary
//  Date        :21 August 2020
//
//////////////////////////////////////////////////////////////////////
int CountUpr(char *cSrc)
{
    int iCnt = 0;
    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
        return ERROR;
    }
    
    while(*cSrc != '\0')
    {
        if (*cSrc >= 'A' && *cSrc <= 'Z')
        {
            iCnt++;
        }
        cSrc++;
    }

    return iCnt;
}