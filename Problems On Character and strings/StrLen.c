/*
*   Program to compute length of string
*/
#include<stdio.h>
#define MAXLEN      30

int StrLen(const char *);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    int iRet = 0;
    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    printf("Entered String:\t%s\n", cArr);
    iRet = StrLen(cArr);
    if(iRet != -1)
        printf("Length of String:\t%d\n", iRet);
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrLen
//  Input       :const char*
//  Returns     :int
//  Description :computes length of entered string
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
//////////////////////////////////////////////////////////////////////
int StrLen(const char *cSrc)
{
    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return -1;
    }
    int iLen = 0;
    char *cTemp = cSrc;
    while(*cTemp != '\0')
    {
        iLen++;
        cTemp++;
    }
    return iLen;
}
