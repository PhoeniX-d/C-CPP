/*
*	Program to count frequency of particular digit in number
*/
#include<stdio.h>

int CountFreq(long, int);

int main()
{
	long lNum = 0;
	int iDig = 0, iRet = 0;
	printf("Enter the number:\t");
	scanf("%ld", &lNum);
	printf("Enter the digit:\t");
	scanf("%d", &iDig);
	iRet = CountFreq(lNum, iDig);
	printf("Number of %d in %ld is %d\n", iDig, lNum, iRet );
	return 0;
}
/////////////////////////////////////////////////////////////
//
//	Name		:CountFreq
//	Input		:long, int
//	Returns		:int
//	Description	:count frequency of particular digit in number
//	Author		:Pranav Choudhary
//	Date		:5 August 2020
//
/////////////////////////////////////////////////////////////
int CountFreq(
				long lNum,
				int iDig
			 )
{
	int iCnt = 0;
	if(lNum < 0)
	{
		lNum = -lNum;
	}
	if(iDig < 0)
	{
		iDig = -iDig;
	}

	while(lNum > 0)
	{
		if(lNum % 10 == iDig)
		{
			iCnt++;
		}
		lNum = lNum / 10;
	}
	return iCnt;
}