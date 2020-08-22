/*
*   Program to count words in given string
*/

#include<stdio.h>
#define MAXLEN      30
#define ERROR       -1
#define IN           1
#define OUT          0
int WordCnt(char *);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    int iRet = 0;
    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    iRet = WordCnt(cArr);
    if(iRet != ERROR)
        printf("Total Words :\t%d", iRet);

    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//  Name        :WordCnt
//  Input       :char *
//  Returns     :int
//  Description :count words in given string
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
//////////////////////////////////////////////////////////////////////
int WordCnt(const char *cSrc)
{
    int iCnt = 0;
    int iState = OUT;
    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
        return ERROR;
    }
    while (*cSrc != '\0')
    {
        if(*cSrc == ' ' || *cSrc == '\n' || *cSrc == '\t')
		{
            iState = OUT;
        }
		else if(iState == OUT)
		{	
			iState = IN;
			iCnt++;
		}
        cSrc++;
    }
    return iCnt;
}