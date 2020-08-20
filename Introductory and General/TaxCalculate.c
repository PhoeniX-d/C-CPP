/*
*   Program to calculate Tax according to the income
*/
#include<stdio.h>

double CalculateTax(int);

int main()
{
    int iIncome = 0;
    double dTax = 0.0;
    printf("Enter the income\n");
    scanf("%d", &iIncome);
    dTax = CalculateTax(iIncome);
    printf("Your Tax income = %#G\n", dTax);
    return 0;
}
//////////////////////////////////////////////////////////////////////
//
//  Name        :CalculateTax
//  Input       :int
//  Returns     :double
//  Description :Calculates Tax acording to income
//  Author      :Pranav Choudhary
//  Date        : 20 August 2020
//
//////////////////////////////////////////////////////////////////////
double CalculateTax(int iIncome)
{
    double dTax = 0.0, dTemp1 = 0.0, dTemp2 = 0.0, dTemp3 = 0.0;
    if(iIncome < 0)
        iIncome = -iIncome;
    
    if(iIncome > 0 && iIncome < 500000)
    {
        dTax = 0.0;
    }
    else if(iIncome >= 500000 && iIncome < 1000000)
    {
        dTemp1 = iIncome - 500000;
        dTax = dTemp1 * 0.1;
    }
    else if(iIncome >= 1000000 && iIncome < 2000000)
    {
        dTemp1 = iIncome - 1000000;
        dTemp2 = iIncome - dTemp1 - 500000;
        dTax = (dTemp1 * 0.2) + (dTemp2 * 0.1);
    }
    else if(iIncome >= 2000000)
    {
        dTemp1 = iIncome - 2000000;
        dTemp2 = iIncome - dTemp1 - 1000000;
        dTemp3 = dTemp2 - 500000;
        dTax = (dTemp1 * 0.3) + (dTemp2 * 0.2) + (dTemp3 * 0.1);
    }
    return dTax;
}