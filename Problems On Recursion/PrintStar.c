/*
*   Write a recursive program which display below pattern.
*   Input   :5
*   Output  : * * * * * 
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
///////////////////////////////////////////////////////////
//
//  Name        :Display
//  Input       :void
//  Returns     :void
//  Description :Displays pattern on console using recursion
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
void Display(int iNo)
{
    static int i = 1;   /* Initialized only once */
    if(i <= iNo)
    {
        printf("* ");
        i++;
        Display(iNo);   /*  Recursive calls Display() until i becomes iNo */
    }    
}