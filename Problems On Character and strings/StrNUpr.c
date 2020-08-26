/*
*   Program to converts upper case entered string upto N
*/
#include<stdio.h>
#define MAXLEN      30

void StrNUpr(char *, int);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    int iN = 0;

    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    printf("Enter N\n");
    scanf(" %d", &iN);
    
    StrNUpr(cArr, iN);
    printf("Output String:\t%s\n", cArr);
    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//  Name        :StrNUpr
//  Input       :char*, int
//  Returns     :void
//  Description :converts upper case entered string upto N
//  Author      :Pranav Choudhary
//  Date        :24 August 2020
//
//////////////////////////////////////////////////////////////////////
void StrNUpr(char* cSrc, int iN)
{
    if(NULL == cSrc)
	{
		printf("Invalid Input\n");
	}
    if(iN < 0)
    {
        iN = -iN;
    }
	while(*cSrc !='\0' && iN != 0)
	{
		if((*cSrc >= 'a') && (*cSrc <= 'z'))
		{
			*cSrc = *cSrc - 32;
		}
		cSrc++;
        iN--;
    }
}