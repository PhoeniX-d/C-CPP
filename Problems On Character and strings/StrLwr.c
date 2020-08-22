/*
*   Program to converts lower case of entered string
*/
#include<stdio.h>
#define MAXLEN      30

void StrLow(const char *);

int main()
{
    char cArr[MAXLEN] = {'\0'};

    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    printf("Entered String:\t%s\n", cArr);
    StrLow(cArr);
    printf("Output String:\t%s\n", cArr);
    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//  Name        :StrLow
//  Input       :const char*
//  Returns     :void
//  Description :converts lower case of entered string
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrLow(char* cSrc)
{
    if(NULL == cSrc)
	{
		printf("Invalid Input\n");
	}
	while(*cSrc !='\0')
	{
		if((*cSrc >= 'A') && (*cSrc <= 'Z'))
		{
			*cSrc = *cSrc + 32;
		}
		cSrc++;
	}
}