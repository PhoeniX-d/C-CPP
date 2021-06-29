///////////////////////////////////////////////////////////
//
//  Program to accept a two numbers and prints addition
//
///////////////////////////////////////////////////////////

// Headers
#include<stdio.h>

// Entry Point
int main()
{
    int iNo1 = 0, iNo2 = 0, iSum = 0;
    printf("Enter the first Number\n");
    scanf("%d", &iNo1);
    printf("Enter the second Number\n");
    scanf("%d", &iNo2);
    iSum = iNo1 + iNo2;
    printf("Addition is %5d", iSum);
    return 0;
}

/*
Output:
Enter the first Number
87
Enter the second Number
56
Addition is   143
*/
