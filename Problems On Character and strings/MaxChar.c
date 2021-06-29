/*
*   Program  in C to find maximum occurring character in a string
*/
#include<stdio.h>
#define MAXLEN       50
#define ERROR        -1
#define MAX_CHAR    127

void MaxChar(const char *);

int main()
{
    char cArr[MAXLEN] = {'\0'};

    printf("Enter the string\n"); 
    scanf("%[^\n]", cArr);

    MaxChar(cArr);
    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//  Name        :MaxChar
//  Input       :const char *
//  Returns     :void
//  Description :find maximum occurring character in a string
//  Author      :Pranav Choudhary
//  Date        :22 August 2020
//
//////////////////////////////////////////////////////////////////////
void MaxChar(const char *cSrc)
{
    int iChars[MAX_CHAR] = {0}, i = 0, iMax = 0;
    char ch = '\0';
    if(NULL == cSrc)
    {
        printf("Invalid Input\n");
        return;
    }
    while (*cSrc != '\0')
    {
        iChars[*cSrc]++;
        cSrc++;
    }
    iMax = iChars[0];
    for (i = 0; i < MAX_CHAR; i++)
    {
        if(i != 32)
        {
            if(iMax < iChars[i])
            {
                iMax = iChars[i];
                ch = i;
            }
        }
    }

    printf("Max occuring char \'%c\' with occurance %d\n", ch, iMax);
}