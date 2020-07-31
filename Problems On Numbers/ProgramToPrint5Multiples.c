/* Program to print first 5 numbers */

#include<stdio.h>

void Display5Mults(int);
	
int main()
{
	int iNo = 0;
	printf("Enter the N number\n");
	scanf("%d", &iNo);
	Display5Mults(iNo);
	return 0;
}

////////////////////////////////////////////////////////////////
//	
//	Name		:Display5Mults
//	Input		:int
//	Returns		:void
//	Description	:Prints first 5 multiples of N
//
////////////////////////////////////////////////////////////////
void Display5Mults(
                  	int iNo
                  	)
{
	int i = 0;
	if(iNo < 0)
	{
		iNo = -iNo;
	}

	for(i = 1; i <= 5; i++)
	{
		printf("%d ", i * iNo);
	}
}