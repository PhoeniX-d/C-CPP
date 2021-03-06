/* 
*   Program to print pattern like 
*
*    1  2  3  4
*    2  3  4  5
*    3  4  5  6
*    4  5  6  7
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
    int i = 0, j = 0, iNum = 0;
    if(iRow < 0)
        iRow = -iRow;
    if(iCol < 0)
        iCol = -iCol;
    printf("Output Pattern:\n");
    for (i = 1; i <= iRow; i++)
    {
        for(j = 1, iNum = i; j <= iCol; j++, iNum++)
        {
            printf("%2d ", iNum);
        }
        printf("\n");
    }
}