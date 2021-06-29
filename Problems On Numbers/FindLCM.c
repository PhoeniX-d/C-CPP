/* 
	Program to find LCM of a number
*/

#include<stdio.h>
#define ERR		-1
int lcm(int, int);

int main()
{
	int iNo1 = 0, iNo2 = 0, iRet = 0;
	printf("Enter the number1\n");
	scanf("%d", &iNo1);
	printf("Enter the number2\n");
	scanf("%d", &iNo2);
	iRet = lcm(iNo1, iNo2);

	if(iRet != ERR)
		printf("LCM of number is %d\n", iRet);
	else
		printf("Enter non zero number\n");
	return 0;
}

////////////////////////////////////////////////////////////////
//
//	Name		:lcm
//	Input		:int, int
//	Returns		:int
//	Description	:find lcm of two numbers
//	Author		:Pranav Choudhary
//	Date		:3 August 2020
//
////////////////////////////////////////////////////////////////
int lcm(
            int iNum1,
            int iNum2
        )
{
	int i = 1, iMin = 0;
	iNum1 = (iNum1 < 0) ? -iNum1 : iNum1;
	iNum2 = (iNum2 < 0) ? -iNum2 : iNum2;
	if(iNum1 == 0 || iNum2 == 0)
		return ERR;

	iMin = (iNum1 > iNum2) ? iNum2 : iNum1;
	while(1)
	{
		if(iMin % iNum1 == 0 && iMin % iNum2 == 0)
		{
			break;
		}
		iMin++;		
	}
	return iMin;
}