/*
*   Write a program which accept number from user and print 5 multiples of
*   that number.
*   Input : 2 Output : 2 4 6 8 10
*/

#include<stdio.h>
#define MAXNO       1000

void PrintMultiples(int);

int main()
{
    int iNum = 0;
    printf("Enter the number\t:");
    scanf("%d", &iNum);
    PrintMultiples(iNum);
    return 0;
}
/////////////////////////////////////////////////////////////
//
//  Name        :PrintMultiples
//  Input       :int
//  Returns     :void
//  Description :Prints 5 Multiples of number using recursion
//  Author      :Pranav Choudhary
//  Date        :7 Sept 2020
//
//////////////////////////////////////////////////////////////
void PrintMultiples(int iNo)
{
    static int i = 1;   /* Initialized only once */
    if(i <= 5)
    {
        printf("%d ", i * iNo);
        i++;
        PrintMultiples(iNo);   /*  Recursive calls PrintMultiples() until i becomes iNo */
    }    
}