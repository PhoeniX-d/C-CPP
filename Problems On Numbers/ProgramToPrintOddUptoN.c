/* Program to print Odd numbers upto N numbers */

#include<stdio.h>

void DisplayOddN(int);
	
int main()
{
	int iNo = 0;
	printf("Enter the N numbers\n");
	scanf("%d", &iNo);
	DisplayOddN(iNo);
	return 0;
}

////////////////////////////////////////////////////////////////
//	
//	Name		:DisplayOddN
//	Input		:int
//	Returns		:void
//	Description	:Prints Odd numbers upto N
//
////////////////////////////////////////////////////////////////
void DisplayOddN(
                  	int iMax
                  )
{
	int i = 0;
	if(iMax < 0)
	{
		iMax = -iMax;
	}

	for(i = 1; i <= iMax; i++)
	{
		if(i % 2 != 0)
		{
			printf("%d ", i);
		}
	}
}