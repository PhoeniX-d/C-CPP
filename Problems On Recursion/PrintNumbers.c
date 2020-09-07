/*
*   Write a recursive program which display below pattern.
*   Input   : 5
*   Output  : 1 2 3 4 5
*/

#include<stdio.h>
#define MAXNO       1000

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
//  Input       :int
//  Returns     :void
//  Description :Displays pattern on console using recursion
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
void Display(int iNo)
{
    static int i = 1;   /* Initialized only once */
    if(i <= iNo && i <= MAXNO)
    {
        printf("%d ", i);
        i++;
        Display(iNo);   /*  Recursive calls Display() until i becomes iNo */
    }    
}