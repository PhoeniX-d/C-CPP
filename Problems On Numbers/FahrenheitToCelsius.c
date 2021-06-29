/* Program to convert fahrenheit to celsius conversion */
#include<stdio.h>

double FhToCs(float);

int main()
{
    float fFah = 0.0f;
    double dCel = 0.0;
    printf("Enter the temperature in Fahrenheit\n");
    scanf("%f", &fFah);
    dCel = FhToCs(fFah);
    printf("%f Fahreinheit = %lf Celsius", fFah, dCel);
    return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:FhToCs
//	Input		:float
//	Returns		:double
//	Description	:Convert fahreinheit to Celsius
//	Author		:Pranav Choudhary
//	Date		:7 August 2020
//
////////////////////////////////////////////////////////////////
double FhToCs(float fFah)
{
    return (5.0 / 9.0) * (fFah - 32.0);
}