/*
*
*      Write a program which accept string from user and return length of
*      largest word.
*      Input : “Welcome To C Programming Language”
*      Output : 11
*/

#include<stdio.h>
#define MAXLEN      30
#define IN           1
#define OUT          0

int LargestWord(const char *);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    int iRet = 0;
        
    printf("Enter the string :\n");
    scanf("%[^\n]s",cArr);

    iRet = LargestWord(cArr );

    if(iRet != -1)
        printf("Length of largest word in string  : \n%d",iRet);
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :LargestWord
//  Input       :const char *
//  Returns     :int
//  Description :program which accept string from user and return 
//               length of largest word
//  Author      :Pranav Choudhary
//  Date        :27 August 2020
//
//////////////////////////////////////////////////////////////////////
int LargestWord(const char *cStr)
{
    int iMax = 0 ,i = 0 ,iCnt = 0;

    if(cStr == NULL)
    {
        printf("Invalid Input\n");
        return -1;
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
			while(*cStr != ' ' && *cStr != '\0')
			{
                iCnt++;
                cStr++;
            }					
		}
        if(iCnt > iMax)
        {
            iMax = iCnt;
        }
        iCnt = 0;
        cStr++; 
    }
    return iMax;
}