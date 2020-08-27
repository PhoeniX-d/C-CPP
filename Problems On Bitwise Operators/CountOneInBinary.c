/*
*   Program to count one's in Binary representation of enterd number
*/
#include<stdio.h>
#define MAXLEN      32

typedef unsigned int UINT;

int CountOne(UINT);

int main()
{
    UINT uNum = 0;
    int iRet = 0;
    printf("Enter the number\n");
    scanf("%lu", &uNum);
    iRet = CountOne(uNum);
    printf("Output:\n%d", iRet);
    return 0;
}
///////////////////////////////////////////////////////////////////////
//
//  Name        :CountOne
//  Input       :UINT
//  Returns     :int
//  Description :count one's in Binary representation of enterd number
//  Author      :Pranav Choudhary
//  Date        :27 Aug 2020
//
///////////////////////////////////////////////////////////////////////
int CountOne(UINT uNum)
{
    int iCnt = 0;
    while(uNum != 0)
    {
        if(uNum % 2 == 1)
        {
            iCnt++;
        }
        uNum = uNum / 2;
    }
    return iCnt;
}
