/* Program to print Power of a number */

#include<stdio.h>

double Power(int, int);

int main()
{
    int iBase = 0, iRaised = 0;
    double dPow = 0;
    printf("Enter the Base\n");
    scanf("%d", &iBase);
    printf("Enter the Power\n");
    scanf("%d", &iRaised);
    dPow = Power(iBase, iRaised);
    printf("%d Power of %d is %G", iRaised, iBase, dPow);

    return 0;
}
///////////////////////////////////////////////////////////////
//
//  Name        :Power
//  Input       :int, int
//  Returns     :long
//  Desription  :computes power of a number
//  Author      :Pranav P. Choudhary
//  Date        :1 August 2020
//
///////////////////////////////////////////////////////////////
double Power(
                int iBase,
                int iRaised
                )
{
    int i = 0;
    double dPow = 1;
    if(iRaised > 0)
    {
        for (i = 1; i <= iRaised; i++)
        {
            dPow = dPow * iBase;
        }
    }
    else if(iRaised < 0)
    {
        for (i = 1; i <=(-iRaised); i++)
        {
            dPow = dPow / iBase;
        }
    }

    /* alternate way
    for(i = 1; i <= abs(iRaised); i++)
    {
        dPow = dPow * iBase;
    }
    if(iRaised < 0)
    {
        dPow= 1 / dPow;
    }
    */
    return dPow;
}