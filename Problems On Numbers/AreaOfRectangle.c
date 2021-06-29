/* Program to calculate area of a rectangle */
// headers
#include<stdio.h>
#define PI 3.142

double RectangleArea(float, float);

int main()
{
    float flength = 0.0f, fBreadth = 0.0f;
    double dArea = 0.0;
    printf("Enter the lenth and breadth of recangle\n");
    scanf("%f %f", &flength, &fBreadth);
    dArea = RectangleArea(flength, fBreadth);
    printf("Area of rectangle = %G", dArea);
    return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:RectangleArea
//	Input		:float, float
//	Returns		:double
//	Description	:calculate area of a rectangle
//	Author		:Pranav Choudhary
//	Date		:7 August 2020
//
////////////////////////////////////////////////////////////////
double RectangleArea(float fL, float fB)
{
    if(fL < 0.0)
        fL = -fL;
    if(fB < 0)
        fB = -fB;    
    return (fL * fB);
}