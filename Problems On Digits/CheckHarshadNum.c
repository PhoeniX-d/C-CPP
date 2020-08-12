/*
*	Program to check whether entered number is Harshad Number or not
*	Harshad Number : a harshad number (or Niven number) in a given number base is an integer that
*	is divisible by the sum of its digits when written in that base
*/
#include<stdio.h>
#define TRUE	1
#define FALSE	0
#define ERR		-1
#define BASE 	10
typedef char BOOL;

BOOL ChkHarshad(int);

int main()
{
	int iNum = 0;
	BOOL bRet = FALSE;
	printf("Enter the number :\t");
	scanf("%d", &iNum);
	bRet = ChkHarshad(iNum);
	if(bRet == TRUE)
		printf("%d is Harshad(Niven) Number\n", iNum);
	else
		printf("%d is Not Harshad(Niven) Number\n", iNum );
	return 0;
}

////////////////////////////////////////////////////////////////
//
//	Name		:ChkHarshad
//	Input		:int
//	Returns		:BOOL
//	Description	:Checks whether number is Harshad number or not
//	Author		:Pranav Choudhary
//	Date		:2 August 2020
//
////////////////////////////////////////////////////////////////
BOOL ChkHarshad(
                	int iNum	// number 
                )
{
	int iSum = 0,iTemp = iNum;
	iNum = (iNum < 0) ? -iNum : iNum;
	if(iNum == 0)
		return ERR;
	while(iNum > 0)
	{
		iSum = iSum + (iNum % BASE);
		iNum = iNum / BASE;
	}
	if(iTemp % iSum == 0)
		return TRUE;
	else
		return FALSE;
}
