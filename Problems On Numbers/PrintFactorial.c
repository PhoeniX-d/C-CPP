/* Program to print factorial of a number */

#include<stdio.h>

long Factorial(int);

int main()
{
    int iNo = 0;
    long lFact = 0L;
    printf("Enter the Number\n");
    scanf("%d", &iNo);
    lFact = Factorial(iNo);
    printf("Factorial of %d is %ld", iNo, lFact);

    return 0;
}
///////////////////////////////////////////////////////////////
//
//  Name        :Factorial
//  Input       :int
//  Returns     :long
//  Desription  :computes factorial of number and returns it
//  Author      :Pranav P. Choudhary
//  Date        :1 August 2020
//
///////////////////////////////////////////////////////////////
long Factorial(
                int iNo
                )
{
    long lFact = 1L;
    iNo = (iNo < 0) ? -iNo : iNo;
    while(iNo != 0)
    {
        lFact = lFact * iNo;
        iNo--;
    }
    return lFact;
}