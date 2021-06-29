/* Progran to divide two numbers */

#include<stdio.h>
///////////////////////////////////////////////////////////
//
//  Name        : Divide
//  Input       : int, int
//  Returns     : double
//  Description : Divides two numbers and returns quotient
//
///////////////////////////////////////////////////////////
double Divide(int iNo1, int iNo2)
{
    double dAns = 0.0;
    if(iNo2 == 0 && iNo1 != iNo2)
    {
        printf("Cannot Divide by zero\n");
        return -1;
    }
    dAns = iNo1 / iNo2;
    return dAns;
}

// entry point
int main()
{
    int iValue1 = 0, iValue2 = 0;
    double dRet = 0.0;
    scanf("%d %d", &iValue1, &iValue2);
    dRet = Divide(iValue1, iValue2);
    printf("Division is %lf", dRet);
    return 0;
}