/* Program to print difference between even and odd factorial of a number */

#include<stdio.h>

long DiffFactorial(int);

int main()
{
    int iNo = 0;
    long lFact = 0L;
    printf("Enter the Number\n");
    scanf("%d", &iNo);
    lFact = DiffFactorial(iNo);
    printf("Odd Factorial of %d is %ld", iNo, lFact);

    return 0;
}
/////////////////////////////////////////////////////////////////////////////
//
//  Name        :DiffFactorial
//  Input       :int
//  Returns     :long
//  Desription  :print difference between even and odd factorial of a number
//  Author      :Pranav P. Choudhary
//  Date        :7 August 2020
//
/////////////////////////////////////////////////////////////////////////////
long DiffFactorial(
                int iNo
                )
{
    long lEvenFact = 1L, lOddFact = 1L;
    iNo = (iNo < 0) ? -iNo : iNo;
    while(iNo != 0)
    {
        if(iNo % 2 == 0)
        {
            lEvenFact = lEvenFact * iNo;
        }
        else
        {
            lOddFact = lOddFact * iNo;
        }        
        iNo--;
    }
    return lEvenFact - lOddFact;
}