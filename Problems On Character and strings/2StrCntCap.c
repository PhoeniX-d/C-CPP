/*
*   Program to compute length of 2 strings
*/
#include<stdio.h>
#define MAXLEN      30

void CountUpr(const char *, const char*);

int main()
{
    char cArr1[MAXLEN] = {'\0'};
    char cArr2[MAXLEN] = {'\0'};
    
    printf("Enter the 1st string\n"); 
    scanf("%[^\n]", cArr1);

    printf("Enter the 2nd string\n"); 
    scanf(" %[^\n]", cArr2);

    CountUpr(cArr1, cArr2);
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :CountUpr
//  Input       :const char*, const char*
//  Returns     :void
//  Description :computes length of entered 2 strings
//  Author      :Pranav Choudhary
//  Date        :28 August 2020
//
//////////////////////////////////////////////////////////////////////
void CountUpr(const char *cStr1, const char* cStr2)
{
    if(cStr1 == NULL || NULL == cStr2)
    {
        printf("Invalid Input\n");
        return;
    }
    int iUpr1 = 0, iUpr2 = 0;
    const char *cTemp = cStr1;
    while(*cStr1 != '\0')
    {
        if(*cStr1 >= 'A' && *cStr1 <= 'Z')
            iUpr1++;
        cStr1++;
    }

    printf("Capital Count : %s\n%d\n", cTemp, iUpr1);
    cTemp = cStr2;

    while(*cStr2 != '\0')
    {
        if(*cStr2 >= 'A' && *cStr2 <= 'Z')
            iUpr2++;
        cStr2++;
    } 
    printf("Capital Count : %s\n%d\n", cTemp, iUpr2);
}
