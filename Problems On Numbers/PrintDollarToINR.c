/* Program to print N USD Dollar into N INR assume 1$ = 70 */
#include<stdio.h>
int DollarToINR(int);

int main()
{
    int iNo = 0, iRet = 0;
    printf("Enter the number\n");
    scanf("%d", &iNo);
    iRet = DollarToINR(iNo);
    printf("%d Dollar = %d Ruppees", iNo, iRet);
    return 0;
}
//////////////////////////////////////////////////////////////////////////
//
//	Name		:DollarToINR
//	Input		:int
//	Returns		:int
//	Description	:Program to print N USD Dollar into N INR assume 1$ = 70Rs
//	Author		:Pranav Choudhary
//	Date		:7 August 2020
//
//////////////////////////////////////////////////////////////////////////
int DollarToINR(
                        int iNo        
)   
{
    if(iNo < 0)
        iNo = -iNo;
    return iNo * 70;
}