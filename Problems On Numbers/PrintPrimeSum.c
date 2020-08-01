/* program to find numbers whose sum is prime number */

#include<stdio.h>
#include<stdlib.h>
#include<assert.h>
void PrintPrimeSum(const int[], int);

int main()
{
	int iNo = 0;
	const int *iArr = NULL;
	printf("Enter total numbers\n");
	scanf("%d", &iNo);

	iNo = (iNo < 0) ? -iNo : iNo;

	iArr = (int *)malloc(sizeof(int) * iNo);
	assert(iArr != NULL);
	printf("Enter the %d numbers \n",iNo);
	for(int i = 0; i < iNo; i++)
	{
		scanf("%d", &iArr[i]);
	}
	PrintPrimeSum(iArr, iNo);
	return 0;
}

///////////////////////////////////////////////////////////////
//
//  Name        :PrintPrimeSum
//  Input       :int[], int
//  Returns     :void
//  Desription  :find numbers whose sum is prime number
//  Author      :Pranav P. Choudhary
//  Date        :1 August 2020
//
///////////////////////////////////////////////////////////////
void PrintPrimeSum(
                   	const int iArr[],
                   	int iNo
                   )
{
	int i = 0, k = 0, iTemp = 0, iSum = 0;
	for(i = 0; i < iNo; i++)
	{
		iTemp = iArr[i];
		while(iTemp != 0)
		{
			iSum = iSum + (iTemp % 10);
			iTemp = iTemp / 10;
		}
		for(k = iSum / 2; k > 1; k--)
		{
			if(iSum % k == 0)
			{
				break;
			}
		}
		if(k == 1)
		{
			printf("%d ", iArr[i]);
		}
		iSum = 0;
	}
}