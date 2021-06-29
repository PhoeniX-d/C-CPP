/*
*   Program to compute space in the entered string
*/
#include<stdio.h>
#define MAXLEN      30

int CntSpace(const char *);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    int iRet = 0;
    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    printf("Entered String:\t%s\n", cArr);
    iRet = CntSpace(cArr);
    printf("No. of spaces :\t%d\n", iRet);
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CntSpace
//  Input       :const char*
//  Returns     :int
//  Description :compute space in the entered string
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
//////////////////////////////////////////////////////////////////////
int CntSpace(const char *cSrc)
{
    int iCnt = 0;
    while(*cSrc != '\0')
    {
        if(*cSrc == 32)
        {
            iCnt++;
        }
        cSrc++;
    }
    return iCnt;
}
