/*  
*   Program which accept string from user and replace each
*   occurrence of first character of each word into capital case.
*      
*   Input : “marvellous infosystems by Piyush khairnar”
*   Output : “Marvellous Infosystems By Piyush Khairnar”
*/
#include<stdio.h>
#define MAXLEN      30
#define ERROR       -1
#define IN           1
#define OUT          0

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
void FirstCharCap(char *cSrc)
{
    int iState = OUT;
    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
        return;
    }
    while (*cSrc != '\0')
    {
        if(*cSrc == ' ' || *cSrc == '\n' || *cSrc == '\t')
		{
            iState = OUT;
        }
		else if(iState == OUT)
		{	
			iState = IN;
			if(*cSrc >= 'a' && *cSrc <= 'z')
            {
                *cSrc = *cSrc - 32;
            }
		}
        cSrc++;
    }
}
