/*
*   Program to print frequency of even and odd digits in a number
*/
#include<stdio.h>

void FreqEvenOdd(long);

int main()
{
    long lNum = 0;
    printf("Enter the number\n");
    scanf("%ld", &lNum);
    FreqEvenOdd(lNum);
    return 0;
}

/////////////////////////////////////////////////////////////
//
//	Name		:FreqEvenOdd
//	Input		:long
//	Returns		:void
//	Description	:count frequency of even nd odd digits
//	Author		:Pranav Choudhary
//	Date		:13 August 2020
//
/////////////////////////////////////////////////////////////
void FreqEvenOdd(
                    long lNum
                )
{
    int iEven = 0, iOdd = 0;
    if(lNum < 0)
        lNum = -lNum;
    if(lNum == 0)
    {
        iEven = 1;
        iOdd = 0;
    }
    while(lNum != 0)
    {
        if((lNum % 10) % 2 == 0 && (lNum % 10 != 0))
        {
            iEven++;
        }
        else
        {
            iOdd++;
        }        
        lNum = lNum / 10;
    }
    printf("Even Digits = %d\nOdd Digits = %d", iEven, iOdd);
}