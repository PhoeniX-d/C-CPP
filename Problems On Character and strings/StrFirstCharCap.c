/*  
*   Program which accept string from user and replace each
*   occurrence of first character of each word into capital case.
*      
*   Input : "welcome to the c programming Language"
*   Output : "Welcome To The C Programming Language"
*/
#include<stdio.h>
#define MAXLEN      30
#define ERROR       -1

void FirstCharCap(char *);

int main()
{
    char cArr[MAXLEN] = {'\0'};

    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    FirstCharCap(cArr);
    printf("Output:\n%s\n", cArr);

    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//  Name        :FirstCharCap
//  Input       :char *
//  Returns     :void
//  Description :replace each occurrence of first character of 
//               each word into capital case
//  Author      :Pranav Choudhary
//  Date        :27 August 2020
//
//////////////////////////////////////////////////////////////////////
void FirstCharCap(char *cStr)
{
    if(NULL == cStr)
    {
        printf("Invalid Input\n");
        return;
    }

    while(*cStr != '\0')
    {
        if(*cStr == ' ')
		{
			while((*cStr == ' ' || *cStr == '\t') && (*cStr != '\0'))
			{
				cStr++;
			}
		}
		else
		{
            if(*cStr >= 'a' && *cStr <= 'z')
            {
                *cStr = *cStr - 32;
            }
			while(*cStr != ' ' && *cStr != '\0')
			{
                cStr++;
            }
        }
        cStr++; 
    }
}
