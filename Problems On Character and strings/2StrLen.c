/*
*   Program to compute length of 2 strings
*/
#include<stdio.h>
#define MAXLEN      30

void StrLen(const char *, const char*);

int main()
{
    char cArr1[MAXLEN] = {'\0'};
    char cArr2[MAXLEN] = {'\0'};
    
    printf("Enter the 1st string\n"); 
    scanf("%[^\n]", cArr1);

    printf("Enter the 2nd string\n"); 
    scanf(" %[^\n]", cArr2);

    StrLen(cArr1, cArr2);
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :StrLen
//  Input       :const char*, const char*
//  Returns     :void
//  Description :computes length of entered 2 strings
//  Author      :Pranav Choudhary
//  Date        :28 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrLen(const char *cStr1, const char* cStr2)
{
    if(cStr1 == NULL || NULL == cStr2)
    {
        printf("Invalid Input\n");
        return;
    }
    int iLen1 = 0, iLen2 = 0;
    const char *cTemp = cStr1;
    while(*cStr1 != '\0')
    {
        iLen1++;
        cStr1++;
    }
    printf("Length of : %s\n%d\n", cTemp, iLen1);
    cTemp = cStr2;
    while(*cStr2 != '\0')
    {
        iLen2++;
        cStr2++;
    }   
    printf("Length of : %s\n%d\n", cTemp, iLen2);
}
