/* Program to print 2nd max of N numbers */

#include<stdio.h>
#include<stdlib.h>

int Display2ndMax(int[], int);
	
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

	iRet = Display2ndMax(iArr, iNo);
	printf("Second Maximum is %d\n", iRet);

	free(iArr);
	return 0;
}
////////////////////////////////////////////////////////////////
//
//	Name		:Display2ndMax
//	Input		:int[], int
//	Returns		:int
//	Description	:displays Second Max of elements
//	Author		:Pranav Choudhary
//	Date		:21 August 2020
//
////////////////////////////////////////////////////////////////
int Display2ndMax(
               		int iArr[],
               		int iNo
               )
{
	int i = 0, iMax1 = iArr[0],iMax2 = 0;

	for(i = 1; i < iNo; i++)
	{
		if(iMax1 < iArr[i])
		{
			iMax2 = iMax1;
			iMax1 = iArr[i];
		}
		else if(iMax2 < iArr[i])
		{
			iMax2 = iArr[i];
		}
	}
	return iMax2;
}