/*
*   Write a recursive program which accept string from user and count number
*   of small characters.
*   Input : HElloWOrlD
*   Output : 5 
*/

#include<stdio.h>
#define MAXLEN      30

int CountLwr(char *);

int main()
{
    char sArr[MAXLEN] = {'\0'};
    int iRet = 0;
    printf("\nEnter the string\t\t\t:");
    scanf("%[^\n]", sArr);
    iRet = CountLwr(sArr);
    printf("Total lower case character in string\t:%d\n", iRet);
    return 0;
}

//////////////////////////////////////////////////
//
//  Name        :CountLwr
//  Input       :char*
//  Returns     :int
//  Description :count number of small characters
//  Author      :Pranav Choudhary
//  Date        :7 Sept 2020
//
//////////////////////////////////////////////////
int CountLwr(char *cStr)
{
    static int iCnt = 0;
    if(*cStr != '\0')
    {
        if(*cStr >= 'a' && *cStr <= 'z')
        {
            iCnt++;
        }
        cStr++;
        CountLwr(cStr);
    }
    return iCnt;
}
