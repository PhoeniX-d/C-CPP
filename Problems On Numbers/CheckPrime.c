/* Program to check given number is Prime or not 
 * Prime Number is such a number who is divisible by 1 and itself
 */

#include<stdio.h>
#define TRUE	1
#define FALSE	0
typedef int BOOL;


BOOL ChkPrime(int);

int main()
{
	int iNo = 0;
	BOOL bRet = FALSE;
	printf("Enter the number\n");
	scanf("%d", &iNo);
	bRet = ChkPrime(iNo);
	
	if(bRet == TRUE)
		printf("%d is Prime Number\n", iNo);
	else
		printf("%d is Not a Prime Number\n", iNo);

	return 0;
}

//////////////////////////////////////////////////////////
//
//	Name		:ChkPrime
//	Input		:int
//	Returns		:BOOL
//	Description	:Checks given number us Prime or not
//
//////////////////////////////////////////////////////////
BOOL ChkPrime(
                	int iNo		//Given Num
                )
{
	int i = 0;
	
	//	updater
	if(iNo < 0)
		iNo = -iNo;

	for(i = iNo / 2; i > 1; i--)
	{
		if(iNo % i == 0)
		{
			break;
		}
	}
	if(i == 1)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
