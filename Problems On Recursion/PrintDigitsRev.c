/*
*   Write a recursive program which accept number from user and return its
*   reverse number.
*   Input : 523
*   Output : 325 
*/

#include<stdio.h>

void Display(long long int);

int main()
{
    long long int iNum = 0;
    printf("Enter the number\t:");
    scanf("%lld", &iNum);
    Display(iNum);
    return 0;
}
//////////////////////////////////////////////////////////////
//
//  Name        :Display
//  Input       :long long int
//  Returns     :void
//  Description :which prints digits in reverse order of a
//               number using recursion
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
///////////////////////////////////////////////////////////////
void Display(long long int iNo)
{
    if(iNo != 0)
    {
        Display(iNo / 10);   /*  Recursive calls Display() until i becomes iNo */
        printf("%d ", iNo % 10);
    }    
}