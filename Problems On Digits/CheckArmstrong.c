/* Program to check given number is Armstrong or not 
 * Armstrong Number is such a number whose summation of
 * cube of each digit is original number
 */

#include<stdio.h>
#define TRUE	1
#define FALSE	0
typedef int BOOL;


BOOL ChkArmstrong(int);

int main()
{
	int iNo = 0;
	BOOL bRet = FALSE;
	printf("Enter the number\n");
	scanf("%d", &iNo);
	bRet = ChkArmstrong(iNo);
	
	if(bRet == TRUE)
		printf("%d is Armstrong Number\n", iNo);
	else
		printf("%d is Not a Armstrong Number\n", iNo);

	return 0;
}

//////////////////////////////////////////////////////////
//
//	Name		:ChkArmstrong
//	Input		:int
//	Returns		:BOOL
//	Description	:Checks given number us Armstrong or not
//
//////////////////////////////////////////////////////////
BOOL ChkArmstrong(
                	int iNo		//Given Num
                 )
{
	int i = 0, iTemp = iNo, iSum = 0, iDigit = 0;
	
	//	updater
	if(iNo < 0)
		iNo = -iNo;

	while(iTemp > 0)
	{
		iDigit = iTemp % 10;
		iSum = iSum + (iDigit * iDigit * iDigit);
		iTemp = iTemp / 10;
	}
	if(iNo == iSum)
	{
		return TRUE;
	}
	else
	{
		return FALSE;
	}
}
