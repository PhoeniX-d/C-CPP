/*
*   Program to concate two strings
*/
#include<stdio.h>
#define MAXLEN      20

void StrCat(char *, char*);

int main()
{
    char cStr1[MAXLEN * 2] = {'\0'};
    char cStr2[MAXLEN] = {'\0'};

    printf("Enter the 1st string\n"); 
    scanf("%[^\n]", cStr1);

    printf("Enter the 2nd string\n"); 
    scanf(" %[^\n]", cStr2);

    StrCat(cStr1, cStr2);

    printf("Output String:\t%s\n", cStr1);
    return 0;
}

////////////////////////////////////////////////////////////
//
//  Name        :StrCat
//  Input       :char*, char*
//  Returns     :void
//  Description :concate two strings
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
////////////////////////////////////////////////////////////
void StrCat(char* cStr1, char* cStr2)
{
    if(cStr1 == NULL || cStr2 == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    while(*cStr1 != '\0')
    {
        cStr1++;
    }
    while(*cStr2 != '\0')
    {
        *cStr1 = *cStr2;
        cStr2++;
        cStr1++;
    }
    *cStr1 = '\0';
}
