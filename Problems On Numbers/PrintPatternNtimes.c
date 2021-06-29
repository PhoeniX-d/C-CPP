/* Program to print N times # and then N times * */
#include<stdio.h>
void Display(int);

int main()
{
    int iNo = 0;
    printf("Enter the number\n");
    scanf("%d", &iNo);
    Display(iNo);
    return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:Display
//	Input		:int
//	Returns		:void
//	Description	:Program to print N times # and then N times *
//	Author		:Pranav Choudhary
//	Date		:7 August 2020
//
////////////////////////////////////////////////////////////////
void Display(
                        int iNo        
)   
{
    if(iNo < 0)
        iNo = -iNo;
    for (int i = 1; i <= 2 * iNo; i++)
    {
        if(i <= iNo)
            printf("* ");
        else if(i > iNo)
            printf("# ");
    }
    printf("\n");
}