/* 
*	Program to find N abundanceN nums with abundanceN value
*	A number n for which the sum of divisors Sum[N] > N, 
*   or, equivalently, the sum of proper divisors
* 	abundanceN value = N - Sum[N]
*	Eg 12, factors 1,2,3,4,6, sum(factors) = 16, abundanceN value 16-12 = 4
*/

#include<stdio.h>

void abundanceN(int);

int main()
{
	int iNo = 0;
	printf("Enter the number\n");
	scanf("%d", &iNo);
	abundanceN(iNo);
	return 0;
}

////////////////////////////////////////////////////////////////
//
//	Name		:abundanceN
//	Input		:int
//	Returns		:void
//	Description	:find N abundanceN nums with abundanceN value
//	Author		:Pranav Choudhary
//	Date		:3 August 2020
//
////////////////////////////////////////////////////////////////
void abundanceN(
               		int iNum
               )
{
	int i = 0, iSum = 0, iCnt = 0;
	iNum = (iNum < 0) ? -iNum : iNum;
	if(iNum == 0)
		return;
	while(iNum != 0)
	{
		iCnt++;
		iSum = 0;
		for (i = 1; i <= iCnt / 2; i++)
		{
			if(iCnt % i == 0)
			{
				iSum = iSum + i;
			}
		}
		if(iCnt < iSum)
		{
			printf("%d -> Abundance value = %d\n", iCnt,iSum - iCnt);
			iNum--;
		}		
	}
}