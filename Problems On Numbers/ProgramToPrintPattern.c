#include<stdio.h>

////////////////////////////////////////////////////////////////
//
// Name         :Display
// Input        :int, int
// Return       :void
// Description  :prints iNo , iFrequency times
//
/////////////////////////////////////////////////////////////////
void Display(int iNo, int iFrequency)
{
    int i = 0;
    if(iFrequency < 0)
    {
        iFrequency = -iFrequency;
    }
    for (i = 1; i <= iFrequency; i++)
    {
        printf("%d ", iNo);
    }
}
// entry point
int main()
{
    int iValue = 0;
    int iCount = 0;

    printf("Enter the number\n");
    scanf("%d", &iValue);
    printf("Enter how many times to print\n");
    scanf("%d", &iCount);
    Display(iValue, iCount);

    return 0;
}
