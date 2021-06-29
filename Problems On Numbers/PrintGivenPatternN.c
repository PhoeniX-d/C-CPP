/* Program to print N times $ and * */
#include<stdio.h>
void DisplayDollStar(int);

int main()
{
    int iNo = 0;
    printf("Enter the number\n");
    scanf("%d", &iNo);
    DisplayDollStar(iNo);
    return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:DisplayDollStar
//	Input		:int
//	Returns		:void
//	Description	:prints that number of stars and dollers
//	Author		:Pranav Choudhary
//	Date		:7 August 2020
//
////////////////////////////////////////////////////////////////
void DisplayDollStar(
                        int iNo        
)   
{
    if(iNo < 0)
        iNo = -iNo;
    for (; iNo >= 1; iNo--)
    {
        printf("$ * ");
    }
    printf("\n");
}