/*
*   Program to compute difference between capital and lower case
*/

#include<stdio.h>
#define MAXLEN      15
#define ERROR       -1

int DiffCapLow(char *);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    int iRet = 0;
    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    iRet = DiffCapLow(cArr);
    if(iRet != ERROR)
        printf("%d", iRet);

    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//  Name        :DiffCapLow
//  Input       :char *
//  Returns     :int
//  Description :compute difference between capital and lower case
//  Author      :Pranav Choudhary
//  Date        :21 August 2020
//
//////////////////////////////////////////////////////////////////////
int DiffCapLow(char *cSrc)
{
    int iLcnt = 0, iCcnt = 0;
    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
        return ERROR;
    }
    
    while(*cSrc != '\0')
    {
        if (*cSrc >= 'a' && *cSrc <= 'z')
        {
            iLcnt++;
        }
        else if(*cSrc >= 'A' && *cSrc <= 'Z')
        {
            iCcnt++;
        }
        cSrc++;
    }
    return iLcnt - iCcnt;
}