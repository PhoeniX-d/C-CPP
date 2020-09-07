/*
*   Write a program which accept number from user and print its factors in
*   recursive manner.
*   Input : 15 Output : 1 3 5
*/
#include<stdio.h>

void Factors(int);

int main()
{
    int iNum = 0;
    printf("Enter the number\t:");
    scanf("%lld", &iNum);
    Factors(iNum);
    return 0;
}
//////////////////////////////////////////////////////////////
//
//  Name        :Factors
//  Input       :int
//  Returns     :void
//  Description :which prints factord of number using recursion
//  Author      :Pranav Choudhary
//  Date        :7 Sept 2020
//
///////////////////////////////////////////////////////////////
void Factors(int iNo)
{
    static int i = 1;   /* Initialized only once */
    if(i <= iNo / 2)
    {
        if(iNo % i == 0)
        {
            printf("%d ", i);
        }
        i++;
        Factors(iNo);   /*  Recursive calls Factors() until i becomes iNo */
    }    
}