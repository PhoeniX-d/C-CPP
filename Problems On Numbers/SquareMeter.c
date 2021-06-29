/* Program to convert square feet into square meter */
#include<stdio.h>
#define SFEET  0.0929
double SquareMeter(float);

int main()
{
    float fSqFeet = 0.0f;
    double dSqM = 0.0;
    printf("Enter Square feet\n");
    scanf("%f", &fSqFeet);
    dSqM = SquareMeter(fSqFeet);
    printf("Square Meter = %lf", dSqM);
}
////////////////////////////////////////////////////////////////
//
//	Name		:SquareMeter
//	Input		:float
//	Returns		:double
//	Description	:Convert SquareFeet to SquareMeter
//	Author		:Pranav Choudhary
//	Date		:7 August 2020
//
////////////////////////////////////////////////////////////////
double SquareMeter(float fFeet)
{
    double dRet = 0.0;
    if(fFeet < 0)
        fFeet = -fFeet;
    return SFEET * fFeet;
}
