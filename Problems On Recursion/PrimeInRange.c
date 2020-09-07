/*
*   Write a program which accept range from user and print all prime
*   numbers in that range in recursive manner
*/
#include<stdio.h>
#define TRUE        1
#define FALSE       0

typedef int BOOL;

void PrimeRange(int, int);
BOOL IsPrime(int, int);

int main()
{
    int iStart = 0, iEnd = 0;

    printf("Enter the start of range\t:");
    scanf("%d", &iStart);
    printf("Enter the end of range\t\t:");
    scanf("%d", &iEnd);
    if(iStart > iEnd || iStart < 0)
    {
        printf("Invalid Range!!\n");
        return;
    }
    PrimeRange(iStart, iEnd);
    return 0;
}

//////////////////////////////////////////////////////////////
//
//  Name        :PrimeRange
//  Input       :int, int
//  Returns     :void
//  Description :which prints prime number in that range using
//               recursion
//  Author      :Pranav Choudhary
//  Date        :7 Sept 2020
//
///////////////////////////////////////////////////////////////
void PrimeRange(int iS, int iE)
{
    BOOL bRet = FALSE;
    if(iS <= iE)
    {        
        bRet = IsPrime(iS, iS / 2);   /*  Recursive calls PrimeRange() until i becomes iNo */
        if(bRet == TRUE)
        {
            printf("%d ", iS);
        }
        iS++;
        PrimeRange(iS, iE);
    }
}

//////////////////////////////////////////////////////////////
//
//  Name        :IsPrime
//  Input       :int, int
//  Returns     :BOOL
//  Description :Checks whether number is Prime or not using 
//               recursion
//  Author      :Pranav Choudhary
//  Date        :7 Sept 2020
//
///////////////////////////////////////////////////////////////
BOOL IsPrime(int iS, int j)
{
    if(j > 1)
    {
        if(iS % j == 0)
        {
            return FALSE;
        }
        j--;
        IsPrime(iS, j);   /*  Recursive calls PrimeRange() until i becomes iNo */
    }
    if(j == 1)
    {
        return TRUE;
    }
}