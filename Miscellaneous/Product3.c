/*
*	Program to print product of three numbers
*/
#include<stdio.h>

int Multiply(int, int, int);

int main()
{
	int iVal1 = 0, iVal2 = 0, iVal3 = 0, iRet = 0;
	printf("Enter three numbers\n");
	scanf("%d %d %d", &iVal1, &iVal2, &iVal3);
	iRet = Multiply(iVal1, iVal2, iVal3);
	printf("Product is %d", iRet);
	return 0;
}

/* defination of Multiply */
int Multiply(int iNum1, int iNum2, int iNum3)
{
	int iMult = 1;
	if(iNum1 == 0 && iNum2 == 0 && iNum3 == 0)
		return 0;
	if(iNum1 == 0)
		iNum1 = 1;
	if(iNum2 == 0)
		iNum2 = 1;
	if(iNum3 == 0)
		iNum3 = 1;

	return iNum1 * iNum2 * iNum3;
}
