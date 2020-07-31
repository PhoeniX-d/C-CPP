/* Program to print Even numbers upto N numbers */

#include<stdio.h>

void DisplayEvenN(int);
	
int main()
{
	int iNo = 0;
	printf("Enter the N numbers\n");
	scanf("%d", &iNo);
	DisplayEvenN(iNo);
	return 0;
}

////////////////////////////////////////////////////////////////
//	
//	Name		:DisplayEvenN
//	Input		:int
//	Returns		:void
//	Description	:Prints even numbers upto N
//
////////////////////////////////////////////////////////////////
void DisplayEvenN(
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
		if(i % 2 == 0)
		{
			printf("%d ", i);
		}
	}
}