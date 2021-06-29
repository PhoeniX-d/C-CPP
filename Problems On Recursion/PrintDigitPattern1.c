/*
*   Write a program which prints following pattern in recursive manner.
*   Accept number of rows from user.
*   1
*   1 2
*   1 2 3
*/
#include<stdio.h>

void PatternRows(int);
void PatternCols(int, int);

//static int iCol = 1;

int main()
{
    int iNum = 0;
    printf("\nEnter the number\t:");
    scanf("%d", &iNum);
    if(iNum < 0)
    {
        iNum = -iNum;
    }
    printf("\n");
    PatternRows(iNum);
    return 0;
}
///////////////////////////////////////////////////////////
//
//  Name        :PatternRows
//  Input       :int
//  Returns     :void
//  Description :Displays pattern on console using recursion
//  Author      :Pranav Choudhary
//  Date        :7 Sept 2020
//
////////////////////////////////////////////////////////////
void PatternRows(int iNo)
{
    static int iRow = 1, iCol = 1;   /* Initialized only once */
    if(iRow <= iNo)
    {
        iCol = 1;
        PatternCols(iCol, iRow);
        printf("\n");
        iRow++;
        PatternRows(iNo);   /*  Recursive calls PatternRows() until i becomes iNo */
    }    
}

///////////////////////////////////////////////////////////
//
//  Name        :PatternCols
//  Input       :int, int
//  Returns     :void
//  Description :Displays pattern on console using recursion
//  Author      :Pranav Choudhary
//  Date        :7 Sept 2020
//
////////////////////////////////////////////////////////////
void PatternCols(int iCol, int iRow)
{
    if(iCol <= iRow)
    {
        printf("%d ", iCol);
        iCol++;
        PatternCols(iCol, iRow);   /*  Recursive calls PatternCols() until i becomes iNo */
    }    
}