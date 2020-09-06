/*
*   Write a recursive program which prints digits of number
*   Input   : 123
*   Output  : 3 2 1
*/

#include<stdio.h>

void Display(int);

int main()
{
    int iNum = 0;
    printf("Enter the number\t:");
    scanf("%d", &iNum);
    Display(iNum);
    return 0;
}
//////////////////////////////////////////////////////////////
//
//  Name        :Display
//  Input       :void
//  Returns     :void
//  Description :which prints digits of number using recursion
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
///////////////////////////////////////////////////////////////
void Display(int iNo)
{
    //static int i = 1;   /* Initialized only once */
    if(iNo != 0)
    {
        printf("%d ", iNo % 10);
        iNo = iNo / 10;
        Display(iNo);   /*  Recursive calls Display() until i becomes iNo */
    }    
}