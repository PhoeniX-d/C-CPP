/*
*   Program to calculate length of string using recursion
*/

#include<stdio.h>
#define MAXLEN      30
int StrLenX(char *);

int main()
{
    char sArr[MAXLEN] = {'\0'};
    int iRet = 0;
    printf("\nEnter the string\t:");
    scanf("%[^\n]", sArr);
    iRet = StrLenX(sArr);
    printf("Length of string is\t:%d\n", iRet);

    return 0;
}

///////////////////////////////////////////////////////////
//
//  Name        :StrLenX
//  Input       :char*
//  Returns     :int
//  Description :calculates length of string
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
int StrLenX(char *cStr)
{
    static int iCnt = 0;
    if(NULL == cStr)
    {
        return -1;
    }
    if(*cStr != '\0')
    {
        iCnt++;
        cStr++;
        StrLenX(cStr);
    }
    return iCnt;
}