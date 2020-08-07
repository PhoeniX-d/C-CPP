/* Program to print even factorial of a number */

#include<stdio.h>

long EvenFactorial(int);

int main()
{
    int iNo = 0;
    long lFact = 0L;
    printf("Enter the Number\n");
    scanf("%d", &iNo);
    lFact = EvenFactorial(iNo);
    printf("Even Factorial of %d is %ld", iNo, lFact);

    return 0;
}
///////////////////////////////////////////////////////////////
//
//  Name        :EvenFactorial
//  Input       :int
//  Returns     :long
//  Desription  :computes even factorial of number and returns it
//  Author      :Pranav P. Choudhary
//  Date        :7 August 2020
//
///////////////////////////////////////////////////////////////
long EvenFactorial(
                int iNo
                )
{
    long lFact = 1L;
    iNo = (iNo < 0) ? -iNo : iNo;
    while(iNo != 0)
    {
        if(iNo % 2 == 0)
        {
            lFact = lFact * iNo;
        }
        iNo--;
    }
    return lFact;
}