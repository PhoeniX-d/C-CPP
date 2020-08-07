/* Program to calculate area of a circle */
// headers
#include<stdio.h>
#define PI 3.142

double CircleArea(float);

int main()
{
    float fRad = 0.0f;
    double dArea = 0.0;
    printf("Enter the radius of a cirlce\n");
    scanf("%f", &fRad);
    dArea = CircleArea(fRad);
    printf("Area of circle with radius %G = %G", fRad, dArea);
    return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:CircleArea
//	Input		:float
//	Returns		:double
//	Description	:calculate area of a circle
//	Author		:Pranav Choudhary
//	Date		:7 August 2020
//
////////////////////////////////////////////////////////////////
double CircleArea(float fRad)
{
    double dArea = 0.0;
    if(fRad < 0.0)
        fRad = -fRad;
    dArea = PI * fRad * fRad;
    return dArea;
}