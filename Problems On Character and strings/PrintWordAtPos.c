/*
*   Write a program which accept sentence from user and position from user and
*   print the word at that position.
*   Input : is my he she 3 Output : he
*/
#include<stdio.h>

#define MAXLEN      30
#define ERROR       -1
#define IN           1
#define OUT          0

void WordAtPos(char *, int);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    int iN = 0;
    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);
    printf("Enter the word pos\n");
    scanf(" %d", &iN);

    WordAtPos(cArr, iN);
    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//  Name        :WordAtPos
//  Input       :char *, int
//  Returns     :void
//  Description :print the word at that position
//  Author      :Pranav Choudhary
//  Date        :23 August 2020
//
//////////////////////////////////////////////////////////////////////
void WordAtPos(const char *cSrc, int iPos)
{
    int iCnt = 1, iState = OUT;
    char *cWord = cSrc;
    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
        return;
    }
    /* way 1
    while (*cSrc != '\0')
    {
        if(*cSrc == ' ' || *cSrc == '\t')
        {
            iCnt++;
        }
        else if(iCnt == iPos) 
        {   
            while(*cSrc != '\0' && *cSrc != ' ' && *cSrc != '\t')
            {
                printf("%c", *cSrc);
                cSrc++;
            }
            break;
        }
        cSrc++;
    }
    */

    while( *cSrc != '\0')
    {
        if(*cSrc == ' ' || *cSrc == '\n' || *cSrc == '\t')
		{
            iState = OUT;
        }
		else if(iState == OUT)
		{	
			iState = IN;
			iPos--;
            if(iPos == 0)
            {
                cWord = cSrc;
                break;
            }
		}
        cSrc++;
    }
    if(*cSrc == '\0')
    {
        printf("Invalid\n");
    }
    else
    {
        while(*cWord != '\0' && *cWord != ' ' && *cWord != '\t')
        {
            printf("%c", *cWord);
            cWord++;
        }
    }
    
}