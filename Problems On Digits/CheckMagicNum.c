/*
*	Program to check a magic number and find first N magic numebrs
*	A magic number is that number whose sum of its digits is when
*	multiplied by the reverse of the sum of its digits gives back 
*	the same number.
*/

#include<stdio.h>

#define TRUE		1
#define FALSE		0
#define ERR 	 	-1

typedef char BOOL;

BOOL isMagic(long);

int main()
{
	long iNo = 0;
	BOOL bRet = FALSE;
	printf("Enter the number\n");
	scanf("%d", &iNo);
	bRet = isMagic(iNo);
	if(bRet == TRUE)
		printf("%d is Magic Number\n", iNo);
	else
		printf("%d is Not Magic Number\n", iNo);
	return 0;
}

////////////////////////////////////////////////////////////////
//
//	Name		:isMagic
//	Input		:long
//	Returns		:BOOL
//	Description	:Checks whether number is Magic number or not
//	Author		:Pranav Choudhary
//	Date		:3 August 2020
//
////////////////////////////////////////////////////////////////
BOOL isMagic(
             	long iNum
             )
{
	long iSum = 0, iRev = 0, iTemp = iNum;
	iNum = (iNum < 0) ? -iNum : iNum;
	if(iNum == 0)
		return ERR;

	while(iTemp != 0)
	{
		iSum = iSum + (iTemp % 10);
		iTemp = iTemp / 10;
	}
	iTemp = iSum;
	while(iTemp != 0)
	{
		iRev = iRev * 10 + (iTemp % 10);
		iTemp = iTemp / 10;
	}
	if(iRev * iSum == iNum)
		return TRUE;
	else
		return FALSE;
}