/*
*   Program to calculate power of number using recursion
*   Input   :2 4    Input   :2 -2    
*   Output  :16     Output  :0.25
*/

#include<stdio.h>
#include<math.h>

float PowerX(int , int);

int main()
{
    int iNum = 0, iPow = 0;
    float fRet = 0.0;
    printf("Enter the number\t:");
    scanf("%d", &iNum);

    printf("Enter the power\t\t:");
    scanf("%d", &iPow);

    fRet = PowerX(iNum, iPow);
    printf("%d Power %d is\t\t:%g\n", iPow, iNum, fRet);

    return 0;
}
///////////////////////////////////////////////////////////
//
//  Name        :PowerX
//  Input       :int, int
//  Returns     :float
//  Description :calculate power of number using recursion
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
float PowerX(int iNo, int iPower)
{
    static float fAns = 1;
    static int i = 1;
    if(iNo == 0)
    {
        return iNo;
    }
    if(i <= abs(iPower))
    {
        fAns = iNo * fAns;
        i++;
        PowerX(iNo, iPower);
    }
    if(iPower < 0)
    {
        return (1 / fAns);
    }
    else
    {
        return fAns;
    }
}
