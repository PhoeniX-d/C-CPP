/*
*   Program to count Zero's in Binary representation of enterd number
*/
#include<stdio.h>
typedef unsigned int UINT;

int CountZero(UINT);

int main()
{
    UINT uNum = 0;
    int iRet = 0;
    printf("Enter the number\n");
    scanf("%u", &uNum);
   
    iRet = CountZero(uNum);
    printf("Output:\n%d", iRet);

    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//  Name        :CountZero
//  Input       :UINT
//  Returns     :int
//  Description :count Zero's in Binary representation of enterd number
//  Author      :Pranav Choudhary
//  Date        :27 Aug 2020
//
//////////////////////////////////////////////////////////////////////
int CountZero(UINT uNum)
{
    int iCnt = 0;
    while(uNum != 0)
    {
        if(uNum % 2 == 0)
        {
            iCnt++;
        }
        uNum = uNum / 2;
    }
    return iCnt;
}
