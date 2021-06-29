/*
*	Program to count frequency of  digit between given range
*/
#include<stdio.h>
#define ERR		-1

int CountRange(long long, int, int);

int main()
{
	long long lNum = 0;
	int iMin = 0, iMax = 0, iRet = 0;
	printf("Enter the number:\t");
	scanf("%ld", &lNum);
	printf("Enter min max range:\t");
	scanf("%d %d", &iMin, &iMax);
	iRet = CountRange(lNum, iMin, iMax);
	if(iRet == ERR)
	{
		printf("Enter valid range\n");
	}
	{
		printf("%d", iRet);
	}
	return 0;
}
/////////////////////////////////////////////////////////////
//
//	Name		:CountRange
//	Input		:long, int, int
//	Returns		:int
//	Description	:counts frequency of  digit between given range
//	Author		:Pranav Choudhary
//	Date		:5 August 2020
//
/////////////////////////////////////////////////////////////
int CountRange(
				long long lNum,
				int iMin,
				int iMax
			 )
{
	int iCnt = 0;

	// updater
	if(lNum < 0)
		lNum = -lNum;
	if(iMin < 0)
		iMin = -iMin;
	if(iMax < 0)
		iMax = -iMax;

	// filter
	if(iMax < iMin)
		return ERR;

	while(lNum > 0)
	{
		if((lNum % 10 < iMax) && (lNum % 10 > iMin))	
		{
			iCnt++;
		}
		lNum = lNum / 10;
	}
	return iCnt;
}