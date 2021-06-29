/* Program to check given number is perfect or not 
 * Perfect Number is such a number whose summation of factor is original number 
 */

#include<stdio.h>
#define TRUE	1
#define FALSE	0
typedef int BOOL;


BOOL ChkPerfect(int);

int main()
{
	int iNo = 0;
	BOOL bRet = FALSE;
	printf("Enter the number\n");
	scanf("%d", &iNo);
	bRet = ChkPerfect(iNo);
	
	if(bRet == TRUE)
		printf("%d is Perfect Number\n", iNo);
	else
		printf("%d is Not a Perfect Number\n", iNo);

	return 0;
}

//////////////////////////////////////////////////////////
//
//	Name		:ChkPerfect
//	Input		:int
//	Returns		:BOOL
//	Description	:Checks given number us perfect or not
//
//////////////////////////////////////////////////////////
BOOL ChkPerfect(
                	int iNo		//Given Num
                )
{
	int iSum = 0, i = 0;
	
	//	updater
	if(iNo < 0)
		iNo = -iNo;
	// adjustment
	if(iNo == 1)
		return TRUE;
	if(iNo == 0)
		return FALSE;
	for(i = 1; i <= iNo/2 && iSum <= iNo; i++)
	{
		if(iNo % i == 0)
		{
			iSum = iSum + i;
		}
	}
	if(iSum == iNo)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
