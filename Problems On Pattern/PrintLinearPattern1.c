/* 
*   Program to print 5 # 4 # 3 # 2 # 1 #
*/

#include<stdio.h>

void PrintPattern(int);

int main()
{
    int iNo = 0;
    printf("Enter the number\n");
    scanf("%d", &iNo);
    PrintPattern(iNo);
    return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern
//	Input		:int
//	Returns		:void
//	Description	:print 5 # 4 # 3 # 2 # 1 #
//	Author		:Pranav Choudhary
//	Date		:15 August 2020
//
////////////////////////////////////////////////////////////////
void PrintPattern(
                        int iNo        
)   
{
    if(iNo < 0)
        iNo = -iNo;
    for (; iNo >= 1; iNo--)
    {
        printf("%d # ", iNo);
    }
    printf("\n");
}