/* 
*   Program to print pattern like 
*
*   1 2 3 4 
*   1 2 3 4 
*   1 2 3 4
*   1 2 3 4
*
*   if N = 4 
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
//	Description	:print given pattern
//	Author		:Pranav Choudhary
//	Date		:15 August 2020
//
////////////////////////////////////////////////////////////////////////
void PrintPattern(
                        int iNo        
)   
{
    int i = 0, j = 0;
    if(iNo < 0)
        iNo = -iNo;
    for (i = 1; i <= iNo; i++)
    {
        for (j = 1; j <= iNo; j++)
        {
            printf("%d\u0020", j);
        }
        printf("\x0A");
    }
}