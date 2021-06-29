/*
*   Write a program which accept sentence from user and print number of words
*   of even and odd length from that sentence.
*   
*   Input : In my company Output : Even: 2 Odd:1 
*/
#include<stdio.h>
#define MAXLEN      50

void WordCnt(const char *);

int main()
{
    char cArr[MAXLEN] = {'\0'};
    int iRet = 0;
    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    WordCnt(cArr);
    return 0;
}
/////////////////////////////////////////////////////////////
//
//  Name        :WordCnt
//  Input       :const char *
//  Returns     :void
//  Description :print number of words of even and odd length
//               from that sentence
//  Author      :Pranav Choudhary
//  Date        :23 August 2020
//
/////////////////////////////////////////////////////////////
void WordCnt(const char *cSrc)
{
    int iEcnt = 0, iOcnt = 0, iCnt = 0;

    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
        return;
    }
    /* way 1
    while (*cSrc != '\0')
    {
        iCnt++;
        if(*cSrc == ' ' || *cSrc == '\t' || *(cSrc + 1)  == '\0')
        {
            iCnt--;
            if(iCnt % 2 == 0)
            {
                iEcnt++;
            }
            else 
            {
                iOcnt++;
            }
            iCnt = 0;
        }
        cSrc++;
    }
    */
   
    /* way 2 */ 
    while (*cSrc != '\0')
    {
        while(*cSrc != ' ' && *cSrc != '\t' && *cSrc  != '\0')
        {
            iCnt++;
            cSrc++;
        }
        if(iCnt % 2 == 0)
        {
            iEcnt++;
            iCnt = 0;
        }
        else 
        {
            iOcnt++;
            iCnt = 0;
        }        
        cSrc++;
    }
    printf("\nEven:%5d", iEcnt);
    printf("\nOdd:%5d", iOcnt);
}