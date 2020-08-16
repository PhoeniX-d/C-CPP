/* 
*   Program to print pattern like 
*
*   a b c d e  
*   1 2 3 4 5  
*   a b c d e
*   1 2 3 4 5
*
*   if iRow = 4 and iCol = 4
*/

#include<stdio.h>

void PrintPattern(int, int);

int main()
{
    int iValue1 = 0, iValue2 = 0;
    printf("Enter the rows\n");
    scanf("%d", &iValue1);
    printf("Enter the columns\n");
    scanf("%d", &iValue2);
    PrintPattern(iValue1, iValue2);
    return 0;
}
////////////////////////////////////////////////////////////////////////
//
//	Name		:PrintPattern
//	Input		:int, int
//	Returns		:void
//	Description	:print given pattern
//	Author		:Pranav Choudhary
//	Date		:15 August 2020
//
////////////////////////////////////////////////////////////////////////
void PrintPattern(
                        int iRow,
                        int iCol       
)   
{
    int i = 0, j = 0;
    char ch = '\0';
    if(iRow < 0)
        iRow = -iRow;
    if(iCol < 0)
        iCol = -iCol;
    printf("Output Pattern:\n");
    for (i = 1; i <= iRow; i++)
    {
        if(i % 2 == 0)
        {
            for (j = 1; j <= iCol; j++)
            {
                printf("%2d ", -j);
            }
        }
        else
        {
            for (j = 1; j <= iCol; j++)
            {
                printf("%2d ", j);
            }
        }
        printf("\n");
    }
}