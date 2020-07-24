#include<stdio.h>
///////////////////////////////////////////////////////////
//
//  Name        : Display
//  Input       : int
//  Returns     : void
//  Description : Displays N times *
//
///////////////////////////////////////////////////////////
void Display(int iNo)
{
    /*int i = 0;
    for(i = 1; i <= iNo; i++)
    {
        printf("* ");
    }*/
    while(iNo != 0)
    {
        printf("* ");
        iNo--;
    }
}

// entry point
int main()
{
    int iValue = 0;
    printf("Enter number\n");
    scanf("%d", &iValue);
    Display(iValue);
    return 0;
}
