/* Program to print N Even numbers */

#include<stdio.h>

void DisplayNEven(int);
	
int main()
{
	int iNo = 0;
	printf("Enter the N numbers\n");
	scanf("%d", &iNo);
	DisplayNEven(iNo);
	return 0;
}

////////////////////////////////////////////////////////////////
//	
//	Name		:DisplayNEven
//	Input		:int
//	Returns		:void
//	Description	:Prints N even numbers
//	Author		:Pranav Choudhary
//	Date		:2 August 2020
//
////////////////////////////////////////////////////////////////
void DisplayNEven(
                  	int iMax
                  )
{
	int i = 0, iNum = 1;
	if (iMax == 0) return;
	if(iMax < 0)
	{
		iMax = -iMax;
	}

	for(i = 1; i <= iMax; iNum++)
	{
		if(iNum % 2 == 0)
		{
			printf("%d ", iNum);
			i++;
		}
	}
}