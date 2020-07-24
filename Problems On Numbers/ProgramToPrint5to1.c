/* Progran to print 5 to 1 numbers */
#include<stdio.h>
///////////////////////////////////////////////////////////
//
//  Name        : Display
//  Input       : void
//  Returns     : void
//  Description : Displays 5 to 1 numbers
//
///////////////////////////////////////////////////////////
void Display()
{
    int i = 0;
    for(i = 5; i >= 1; i--)
    {
        printf("%d\t", i);
    }
}

// entry point
int main()
{
    Display();
    return 0;
}
