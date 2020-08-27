/*
*   Program to remove extra spaces and copy string to Destination
*/
#include<stdio.h>
#define MAXLEN      30

void StrTrimCpyX(const char *, char *);

int main()
{
    char cSrc[MAXLEN] = {'\0'};
    char cDest[MAXLEN] = {'\0'};

    printf("Enter the string\n"); 
    scanf("%[^\n]", cSrc);

    StrTrimCpyX(cSrc, cDest);
    printf("Output String:\n%s\n", cDest);
    return 0;
}

////////////////////////////////////////////////////////////
//
//  Name        :StrTrimCpyX
//  Input       :const char*, char*
//  Returns     :void
//  Description :function that removes extra spaces
//  Author      :Pranav Choudhary
//  Date        :27 August 2020
//
////////////////////////////////////////////////////////////
void StrTrimCpyX(const char* cSrc, char* cDest)
{
    if(cSrc == NULL || cDest == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    int iSpaces = 0;
    while(*cSrc != '\0')
    {
        if(*cSrc == ' ')
		{
			while((*cSrc == ' ' || *cSrc == '\t') && (*cSrc != '\0'))
			{
				cSrc++;
			}
		}
		else
		{
			while(*cSrc != ' ' && *cSrc != '\0')
			{
				*cDest=*cSrc;
				cSrc++;
				cDest++;
			}
			*cDest=*cSrc;
			cDest++;		
		}
    }
}
