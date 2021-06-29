/* 
*   Program to print pattern like 
*
*   2 4 6 8 10  
*   1 3 5 7  9  
*   2 4 6 8 10
*   1 3 5 7  9
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
    int i = 0, j = 0, iNum = 1;
    if(iRow < 0)
        iRow = -iRow;
    if(iCol < 0)
        iCol = -iCol;
    printf("Output Pattern:\n");
    for (i = 1; i <= iRow; i++)
    {
        if(i % 2 == 0)
        {
            for (j = 1, iNum = 1; j <= iCol; j++, iNum = iNum + 2)
            {
                printf("%2d ", iNum);
            }
        }
        else
        {
            for (j = 1, iNum = 2; j <= iCol; j++, iNum = iNum + 2)
            {
                printf("%2d ", iNum);
            }
        }
        printf("\n");
    }
}