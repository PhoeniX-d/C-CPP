/* 
*	A number n for which the sum of divisors Sum[N] > N, 
*   or, equivalently, the sum of proper divisors
* 	Abundance value = N - Sum[N]
*	Eg 12, factors 1,2,3,4,6, sum(factors) = 16, abundance value 16-12 = 4
*/

#include<stdio.h>

void abundance(int);

int main()
{
	int iNo = 0;
	printf("Enter the number\n");
	scanf("%d", &iNo);
	abundance(iNo);
	return 0;
}

////////////////////////////////////////////////////////////////
//
//	Name		:abundance
//	Input		:int
//	Returns		:void
//	Description	:find abundance nnumber and its abundance value
//	Author		:Pranav Choudhary
//	Date		:3 August 2020
//
////////////////////////////////////////////////////////////////
void abundance(
               		int iNum
               )
{
	int i = 0, iSum = 0;
	iNum = (iNum < 0) ? -iNum : iNum;
	if(iNum == 0)
		return;

	for (i = 1; i <= iNum / 2; i++)
	{
		if(iNum % i == 0)
		{
			iSum = iSum + i;
		}
	}
	if(iNum < iSum)
		printf("%d is Abundance number and its value = %d\n",iNum, iSum - iNum);
	else
		printf("Not an abundance number\n");
}