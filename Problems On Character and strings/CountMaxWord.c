/*
*
*      Write a program which accept string from user and return length of
*      largest word.
*      Input : “Welcom To C Programming Language”
*      Output : 11
*/

#include<stdio.h>
#define IN     1       
#define OUT    0

int LargestWord(const char *);

int main()
{
    char cArr[30] = {'\0'};
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
    int iMax[10] = {0} ,STATE = IN ,i = 0 ,iLargest = 0;

    if(cStr == NULL)
    {
        printf("Invalid Input\n");
        return -1;
    }

    while(*cStr != '\0' )      
    {
        if((*cStr == ' ') || (*cStr == '\t') || (*cStr == '\n'))
        {
            STATE = OUT;
        }
        else if( STATE == OUT )
        {    
            STATE = IN;
            i++;
            iMax[i]++;
        }
        else
        {
            iMax[i]++;
        }
        cStr++;
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d ", iMax[i]);
    }
    printf("\n");
    iLargest = iMax[1];
    for(i = 0; i < 10; i++)
    {   
        if( iMax[i] > iLargest )
        {
            iLargest = iMax[i];
        }
    }
    return iLargest;    
}