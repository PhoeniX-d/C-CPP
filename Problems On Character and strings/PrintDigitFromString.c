/*
*   Program to display digits form entered string
*/
#include<stdio.h>
#define MAXLEN      30

void PrintDigit(const char *);

int main()
{
    char cArr[MAXLEN] = {'\0'};

    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);
    
    printf("OutPut:\n");
    PrintDigit(cArr);
    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//  Name        :PrintDigit
//  Input       :const char*
//  Returns     :void
//  Description :display digits form entered string
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
//////////////////////////////////////////////////////////////////////
void PrintDigit(char* cSrc)
{
    if(NULL == cSrc)
	{
		printf("Invalid Input\n");
	}
	while(*cSrc !='\0')
	{
		if((*cSrc >= '0') && (*cSrc <= '9'))
		{
            printf("%c", *cSrc);
        }
		cSrc++;
	}
}
