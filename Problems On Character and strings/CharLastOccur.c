/*
*   Program to return position of last occurance of entered 
*   char in the entered string
*/
#include<stdio.h>
#define MAXLEN      30

int LastOccur(const char *, char);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    char cAlp = '\0';
    int iRet = 0;

    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    printf("Enter the character\n");
    scanf(" %c", &cAlp);

    iRet = LastOccur(cArr, cAlp);
    if(iRet != -1)
    {
        printf("last Occurance of \'%c\' is at %d index\n", cAlp, iRet);
    }
    else
    {
        printf("\'%c\' is not present in enterd string\n", cAlp);
    }
        
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :LastOccur
//  Input       :const char*, char
//  Returns     :int
//  Description :return position of last occurance of entered 
//               char in the entered string
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
//////////////////////////////////////////////////////////////////////
int LastOccur(const char *cSrc, char ch)
{
    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return -1;
    }
    int iCnt = 0;
    while(*cSrc != '\0')
    {
        iCnt++;
        cSrc++;
    }
    cSrc--;
    while(iCnt != -1)
    {
        if(*cSrc == ch)
        {
            iCnt--;
            break;
        }
        iCnt--;
        cSrc--;
    }
    if(iCnt == -1)
        return -1;
    else
        return iCnt;
}
