#include<stdio.h>
#define TRUE    1
#define FALSE   0

typedef int BOOL;

/////////////////////////////////////////////////////////////////
//
//  Name        : CheckDiv5
//  Input       : int
//  Returns     : BOOL(int)
//  Description : Displays given number is divisible by 5 or not
//
/////////////////////////////////////////////////////////////////
BOOL CheckDiv5(int iNo)
{
    if(iNo % 5 == 0)
        return TRUE;
    else
        return FALSE;
}
// entry point
int main()
{
    int iValue = 0;
    BOOL bRet = FALSE;
    printf("Enter the number\n");
    scanf("%d", &iValue);
    bRet = CheckDiv5(iValue);
    if(bRet == TRUE)
    {
        printf("Divisible By 5\n");
    }
    else
    {
        printf("Not Divisible by 5\n");
    }
    return 0;
}
