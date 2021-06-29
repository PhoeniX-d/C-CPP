#include<stdio.h>
#define TRUE     1
#define FALSE    0
typedef int BOOL;

////////////////////////////////////////////////////////////////
//
// Name         :CheckOddEven
// Input        :int
// Return       :BOOL(int)
// Description  :prints iNo is Even or Odd
//
/////////////////////////////////////////////////////////////////
BOOL CheckOddEven(int iNo)
{
    if(iNo % 2 == 0)
    {
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

// entry point
int main()
{
    int iValue = 0;
    BOOL bRet = FALSE;

    printf("Enter the number\n");
    scanf("%d", &iValue);

    bRet = CheckOddEven(iValue);
    if(bRet == TRUE)
    {
        printf("Given Number is Even\n");
    }
    else
    {
        printf("Given Number is Odd\n");
    }    
    return 0;
}
