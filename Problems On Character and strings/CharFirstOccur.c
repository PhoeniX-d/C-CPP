/*
*   Program to return position of first occurance of entered 
*   char in the entered string
*/
#include<stdio.h>
#define MAXLEN      30

int FirstOccur(const char *, char);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    char cAlp = '\0';
    int iRet = 0;

    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    printf("Enter the character\n");
    scanf(" %c", &cAlp);

    iRet = FirstOccur(cArr, cAlp);
    if(iRet != -1)
    {
        printf("First Occurance of \'%c\' is at %d index\n", cAlp, iRet);
    }
    else
    {
        printf("\'%c\' is not present in enterd string\n", cAlp);
    }
        
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :FirstOccur
//  Input       :const char*, char
//  Returns     :int
//  Description :return position of first occurance of entered 
//               char in the entered string
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
//////////////////////////////////////////////////////////////////////
int FirstOccur(const char *cSrc, char ch)
{
    int iCnt = -1;
    while(*cSrc != '\0')
    {
        if(*cSrc == ch)
        {
            iCnt++;
            break;
        }
        iCnt++;
        cSrc++;
    }
    if(*cSrc == '\0')
        return -1;
    else
        return iCnt;
}
