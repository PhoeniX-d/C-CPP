/* Program to print Min of N numbers */

#include<stdio.h>
#include<stdlib.h>

int DisplayMin(int[], int);
	
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

	printf("Enter numbers\n");
	for(int i = 0; i < iNo; i++)
	{
		scanf("%d", &iArr[i]);
	}

	iRet = DisplayMin(iArr, iNo);
	printf("Minimum is %d\n", iRet);

	free(iArr);
	return 0;
}

////////////////////////////////////////////////////////////////
//	
//	Name		:DisplayMin
//	Input		:int[], int
//	Returns		:void
//	Description	:Prints Minimum of N Numbers
//
////////////////////////////////////////////////////////////////
int DisplayMin(
               		int iArr[],
               		int iNo
               )
{
	int i = 0, iMin = iArr[0];

	for(i = 1; i < iNo; i++)
	{
		if(iMin > iArr[i])
		{
			iMin = iArr[i];
		}
	}
	return iMin;
}