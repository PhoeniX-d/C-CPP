/*
*   Write a program which accept sentence from user and print number of small
*   letters, capital letters and digits from that sentence.
*
*   Input : abcDE 5Glm1 O Output : Small:5 Capital: 4 Digits: 2 
*/
#include<stdio.h>
#define MAXLEN      30
#define ERROR       -1

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
//  Description :print number of small
//               letters, capital letters and digits from that sentence
//  Author      :Pranav Choudhary
//  Date        :23 August 2020
//
//////////////////////////////////////////////////////////////////////
void CharsCnt(const char *cSrc)
{
    int iAl = 0, iAc = 0, iD = 0;
    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
        return;
    }
    while (*cSrc != '\0')
    {
        if(*cSrc >= 'a' && *cSrc <= 'z')
        {
            iAl++;
        }
        else if(*cSrc >= 'A' && *cSrc <= 'Z')
        {
            iAc++;
        }
        else if(*cSrc >= '0' && *cSrc <= '9')
        {
            iD++;
        }      
        cSrc++;
    }
    printf("\nSmall:\t%5d\n", iAl);
    printf("Capital:\t%5d\n", iAc);
    printf("Digits:\t%5d\n", iD);
}