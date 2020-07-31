/* Program to print number line upto N */

#include<stdio.h>

void DisplayNumLine(int);
	
int main()
{
	int iNo = 0;
	printf("Enter the N number\n");
	scanf("%d", &iNo);
	DisplayNumLine(iNo);
	return 0;
}

////////////////////////////////////////////////////////////////
//	
//	Name		:DisplayNumLine
//	Input		:int
//	Returns		:void
//	Description	:Prints a Number line upto given N
//
////////////////////////////////////////////////////////////////
void DisplayNumLine(
                  	int iMax
                  	)
{
	int i = 0;
	if(iMax < 0)
	{
		iMax = -iMax;
	}

	for(i = -iMax; i <= iMax; i++)
	{
		printf("%d ", i);
	}
}