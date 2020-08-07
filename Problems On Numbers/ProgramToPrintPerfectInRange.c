/* Program to check given number is perfect or not 
 * Perfect Number is such a number whose summation of factor is original number 
 */

#include<stdio.h>

void DisplayPerfect(int, int);

int main()
{
	int iStart = 0, iEnd = 0;
	printf("Enter the start \n");
	scanf("%d", &iStart);
	printf("Enter the end \n");
	scanf("%d", &iEnd);
	DisplayPerfect(iStart, iEnd);
	return 0;
}

//////////////////////////////////////////////////////////
//
//	Name		:DisplayPerfect
//	Input		:int, int
//	Returns		:void
//	Description	:prints perfect number in given range
//
//////////////////////////////////////////////////////////
void DisplayPerfect(
                		int iStart,		//start
                		int iEnd 		//end
                	)
{
	int i = 0, iSum = 0, iFactor = 0;
	
	// updater
	iStart = (iStart < 0) ? -iStart : iStart;
	iEnd = (iEnd < 0) ? -iEnd : iEnd;
	// filter
	if(iEnd <= iStart || iEnd == iStart == 0)
		return;
	printf("Perfect Numbers in range are\n");
	for(i = iStart; i <= iEnd; i++)
	{
		iSum = 0;
		for(iFactor = 1; iFactor <= i/2 && iSum < i; iFactor++)
		{
			if(i % iFactor == 0)
			{
				iSum = iSum + iFactor;
			}
		}
		if(iSum == i)
		{	
			printf("%d ",i);;
		}
	}
	
}
