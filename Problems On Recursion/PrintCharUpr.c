/*
*   Write a recursive program which display below pattern.
*   Input   : 5
*   Output  : a b c d e
*/

#include<stdio.h>

void DisplayUpr(int);

int main()
{
    int iNum = 0;
    printf("Enter the number\t:");
    scanf("%d", &iNum);
    if(iNum < 0)
    {
        iNum = -iNum;
    }
    DisplayUpr(iNum);
    return 0;
}
///////////////////////////////////////////////////////////
//
//  Name        :DisplayUpr
//  Input       :void
//  Returns     :void
//  Description :Displays pattern on console using recursion
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
void DisplayUpr(int iNo)
{
    static int i = 1;        /* Initialized only once */
    static char ch = 'A';    /* Initialized only once */

    if(i <= iNo)
    {
        printf("%c ", ch);
        i++;
        ch++;
        DisplayUpr(iNo);   /*  Recursive calls Display() until i becomes iNo */
    }    
}