/*
*	Program to find first N Automorphic numbers
*	Automorpic Number :an automorphic number is a natural
*	number in a given number base whose square "ends" in 
*	the same digits as the number itself.
*/

#include<stdio.h>
#define MAX 	6
void N_automorphic(int);

int main()
{
	int iMax = 0;
	printf("Enter the number (Max 6)\n");
	scanf("%d", &iMax);
	N_automorphic(iMax);
	return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:N_automorphic
//	Input		:int
//	Returns		:BOOL
//	Description	:find first N Automorphic numbers
//	Author		:Pranav Choudhary
//	Date		:3 August 2020
//
////////////////////////////////////////////////////////////////
void N_automorphic(
                   		int iMax
                   )
{
	long long unsigned lTemp = 0L;
	unsigned int iLen = 0, iRev1 = 0, iRev2 = 0, iCnt = 0, iTemp = 0;
	
	iMax = (iMax < 0) ? -iMax : iMax;
	if(iMax == 0 && iMax >= MAX)
		return;

	while(iMax != 0)
	{
		iCnt++;
		iLen = 0; iRev1 = 0; iRev2 = 0;
		lTemp = iCnt;
		while(lTemp != 0)
		{
			iLen++;
			lTemp = lTemp / 10;
		}
		lTemp = iCnt * iCnt;
		iTemp = iCnt;
		while(iLen != 0)
		{
			iRev1 = iRev1 * 10 + (lTemp % 10);
			iRev2 = iRev2 * 10 + (iTemp % 10);
			lTemp = lTemp / 10;
			iTemp = iTemp / 10;
			iLen--;
		}
		if(iRev1 == iRev2)
		{
			printf("%d ",iCnt);
			iMax--;
		}
	}
}