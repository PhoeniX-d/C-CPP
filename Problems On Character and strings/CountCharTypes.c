/*
*   Program in C to count total number of alphabets,
*   digits and special characters in a string
*/
#include<stdio.h>
#define MAXLEN      30
#define ERROR       -1
#define IN           1
#define OUT          0

void CharsCnt(const char *);

int main()
{
    char cArr[MAXLEN] = {'\0'};

    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    CharsCnt(cArr);
    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//  Name        :CharsCnt
//  Input       :const char *
//  Returns     :void
//  Description :count total number of alphabets,
//               digits and special characters in a string
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
//////////////////////////////////////////////////////////////////////
void CharsCnt(const char *cSrc)
{
    int iA = 0, iSp = 0, iD = 0, iW = 0, iState = OUT;
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
			iW++;
		}
        if(*cSrc >= 'A' && *cSrc <= 'Z' || *cSrc >= 'a' && *cSrc <= 'z')
        {
            iA++;
        }
        else if(*cSrc >= '0' && *cSrc <= '9')
        {
            iD++;
        }
        else
        {
            iSp++;
        }       
        cSrc++;
    }
    printf("\nTotal Alphabets:\t%d\n", iA);
    printf("Total Digits :\t % d\n", iD);
    printf("Total Special symbols:\t%d\n", iSp);
    printf("Total Words:\t%d\n", iW);
}