////////////////////////////////////////////////////////////////
//
//  Program to accept a two numbers and print maximum of them
//
////////////////////////////////////////////////////////////////

// Headers
#include<stdio.h>

// Global Declarations
int Maximum(int, int);

// Entry Point
int main()
{
    int iNo1 = 0, iNo2 = 0, iMax = 0;
    printf("Enter the first Number\n");
    scanf("%d", &iNo1);
    printf("Enter the second Number\n");
    scanf("%d", &iNo2);

    iMax = Maximum(iNo1,iNo2);

    printf("Maximum is %5d", iMax);
    return 0;
}

// Definition Maximum
int Maximum(int iNo1, int iNo2)
{
    return ( (iNo1 > iNo2)? iNo1 : iNo2 );
}

/*
Output:
Enter the first Number
76
Enter the second Number
43
Maximum is    76
*/
