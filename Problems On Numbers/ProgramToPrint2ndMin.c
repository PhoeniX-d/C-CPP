/* Program to print 2nd Min of N numbers */

#include<stdio.h>
#include<stdlib.h>

int Display2ndMin(int[], int);
	
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

	iRet = Display2ndMin(iArr, iNo);
	printf("Second Minimum is %d\n", iRet);

	free(iArr);
	return 0;
}

////////////////////////////////////////////////////////////////
//	
//	Name		:Display2ndMin
//	Input		:int[], int
//	Returns		:void
//	Description	:Prints 2nd last Minimum of N Numbers
//
////////////////////////////////////////////////////////////////
int Display2ndMin(
               		int iArr[],
               		int iNo
               )
{
	int i = 0, iMin1 = iArr[0],iMin2 = 0;

	for(i = 0; i < iNo; i++)
	{
		if(iMin1 > iArr[i])
		{
			iMin2 = iMin1;
			iMin1 = iArr[i];
		}
		else if(iMin2 > iArr[i] || iMin2 < iMin1)
		{
			if(iArr[i] != iMin1)
				iMin2 = iArr[i];
		}
	}
	return iMin2;
}