/*
*   Program to print even and odd digits in reverse of number
*/

#include<stdio.h>

void EvenOddRev(long);

int main()
{
    long lNo = 0;
    printf("%d\n", sizeof(lNo));
    printf("Enter the number\n");
	scanf("%ld", &lNo);
    EvenOddRev(lNo);
    return 0;
}
///////////////////////////////////////////////////////////////
//
//  Name        :EvenOddRev
//  Input       :long
//  Returns     :void
//  Desription  :print even and odd digits in reverse of number
//  Author      :Pranav P. Choudhary
//  Date        :15 August 2020
//
///////////////////////////////////////////////////////////////
void EvenOddRev(
                        long lNo
                    )
{
    int iDigit = 0;
    long lEvenRev = 0L, lOddRev = 0L;
    if(lNo < 0)
        lNo = -lNo;
    while(lNo != 0)
    {
        iDigit = lNo % 10;
        if(iDigit % 2 != 0)
        {
            lOddRev = lOddRev * 10 + iDigit;
        }
        else
        {
            lEvenRev = lEvenRev * 10 + iDigit;
        }
        lNo = lNo / 10;
    }
    printf("Even : %ld\n", lEvenRev);
    printf("Odd : %ld", lOddRev);
}