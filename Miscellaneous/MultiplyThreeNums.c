////////////////////////////////////////////////////////////////
//
//  Program to accept a three numbers and prints multiplication
//
////////////////////////////////////////////////////////////////

// Headers
#include<stdio.h>

// Global Declarations
int Multiply(int, int, int);

// Entry Point
int main()
{
    int iNo1 = 0, iNo2 = 0, iNo3 = 0, iProd = 0;
    printf("Enter the first Number\n");
    scanf("%d", &iNo1);
    printf("Enter the second Number\n");
    scanf("%d", &iNo2);
    printf("Enter the third Number\n");
    scanf("%d", &iNo3);
    iProd = Multiply(iNo1,iNo2,iNo3);
    printf("Multiplication is %5d", iProd);
    return 0;
}

// Definition Multiply
int Multiply(int iNo1, int iNo2, int iNo3)
{
    return iNo1 * iNo2 * iNo3;
}

/*
Output:
Enter the first Number
4
Enter the second Number
9
Enter the third Number
3
Multiplication is   108
*/
