/*
*   Write a recursive program which display below pattern.
*   Input   : 5
*   Output  : 5 4 3 2 1
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
    if(iNo > 0)
    {
        printf("%d ", iNo);
        iNo--;
        Display(iNo);   /*  Recursive calls Display() until i becomes iNo */
    }    
}