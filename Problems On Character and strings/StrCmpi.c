/*
*   Program to compare 2 strings case insensitive
*/
#include<stdio.h>
#define ERROR     -999
#define MAXLEN      30

int StrCmpi(const char *, const char*);

int main()
{
    char cStr1[MAXLEN] = {'\0'};
    char cStr2[MAXLEN] = {'\0'};
    int iRet = 0;

    printf("Enter the string 1\n"); 
    scanf("%[^\n]", cStr1);

    printf("Enter the string 2\n"); 
    scanf(" %[^\n]", cStr2);

    iRet = StrCmpi(cStr1, cStr2);

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
//  Name        :StrCmpi
//  Input       :const char*, const char*
//  Returns     :int
//  Description :compare 2 strings case insensitive
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
////////////////////////////////////////////////////////////
int StrCmpi(const char* cStr1, const char* cStr2)
{
    if(cStr1 == NULL || cStr2 == NULL)
    {
        printf("Invalid Input\n");
        return ERROR;
    }

    while(*cStr1 != '\0' && *cStr2 != '\0')
    {
        if((*cStr1 != *cStr2) && (*cStr1 != *cStr2 + 32) && (*cStr1 != *cStr2 - 32))
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
