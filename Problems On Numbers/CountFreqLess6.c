/*
*	Program to count frequency of  digit less than 6
*/
#include<stdio.h>

int CountFreq(long);

int main()
{
	long lNum = 0;
	int iDig = 0, iRet = 0;
	printf("Enter the number:\t");
	scanf("%ld", &lNum);
	iRet = CountFreq(lNum);
	printf("%d", iRet );
	return 0;
}
/////////////////////////////////////////////////////////////
//
//	Name		:CountFreq
//	Input		:long
//	Returns		:int
//	Description	:count frequency of  digit less than 6
//	Author		:Pranav Choudhary
//	Date		:5 August 2020
//
/////////////////////////////////////////////////////////////
int CountFreq(
				long lNum
			 )
{
	int iCnt = 0;
	if(lNum < 0)
	{
		lNum = -lNum;
	}
	while(lNum > 0)
	{
		if(lNum % 10 < 6)
		{
			iCnt++;
		}
		lNum = lNum / 10;
	}
	return iCnt;
}