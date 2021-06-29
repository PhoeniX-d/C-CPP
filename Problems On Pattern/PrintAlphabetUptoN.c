/* 
*   Program to print Capital alphabets upto N
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
//	Description	:print Capital alphabets upto N
//	Author		:Pranav Choudhary
//	Date		:15 August 2020
//
////////////////////////////////////////////////////////////////
void PrintPattern(
                        int iNo        
)   
{
    char ch = 'A';
    if(iNo < 0)
        iNo = -iNo;
    for (; iNo >= 1; iNo--, ch++)
    {
        printf("%c ", ch);
    }
    printf("\n");
}