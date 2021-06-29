////////////////////////////////////////////////////////////////
//
//  Program to accept a two numbers and print Minimum of them
//
////////////////////////////////////////////////////////////////

// Headers
#include<stdio.h>

// Global Declarations
int Minimum(int, int);

// Entry Point
int main()
{
    int iNo1 = 0, iNo2 = 0, iMin = 0;
    printf("Enter the first Number\n");
    scanf("%d", &iNo1);
    printf("Enter the second Number\n");
    scanf("%d", &iNo2);

    iMin = Minimum(iNo1,iNo2);

    printf("Minimum is %5d", iMin);
    return 0;
}

// Definition Minimum
int Minimum(int iNo1, int iNo2)
{
    return ( (iNo1 > iNo2)? iNo2 : iNo1 );
}

/*
Output :
Enter the first Number
79
Enter the second Number
52
Minimum is    52
*/
