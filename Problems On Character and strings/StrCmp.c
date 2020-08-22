/*
*   Program to compare 2 strings
*/
#include<stdio.h>
#define ERROR     -999
#define MAXLEN      30

int StrCmp(const char *, const char*);

int main()
{
    char cStr1[MAXLEN] = {'\0'};
    char cStr2[MAXLEN] = {'\0'};
    int iRet = 0;

    printf("Enter the string 1\n"); 
    scanf("%[^\n]", cStr1);

    printf("Enter the string 2\n"); 
    scanf(" %[^\n]", cStr2);

    iRet = StrCmp(cStr1, cStr2);

    if(iRet == 0)
    {
        printf("Strings are equal\n");
    }
    else
    {
        printf("Strings are unequal\n");
    }
    
    return 0;
}

////////////////////////////////////////////////////////////
//
//  Name        :StrCmp
//  Input       :const char*, const char*
//  Returns     :int
//  Description :compare 2 strings
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
////////////////////////////////////////////////////////////
int StrCmp(const char* cStr1, const char* cStr2)
{
    if(cStr1 == NULL || cStr2 == NULL)
    {
        printf("Invalid Input\n");
        return ERROR;
    }

    while(*cStr1 == *cStr2)
    {
        if(*cStr1 == '\0')
        {
            break;
        }
        cStr1++;
        cStr2++;
    }
    if(*cStr1 == *cStr2)
        return 0;
    else
        return *cStr1 - *cStr2;
}
