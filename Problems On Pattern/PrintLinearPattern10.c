/* 
*   Program to print like 1 2 3 4 * * * * 4 3 2 1  if N = 4 
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
////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern
//	Input		:int
//	Returns		:void
//	Description	:print like 1 2 3 4 * * * * 4 3 2 1  if N = 4  
//	Author		:Pranav Choudhary
//	Date		:15 August 2020
//
////////////////////////////////////////////////////////////////////////
void PrintPattern(
                        int iNo        
)   
{
    int i = 0;
    if(iNo < 0)
        iNo = -iNo;
    for (i = 1; i <= iNo; i++)
    {
        printf("%d\u0020", i);
    }

    for (i = 1; i <= iNo; i++)
    {
        printf("*\u0020", i);
    }

    for (i = iNo; i >= 1; i--)
    {
        printf("%d\u0020", i);
    }
}