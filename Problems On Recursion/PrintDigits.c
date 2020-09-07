/*
*   Write a recursive program which prints digits of number
*   Input   : 123
*   Output  : 3 2 1
*/

#include<stdio.h>

void Display(long long int);

int main()
{
    long long int iNum = 0;
    printf("Enter the number\t:");
    scanf("%lld", &iNum);
    if(iNum < 0)
    {
        iNum = -iNum;
    }
    Display(iNum);
    return 0;
}
//////////////////////////////////////////////////////////////
//
//  Name        :Display
//  Input       :long long int
//  Returns     :void
//  Description :which prints digits of number using recursion
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
///////////////////////////////////////////////////////////////
void Display(long long int iNo)
{
    //static int i = 1;   /* Initialized only once */
    if(iNo != 0)
    {
        printf("%d ", iNo % 10);
        Display(iNo / 10);   /*  Recursive calls Display() until i becomes iNo */
    }    
}