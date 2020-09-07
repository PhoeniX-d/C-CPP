/*
*   Write a program which accept number from user and print the number
*   line for that number in recursive manner.
*   Input : 4 Output: -4 -3 -2 -1 0 1 2 3 4
*/
#include<stdio.h>
#define MAXNO       1000

void NumLine(int, int);

int main()
{
    int iNum = 0, i = 0;
    printf("Enter the number\t:");
    scanf("%d", &iNum);
    if(iNum > 0)
    {
        NumLine(-iNum, iNum);
    }
    else
    {
        NumLine(iNum, -iNum);
    }   
    return 0;
}
///////////////////////////////////////////////////////////
//
//  Name        :NumLine
//  Input       :int
//  Returns     :void
//  Description :Display number line upto N using recursion
//  Author      :Pranav Choudhary
//  Date        :7 Sept 2020
//
////////////////////////////////////////////////////////////
void NumLine(int i, int iNo)
{
    if(i <= iNo)
    {
        printf("%d ", i);
        i++;
        NumLine(i, iNo);   /*  Recursive calls NumLine() until i becomes iNo */
    } 
}