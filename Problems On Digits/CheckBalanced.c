/*
*   Program to check whether given number is Balanced or not
*   Balanced number = no of even and odd digits are equal
*/
#include<stdio.h>
#define TRUE     1
#define FALSE    0
typedef char BOOL;

BOOL CheckBalanced(long);

int main()
{
    long lNum = 0L;
    BOOL bRet = FALSE;
    printf("Enter the number\n");
    scanf("%ld", &lNum);
    bRet = CheckBalanced(lNum);
    if(bRet == TRUE)
        printf("%ld is Balanced number\n", lNum);
    else
        printf("%ld is not Balnced number\n", lNum);

    return 0;
}
///////////////////////////////////////////////////////////////
//
//	Name		:CheckBalanced
//	Input		:long
//	Returns		:BOOL
//	Description	:check whether given number is Balanced or not
//	Author		:Pranav Choudhary
//	Date		:13 August 2020
//
///////////////////////////////////////////////////////////////
BOOL CheckBalanced(
                        long lNum
                    )
{
    int iCnt = 0;
    if(lNum < 0)
        lNum = -lNum;
    if(lNum == 0)
        iCnt++;

    while(lNum > 0)
    {
        if((lNum % 10) % 2 == 0)
            iCnt++;
        else
            iCnt--;
        lNum = lNum / 10;
    }
    if(iCnt == 0)
        return TRUE;
    else
        return FALSE;
}