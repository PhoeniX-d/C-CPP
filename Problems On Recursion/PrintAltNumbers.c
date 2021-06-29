/*
*   Write a program which prints alternate numbers from 1 to 100 in
*   recursive manner.
*   Output : 1 3 5 7 9 11 …………..
*/

#include<stdio.h>
#define MAXNO       1000

void Display(int);

int main()
{
    int iNum = 0;
    printf("Enter the number\t:");
    scanf("%d", &iNum);
    if(iNum < 0)
    {
        iNum = -iNum;
    }
    Display(iNum);
    return 0;
}
///////////////////////////////////////////////////////////
//
//  Name        :Display
//  Input       :int
//  Returns     :void
//  Description :Displays alternate numbers upto N on 
//               console using recursion
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
        i = i + 2;
        Display(iNo);   /*  Recursive calls Display() until i becomes iNo */
    }    
}