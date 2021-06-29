/*
*	Program to check whether number is auolorphic or not
*	Automorpic Number :an automorphic number is a natural
*	number in a given number base whose square "ends" in 
*	the same digits as the number itself.
*/

#include<stdio.h>
#define TRUE		1
#define FALSE		0
#define ERR			-1
typedef char BOOL;

BOOL isAutomorphic(int);

int main()
{
	int iNum = 0;
	printf("Enter the number\n");
	scanf("%d", &iNum);
	BOOL bRet = isAutomorphic(iNum);
	if(bRet == TRUE)
		printf("%d is Automorpic\n", iNum);
	else
		printf("%d is not Automorpic\n", iNum);
	return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:isAutomorphic
//	Input		:int
//	Returns		:BOOL
//	Description	:Checks whether number is Automorphic number or not
//	Author		:Pranav Choudhary
//	Date		:3 August 2020
//
////////////////////////////////////////////////////////////////
BOOL isAutomorphic(
                   		int iNum
                   )
{
	long lTemp = iNum;
	int iLen = 0, iRev1 = 0, iRev2 = 0;
	
	iNum = (iNum < 0) ? -iNum : iNum;
	if(iNum == 0)
		return ERR;

	while(lTemp != 0)
	{
		iLen++;
		lTemp = lTemp / 10;
	}
	lTemp = iNum * iNum;
	while(iLen != 0)
	{
		iRev1 = iRev1 * 10 + (lTemp % 10);
		iRev2 = iRev2 * 10 + (iNum % 10);
		lTemp = lTemp / 10;
		iNum = iNum / 10;
		iLen--;
	}
	if(iRev1 == iRev2)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}