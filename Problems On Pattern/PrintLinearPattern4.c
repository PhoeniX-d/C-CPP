/* 
*   Program to print 1 * 2 * 3 if N  = 5 
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
//	Description	:print 1 * 2 * 3 if N  = 5 
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
    for (int i = 1; i <= iNo; i++)
    {
        if(i % 2 == 0)
        {
            printf("* ");
        }
        else
        {
            printf("%d ", i);
        }        
    }
    printf("\n");
}