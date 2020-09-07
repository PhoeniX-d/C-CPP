/*
*   Write a recursive program which display below pattern.
*   Input   : 5
*   Output  : a b c d e
*/

#include<stdio.h>

void DisplayLwr(int);

int main()
{
    int iNum = 0;
    printf("Enter the number\t:");
    scanf("%d", &iNum);
    if(iNum < 0)
    {
        iNum = -iNum;
    }
    DisplayLwr(iNum);
    return 0;
}
///////////////////////////////////////////////////////////
//
//  Name        :DisplayLwr
//  Input       :void
//  Returns     :void
//  Description :Displays pattern on console using recursion
//  Author      :Pranav Choudhary
//  Date        :6 Sept 2020
//
////////////////////////////////////////////////////////////
void DisplayLwr(int iNo)
{
    static int i = 1;        /* Initialized only once */
    static char ch = 'a';    /* Initialized only once */

    if(i <= iNo)
    {
        printf("%c ", ch);
        i++;
        ch++;
        DisplayLwr(iNo);   /*  Recursive calls Display() until i becomes iNo */
    }    
}