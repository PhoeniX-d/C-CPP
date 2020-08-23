/*
*   Write a program which accept sentence from user and print last word from
*   that sentence.
*   
*   Input : In my company Output : company 
*/

#include<stdio.h>
#define MAXLEN      50

void LastWord(const char *);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    int iRet = 0;
    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    LastWord(cArr);
    return 0;
}
/////////////////////////////////////////////////////////////
//
//  Name        :LastWord
//  Input       :const char *
//  Returns     :void
//  Description :print last word from that sentence
//  Author      :Pranav Choudhary
//  Date        :23 August 2020
//
/////////////////////////////////////////////////////////////
void LastWord(const char *cSrc)
{
    char *cLastWord = cSrc;
    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
        return;
    }
    while(*cSrc != '\0')
    {
        if (*cSrc == ' ' || *cSrc == '\t')
        {
            cLastWord = cSrc + 1;
        }
        cSrc++;
    }
    printf("Last word :\n");
    while (*cLastWord != '\0')
    {
        printf("%c", *cLastWord);
        cLastWord++;
    }
    printf("\n");
}