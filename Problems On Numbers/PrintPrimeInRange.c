/* Program to check given number is Prime or not 
 * Prime Number is such a number who is divisible by 1 and itself
 */

#include<stdio.h>

void DisplayPrime(int, int);

int main()
{
	int iStart = 0, iEnd = 0;
	printf("Enter the start \n");
	scanf("%d", &iStart);
	printf("Enter the end \n");
	scanf("%d", &iEnd);
	DisplayPrime(iStart, iEnd);
	return 0;
}

//////////////////////////////////////////////////////////
//
//	Name		:DisplayPrime
//	Input		:int, int
//	Returns		:void
//	Description	:prints Prime number in given range
//
//////////////////////////////////////////////////////////
void DisplayPrime(
                		int iStart,		//start
                		int iEnd 		//end
                	)
{
	printf("Inside function\n");
	int i = 0, iSum = 0, iPrime = 0;
	
	// updater
	iStart = (iStart < 0) ? -iStart : iStart;
	iEnd = (iEnd < 0) ? -iEnd : iEnd;
	// filter
	if(iEnd <= iStart || iEnd == 0)
	{
		printf("Inside filter\n");
		return;
	}
	printf("Prime Numbers in range are\n");
	for(i = iStart; i <= iEnd; i++)
	{
		for(iPrime = i/2; iPrime > 1 ; iPrime++)
		{
			//printf("%d \n", iPrime);
			if(i % iPrime == 0)
			{
				break;				
			}
		}
		
		if(iPrime == 1)
		{
			printf("%d ", iPrime);
		}
	}
	
}
