/* 
*   Program to print -3 * -2 * -1 * 0 * 1 * 2 * 3 if N = 3 
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
//	Description	:print -3 * -2 * -1 * 0 * 1 * 2 * 3 if N = 3
//	Author		:Pranav Choudhary
//	Date		:15 August 2020
//
////////////////////////////////////////////////////////////////
void PrintPattern(
                        int iNo        
)   
{
    int i = 0;
    if(iNo < 0)
        iNo = -iNo;
    for (i = -iNo; i <= iNo; i++)
    {
        printf("%d * ", i);
    }
    printf("\n");
}