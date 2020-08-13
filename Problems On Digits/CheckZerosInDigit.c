/*
*	Program to check that numbers contains zeros in it or not
*/
#include<stdio.h>
#define TRUE	1
#define FALSE	0
typedef char BOOL;

BOOL isZeroPresent(int);

int main()
{
	int iNum = 0;
	BOOL bRet = FALSE;
	printf("Enter the Number\n");
	scanf("%d", &iNum);
	bRet = isZeroPresent(iNum);
	if(bRet == TRUE)
	{
		printf("There is zero in number\n");
	}
	else
	{
		printf("There is no zero in number\n");
	}
	return 0;
}

///////////////////////////////////////////////////////////////
//
//  Name        :isZeroPresent
//  Input       :int
//  Returns     :BOOL
//  Desription  :check that numbers contains zeros in it or not
//  Author      :Pranav P. Choudhary
//  Date        :4 August 2020
//
///////////////////////////////////////////////////////////////
BOOL isZeroPresent(
                   		int iNum
                   )
{
	int iDigit = 0;
	if(iNum < 0)
		iNum = -iNum;
	while(iNum != 0)
	{
		iDigit = iNum % 10;
		if(iDigit == 0)
		{
			break;
		}
		iNum = iNum / 10;
	}
	if(iNum == 0)
		return FALSE;
	else
		return TRUE;
}
