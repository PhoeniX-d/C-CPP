/* Program to print Table of given number */
#include<stdio.h>

void DisplayTable(int iNo);

int main()
{
    int iNo = 0;
    printf("Enter the number\n");
    scanf("%d", &iNo);
    DisplayTable(iNo);
    return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:DisplayTable
//	Input		:int
//	Returns		:void
//	Description	:print table of a given number (reverse + forward)
//	Author		:Pranav Choudhary
//	Date		:7 August 2020
//
////////////////////////////////////////////////////////////////
void DisplayTable(int iNum)
{
    int i = 0, j = 0;
    if(iNum < 0)
        iNum = -iNum;
    // forward
    for (i = 1, j = 10; i <= 10 && j >=1; i++, j--)
    {
        printf("%d\t%d\n", iNum * i, iNum * j);
    }
}
/* Time Complexity O(n) */