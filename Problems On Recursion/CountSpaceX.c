/*
*   Write a recursive program which accept string from user and count white
*   spaces.
*   Input : HE llo WOr lD
*   Output : 3 
*/

#include<stdio.h>
#define MAXLEN      30

int CountSpaceX(char *);

int main()
{
    char sArr[MAXLEN] = {'\0'};
    int iRet = 0;
    printf("\nEnter the string\t\t\t:");
    scanf("%[^\n]", sArr);
    iRet = CountSpaceX(sArr);
    printf("Total white spaces in string are\t:%d\n", iRet);

    return 0;
}

///////////////////////////////////////////////////////////////
//
//  Name        :CountSpaceX
//  Input       :char*
//  Returns     :int
//  Description :counts white spaces in string using recursion
//  Author      :Pranav Choudhary
//  Date        :7 Sept 2020
//
///////////////////////////////////////////////////////////////
int CountSpaceX(char *cStr)
{
    static int iCnt = 0;
    if(*cStr != '\0')
    {
        if(*cStr == ' ')
        {
            iCnt++;
        }
        cStr++;
        CountSpaceX(cStr);
    }
    return iCnt;
}