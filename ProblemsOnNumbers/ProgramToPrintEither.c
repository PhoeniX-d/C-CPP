#include<stdio.h>

////////////////////////////////////////////////////////////////
//
// Name         :Display
// Input        :int
// Return       :void
// Description  :Checks Number and prints string deped on number
//
/////////////////////////////////////////////////////////////////
void Display(int iNo)
{
    if(iNo < 10)
    {
        printf("Hello\n");
    }
    else
    {
        printf("Demo\n");
    }    
}
// entry point
int main()
{
    int iValue = 0;
    printf("Enter the number\n");
    scanf("%d", &iValue);
    Display(iValue);

    return 0;
}

