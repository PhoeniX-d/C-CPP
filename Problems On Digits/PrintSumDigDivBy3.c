/* Program to print summation of digits which are divisible by 3 */

#include<stdio.h>

int Compute(long);

int main()
{
	long lNo = 0;
	int iRet = 0;
	printf("Enter the number\n");
	scanf("%ld", &lNo);
	iRet = Compute(lNo);
    printf("summation is %d", iRet);
    return 0;
}

//////////////////////////////////////////////////////////////////////
//
//  Name        :Compute
//  Input       :long
//  Returns     :int
//  Desription  :print summation of digits which are divisible by 3
//  Author      :Pranav P. Choudhary
//  Date        :1 August 2020
//
//////////////////////////////////////////////////////////////////////
int Compute(
               	long lNo
            )
{
	int iSum = 0, iDigit = 0;
	lNo = (lNo < 0) ? -lNo : lNo;

	while(lNo != 0)
	{
		iDigit = lNo % 10;
		if(iDigit % 3 == 0)
		{
			iSum = iSum + iDigit;
		}
		lNo = lNo / 10;
	}
	return iSum;
}