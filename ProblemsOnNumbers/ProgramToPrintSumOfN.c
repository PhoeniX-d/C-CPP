/* Program to print first 5 numbers */

#include<stdio.h>
#include<stdlib.h>

int DisplaySum(int[], int);
	
int main()
{
	int iNo = 0, iRet = 0;
	int *iArr = NULL;

	printf("Enter the N number\n");
	scanf("%d", &iNo);

	if(iNo < 0)
	{
		iNo = -iNo;
	}
	iArr = (int *)malloc(sizeof(int) * iNo);

	if(iArr == NULL)
	{
		printf("Cannot allocate memory\n");
		return 1;
	}

	iRet = DisplaySum(iArr, iNo);
	printf("Summation is %d\n", iRet);

	free(iArr);
	return 0;
}

////////////////////////////////////////////////////////////////
//	
//	Name		:DisplaySum
//	Input		:int[], int
//	Returns		:void
//	Description	:Prints summation of N Numbers
//
////////////////////////////////////////////////////////////////
int DisplaySum(
               		int iArr[],
               		int iNo
               )
{
	int i = 0, iSum = 0;

	for(i = 0; i < iNo; i++)
	{
		iSum = iSum + iArr[i];
	}

	return iSum;
}