/*
*	Program to check whether entered number is Sunny Number or not
*	Sunny Number : A number N is called sunny number
*	if the square root of the number N+1 is an integer number
*/

#include<stdio.h>
#include<math.h>

#define TRUE	1
#define FALSE	0
#define ERR		-1

typedef char BOOL;

BOOL ChkSunny(int);

int main()
{
	int iNum = 0;
	BOOL bRet = FALSE;
	printf("Enter the number :\t");
	scanf("%d", &iNum);
	bRet = ChkSunny(iNum);
	if(bRet == TRUE)
		printf("%d is Sunny Number\n", iNum);
	else
		printf("%d is Not Sunny Number\n", iNum );
	return 0;
}

////////////////////////////////////////////////////////////////
//
//	Name		:ChkSunny
//	Input		:int
//	Returns		:BOOL
//	Description	:Checks whether number is Sunny number or not
//	Author		:Pranav Choudhary
//	Date		:2 August 2020
//
////////////////////////////////////////////////////////////////
BOOL ChkSunny(
                	int iNum	// number 
                )
{
	iNum = (iNum < 0) ? -iNum : iNum;
	double dTemp = sqrt(iNum + 1);
	if(dTemp - floor(dTemp) == 0)
		return TRUE;
	else
		return FALSE;
}
