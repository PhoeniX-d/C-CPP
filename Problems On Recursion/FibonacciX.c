/*
*   Write a program which accept number from user and print that many
*   number of elements from Fibonacci series.
*   Input : 6 Output : 0 1 1 2 3 5
*/

#include<stdio.h>
#define MAXNO       1000

void FibonacciX(int);

int main()
{
    int iNum = 0;
    printf("Enter the number\t:");
    scanf("%d", &iNum);
    if(iNum < 0)
    {
        iNum = -iNum;
    }
    FibonacciX(iNum);
    return 0;
}
/////////////////////////////////////////////////////////////
//
//  Name        :FibonacciX
//  Input       :int
//  Returns     :void
//  Description :Fibonacci numbers upto N using recursion
//  Author      :Pranav Choudhary
//  Date        :7 Sept 2020
//
//////////////////////////////////////////////////////////////
void FibonacciX(int iNum)
{
    static int iFirst = 0, iSecond = 1, iThird = 0, i = 1;   /* Initialized only once */
    if(i <= iNum)
    {
        printf("%d ", iFirst);
        iThird = iFirst + iSecond;
        iFirst = iSecond;
        iSecond = iThird;
        i++;
        FibonacciX(iNum);   /*  Recursive calls FibonacciX() until i becomes iNum */
    }    
}