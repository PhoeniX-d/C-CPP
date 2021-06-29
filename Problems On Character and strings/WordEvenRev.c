/*
*   Write a program which accept string from user and reverse words from that
*   string which are of even length.
*   Input : New HO abcd can Output : New OH dcba can 
*/
#include<stdio.h>
#define MAXLEN      30

void WordRev(char *);

int main()
{
    char cArr[MAXLEN] = {'\0'};

    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    printf("Entered String:\t%s\n", cArr);

    WordRev(cArr);

    printf("Output String:\t%s\n", cArr);
    return 0;
}

////////////////////////////////////////////////////////////////////////
//
//  Name        :WordRev
//  Input       :char*
//  Returns     :void
//  Description :reverse words from that string which are of even length
//  Author      :Pranav Choudhary
//  Date        :23 August 2020
//
////////////////////////////////////////////////////////////////////////
void WordRev(char* cSrc)
{
    if(cSrc == NULL)
    {
        printf("Invalid Input\n");
        return;
    }
    char cTemp = '\0';
    char *cStart = cSrc;
    char *cEnd = cSrc;
    int iCnt = 0;

    while(*cSrc != '\0')
    {
        cEnd = cStart;
        while(*cEnd != ' ' && *cEnd != '\t' && *cEnd != '\0')
        {
            iCnt++;
            cEnd++;
        }
        cSrc = cEnd;
        if(iCnt % 2 == 0)
        {
            cEnd--;
            while(cStart < cEnd)
            {
                cTemp = *cStart;
                *cStart = *cEnd;
                *cEnd = cTemp;
                
                cEnd--;
                cStart++;
            }
        }
        cStart = cSrc + 1;
        iCnt = 0;
    }    
}
