/*
*   Program to converts upper case entered string
*/
#include<stdio.h>
#define MAXLEN      30

void StrUpr(const char *);

int main()
{
    char cArr[MAXLEN] = {'\0'};

    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    printf("Entered String:\t%s\n", cArr);
    StrUpr(cArr);
    printf("Output String:\t%s\n", cArr);
    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//  Name        :StrUpr
//  Input       :const char*
//  Returns     :void
//  Description :converts upper case entered string
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrUpr(char* cSrc)
{
    if(NULL == cSrc)
	{
		printf("Invalid Input\n");
	}
	while(*cSrc !='\0')
	{
		if((*cSrc >= 'a') && (*cSrc <= 'z'))
		{
			*cSrc = *cSrc - 32;
		}
		cSrc++;
	}
}