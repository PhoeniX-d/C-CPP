/*
*   Program to compute entered Char in the entered string
*/
#include<stdio.h>
#define MAXLEN      30

int CntChar(const char *, char);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    char cAlp = '\0';
    int iRet = 0;

    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    printf("Enter the character\n");
    scanf(" %c", &cAlp);

    iRet = CntChar(cArr, cAlp);

    printf("No. of \'%c\' :\t%d\n", cAlp, iRet);
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CntChar
//  Input       :const char*, char
//  Returns     :int
//  Description :compute entered Char in the entered string
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
//////////////////////////////////////////////////////////////////////
int CntChar(const char *cSrc, char ch)
{
    int iCnt = 0;
    while(*cSrc != '\0')
    {
        if(*cSrc == ch)
        {
            iCnt++;
        }
        cSrc++;
    }
    return iCnt;
}
