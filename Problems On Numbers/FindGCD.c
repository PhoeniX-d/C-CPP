/* 
	Program to find gcd of a number
*/

#include<stdio.h>
#define ERR		-1
int gcd(int, int);

int main()
{
	int iNo1 = 0, iNo2 = 0, iRet = 0;
	printf("Enter the number1\n");
	scanf("%d", &iNo1);
	printf("Enter the number2\n");
	scanf("%d", &iNo2);
	iRet = gcd(iNo1, iNo2);

	if(iRet > 0)
		printf("gcd of number is %d\n", iRet);
	else
		printf("Enter non zero number or they dont have GCD\n");
	return 0;
}

////////////////////////////////////////////////////////////////
//
//	Name		:gcd
//	Input		:int, int
//	Returns		:int
//	Description	:find gcd of two numbers
//	Author		:Pranav Choudhary
//	Date		:3 August 2020
//
////////////////////////////////////////////////////////////////
int gcd(
            int iNum1,
            int iNum2
        )
{
	int i = 1, iMax = 0;
	iNum1 = (iNum1 < 0) ? -iNum1 : iNum1;
	iNum2 = (iNum2 < 0) ? -iNum2 : iNum2;
	if(iNum1 == 0 || iNum2 == 0)
		return ERR;
	for(i = 2 ; i < iNum1 && i < iNum2 ; i++)
	{
		if(iNum1 % i == 0 && iNum2 % i == 0)
		{
			iMax = i;
		}
	}
	return iMax;
}