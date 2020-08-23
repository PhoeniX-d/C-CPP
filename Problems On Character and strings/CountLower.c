/*
*   Program to count small letters in given string
*/

#include<stdio.h>
#define MAXLEN      15
#define ERROR       -1

int CountLwr(char *);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    int iRet = 0;
    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    iRet = CountLwr(cArr);
    if(iRet != ERROR)
        printf("%d", iRet);

    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//  Name        :CountLwr
//  Input       :char *
//  Returns     :int
//  Description :count small letters in given string
//  Author      :Pranav Choudhary
//  Date        :21 August 2020
//
//////////////////////////////////////////////////////////////////////
int CountLwr(char *cSrc)
{
    int iCnt = 0;
    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
        return ERROR;
    }
    
    while(*cSrc != '\0')
    {
        if (*cSrc >= 'a' && *cSrc <= 'z')
        {
            iCnt++;
        }
        cSrc++;
    }

    return iCnt;
}