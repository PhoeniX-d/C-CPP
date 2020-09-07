/*
*   Write a program which accept range from user and print all Perfect
*   numbers in that range in recursive manner
*/
#include<stdio.h>


void PerfectRange(int, int);
int Perfect(int, int*, int);

int main()
{
    int iStart = 0, iEnd = 0;

    printf("Enter the start of range\t:");
    scanf("%d", &iStart);
    printf("Enter the end of range\t\t:");
    scanf("%d", &iEnd);
    PerfectRange(iStart, iEnd);
    return 0;
}

//////////////////////////////////////////////////////////////
//
//  Name        :PerfectRange
//  Input       :int, int
//  Returns     :void
//  Description :which prints Perfect number in that range using
//               recursion
//  Author      :Pranav Choudhary
//  Date        :7 Sept 2020
//
///////////////////////////////////////////////////////////////
void PerfectRange(int iS, int iE)
{
    static int iSum = 0;
    if(iS <= iE)
    {
        iSum = 0;
        Perfect(iS, &iSum, iS / 2);   /*  Recursive calls PerfectRange() until i becomes iNo */
        if(iS == iSum)
        {
            printf("%d ", iS);
        }
        iS++;
        PerfectRange(iS, iE);
    }
}

//////////////////////////////////////////////////////////////
//
//  Name        :Perfect
//  Input       :int, int*, int
//  Returns     :void
//  Description :Counts summation for checking perfect number 
//               using recursion
//  Author      :Pranav Choudhary
//  Date        :7 Sept 2020
//
///////////////////////////////////////////////////////////////
int Perfect(int iS, int* iSum,  int j)
{
    if(j > 0)
    {
        if(iS % j == 0)
        {
            *iSum = *iSum + j;
        }
        j--;
        Perfect(iS, iSum, j);   /*  Recursive calls PerfectRange() until i becomes iNo */
    }
}