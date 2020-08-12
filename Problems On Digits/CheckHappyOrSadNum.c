/*
*	Program to check that number is happy number or sad number 
*	Happy number : a happy number is a number which 
*	eventually reaches 1 when replaced by the sum of 
*	the square of each digit.	
*/

#include<stdio.h>
#define TRUE	 	1
#define FALSE		0
#define ERR			-1
typedef int BOOL;

BOOL ChkHappy(int);

int main()
{
	int iNo = 0;
	BOOL bRet = FALSE;

	printf("Enter the number\n");
	scanf("%d", &iNo);
	bRet = ChkHappy(iNo);
	if(bRet == TRUE)
		printf("%d is Happy number\n", iNo);
	else if(bRet == FALSE)
		printf("%d is Sad(unhappy) number\n", iNo);
	else if(bRet == ERR)
		printf("please enter valid number\n");
	return 0;
}

/////////////////////////////////////////////////////////////
//
//	Name		:ChkHappy
//	Input		:int
//	Returns		:BOOL
//	Description	:Checks whether number is happy number or sad
//	Author		:Pranav Choudhary
//	Date		:2 August 2020
//
/////////////////////////////////////////////////////////////
BOOL ChkHappy(
              		int iNum
              )
{
	int iDig = 0, iSum = 0;
	// updater
	if(iNum < 0)
		iNum = -iNum;
	// filter
	if(iNum == 0)
		return ERR;
	while(iSum != 1 && iSum != 4)
	{
		iSum = 0;
		while(iNum > 0)
		{
			iDig = iNum % 10;
			iSum = iSum + iDig * iDig;
			iNum = iNum / 10;
		}
		iNum = iSum;
	}
	if(iSum == 1)
		return TRUE;
	else
	   	return FALSE;
}