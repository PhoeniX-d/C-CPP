/*
*   Program to count words in given string
*/

#include<stdio.h>

#define MAXLEN      30
#define ERROR       -1


int WordCnt(const char *);

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
//  Input       :const char *
//  Returns     :int
//  Description :count words in given string
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
//////////////////////////////////////////////////////////////////////
int WordCnt(const char *cStr)
{
    int iCnt = 0;
    if(NULL == cStr)
    {
        printf("Invalid Input\n");
        return ERROR;
    }
       
    while(*cStr != '\0')
    {
        if(*cStr == ' ')
		{
			while((*cStr == ' ' || *cStr == '\t') && (*cStr != '\0'))
			{
				cStr++;
			}
		}
		else
		{
			while(*cStr != ' ' && *cStr != '\0')
			{
                cStr++;
            }
            iCnt++;
        }
        cStr++; 
    }
    return iCnt;
}