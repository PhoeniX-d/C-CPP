/* Program to print Odd factorial of a number */

#include<stdio.h>

long OddFactorial(int);

int main()
{
    int iNo = 0;
    long lFact = 0L;
    printf("Enter the Number\n");
    scanf("%d", &iNo);
    lFact = OddFactorial(iNo);
    printf("Odd Factorial of %d is %ld", iNo, lFact);

    return 0;
}
///////////////////////////////////////////////////////////////
//
//  Name        :OddFactorial
//  Input       :int
//  Returns     :long
//  Desription  :computes Odd factorial of number and returns it
//  Author      :Pranav P. Choudhary
//  Date        :7 August 2020
//
///////////////////////////////////////////////////////////////
long OddFactorial(
                int iNo
                )
{
    long lFact = 1L;
    iNo = (iNo < 0) ? -iNo : iNo;
    while(iNo != 0)
    {
        if(iNo % 2 != 0)
        {
            lFact = lFact * iNo;
        }
        iNo--;
    }
    return lFact;
}