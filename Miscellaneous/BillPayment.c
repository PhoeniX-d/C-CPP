/*
*   Program to calculate bill discount according to the amount
*/
#include<stdio.h>

double CalculateBill(int);

int main()
{
    int iAmount = 0;
    double dBill = 0.0;
    printf("Enter the amount\n");
    scanf("%d", &iAmount);
    dBill = CalculateBill(iAmount);
    printf("Your Bill amount with discount  = %g\n", dBill);
    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//  Name        :CalculateBill
//  Input       :int
//  Returns     :double
//  Description :Calculates Bill with discount
//  Author      :Pranav Choudhary
//  Date        : 20 August 2020
//
//////////////////////////////////////////////////////////////////////
double CalculateBill(int iAmount)
{
    double dBill = 0.0;
    if(iAmount < 0)
        iAmount = -iAmount;
    
    if(iAmount > 0 && iAmount <= 500)
    {
        dBill = iAmount;
    }
    else if(iAmount > 500 && iAmount <= 1500)
    {
        dBill = iAmount - (10.0 / 100) * iAmount;
    }
    else if(iAmount > 1500)
    {
        dBill = iAmount - (15.0 / 100) * iAmount;
    }
    return dBill;
}