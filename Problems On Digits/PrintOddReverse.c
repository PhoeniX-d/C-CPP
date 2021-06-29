/*
*   Program to print odd digits in reverse of number
*/

#include<stdio.h>

void DisplayOddRev(long int);

int main()
{
    long int lNo = 0;
    printf("%d\n", sizeof(lNo));
    printf("Enter the number\n");
	scanf("%ld", &lNo);
    DisplayOddRev(lNo);
    return 0;
}
///////////////////////////////////////////////////////////////
//
//  Name        :CountDig
//  Input       :long int
//  Returns     :void
//  Desription  :print odd digits in reverse of number
//  Author      :Pranav P. Choudhary
//  Date        :15 August 2020
//
///////////////////////////////////////////////////////////////
void DisplayOddRev(
                        long int lNo
                    )
{
    int iDigit = 0;
    long lRev = 0L;
    if(lNo < 0)
        lNo = -lNo;
    while(lNo != 0)
    {
        iDigit = lNo % 10;
        if(iDigit % 2 != 0)
        {
            lRev = lRev * 10 + iDigit;
        }
        lNo = lNo / 10;
    }
    printf("%ld", lRev);
}