/* Program to print max of N numbers */

#include<stdio.h>
#include<stdlib.h>

int DisplayMax(int[], int);
	
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

	iRet = DisplayMax(iArr, iNo);
	printf("Maximum is %d\n", iRet);

	free(iArr);
	return 0;
}

////////////////////////////////////////////////////////////////
//	
//	Name		:DisplayMax
//	Input		:int[], int
//	Returns		:void
//	Description	:Prints Maximum of N Numbers
//
////////////////////////////////////////////////////////////////
int DisplayMax(
               		int iArr[],
               		int iNo
               )
{
	int i = 0, iMax = iArr[0];

	for(i = 1; i < iNo; i++)
	{
		if(iMax < iArr[i])
		{
			iMax = iArr[i];
		}
	}
	return iMax;
}